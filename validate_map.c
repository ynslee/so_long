/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:26:55 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/01 16:58:31 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*check if file is empty file and exit && check characters && check walls
&&check valid path && maps into array*/
void	map_validation(t_sl *sl, char *map_line, int i)
{
	char	**split_result;

	if (map_line == NULL)
		print_error(3, sl);
	sl->map = (char **)malloc(sl->h * sizeof(char *));
	split_result = ft_split(map_line, '\n');
	while (split_result[i])
	{
		sl->map[i] = ft_strdup(split_result[i]);
		free(split_result[i]);
		split_result[i] = NULL;
		i++;
	}
	free(split_result);
	validate_map_rectangular(sl);
	validate_map_char(sl);
	validate_map_walls(sl);
	copy_map(sl);
	if (sl->h <= 2 || sl->w <= 2)
		print_error(6, sl);
	validate_map_path(sl, sl ->p_x, sl ->p_y);
	if (sl->map_validity != 1)
		print_error(6, sl);
}

/*check if map is rectangular*/
void	validate_map_rectangular(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->h)
	{
		if (sl->w != (int)ft_strlen(sl->map[i]))
			print_error(4, sl);
		i++;
	}
	sl->x = sl->w;
	sl->y = sl->h;
}

/*check if map has only C,E,P,1,0 and see if exit is one, player is one,
collectible is more than 1*/
void	validate_map_char(t_sl *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->h)
	{
		j = -1;
		while (++j < sl->w)
		{
			if (sl->map[i][j] != 'C' && sl->map[i][j] != 'E' && sl->map[i][j] \
			!= 'P' && sl->map[i][j] != '1' && sl->map[i][j] != '0')
				print_error(5, sl);
			if (sl->map[i][j] == 'C')
				sl->c_count++;
			if (sl->map[i][j] == 'E')
				sl->e_count++;
			if (sl->map[i][j] == 'P')
				sl->p_count++;
		}
	}
	if (sl->e_count != 1 || sl->p_count != 1 || sl->c_count < 1)
		print_error(5, sl);
}

/*Check if the map has wall surrounded as 1*/
void	validate_map_walls(t_sl *sl)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sl->h)
	{
		if (sl->map[i][0] != '1' || sl->map[i][sl->w - 1] != '1')
			print_error(5, sl);
		else if (i == 0 || i == sl->w - 1)
		{
			j = -1;
			while (++j < sl->w)
			{
				if (sl->map[i][j] != '1')
					print_error(5, sl);
			}
		}
	}
}

/*Check if the map has valid path. Take Exit as an wall and you can't go in
unless you have collected_c all the collectibles*/
void	validate_map_path(t_sl *sl, int i, int j)
{
	if (sl->exited_c == 1 && sl->c_count == sl->collected_c)
		sl->map_validity = 1;
	if (sl->map_check[i][j] == 'E')
		sl->exited_c = 1;
	if (sl->map_check[i][j] == 'C' || sl->map_check[i][j] == 'P' \
	|| sl->map_check[i][j] == '0')
	{
		if (sl->map_check[i][j] == 'C')
			sl->collected_c++;
		sl->map_check[i][j] = 'X';
		if (i < sl->h - 1)
			validate_map_path(sl, i + 1, j);
		if (j < sl->w - 1)
			validate_map_path(sl, i, j + 1);
		if (i > 0)
			validate_map_path(sl, i - 1, j);
		if (j > 0)
			validate_map_path(sl, i, j - 1);
	}
}
