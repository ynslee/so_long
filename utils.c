/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 09:30:02 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/01 17:26:06 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map(t_sl *sl)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	sl->map_check = (char **)ft_calloc(sl->h, sizeof(char *));
	while (++i < sl->h)
		sl->map_check[i] = ft_strdup(sl->map[i]);
	player_location(sl, i, j);
}

void	player_location(t_sl *sl, int i, int j)
{
	i = -1;
	while (++i < sl->y)
	{
		j = -1;
		while (++j < sl->x)
		{
			if (sl->map_check[i][j] == 'P')
			{
				sl ->p_x = i;
				sl ->p_y = j;
			}
		}
	}
}

void	init_solong(t_sl *sl)
{
	sl->h = 0;
	sl->w = 0;
	sl->c_count = 0;
	sl->e_count = 0;
	sl->p_count = 0;
	sl->mv_count = 0;
	sl->wall = 0;
	sl->img_len = 64;
}

int	close_game(t_sl *sl)
{
	mlx_destroy_window(sl->mlx, sl->window);
	free_end(sl);
	exit (0);
	return (0);
}

void	free_all(t_sl *sl)
{
	if (sl->map_line)
	{
		free(sl->map_line);
		sl->map_line = NULL;
	}
	if (sl->map)
	{
		free_char_array(sl, sl->map);
		sl->map = NULL;
	}
	if (sl->map_check)
	{
		free_char_array(sl, sl->map_check);
		sl->map_check = NULL;
	}
}
