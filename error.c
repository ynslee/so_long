/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:59:50 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/02 13:31:13 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Error\n and error message of my choice
0 - 2 : nothing is malloced
3 : map_line is malloced
4 - 5 : map_liine & map is malloced
6: map_linie & map & map_check is malloced*/
void	print_error(int num, t_sl *sl)
{
	if (num == 0)
		ft_putstr_fd("Error\nFile opening error!\n", 2);
	if (num == 1)
		ft_putstr_fd("Error\nwrong argument number!\n", 2);
	if (num == 2)
		ft_putstr_fd("Error\nMap is invalid version!\n", 2);
	if (num == 3)
	{
		free(sl->map_line);
		ft_putstr_fd("Error\nMap is empty!\n", 2);
	}
	if (num == 7)
	{
		free(sl->map_line);
		ft_putstr_fd("Error\nMap is bigger than own screen!\n", 2);
	}
	if (num == 4 || num == 5 || num == 6)
		print_error2(num, sl);
	exit(1);
}

void	print_error2(int num, t_sl *sl)
{
	if (num == 4)
	{
		free_two(sl);
		ft_putstr_fd("Error\nMap is not rectangular!\n", 2);
	}
	if (num == 5)
	{
		free_two(sl);
		ft_putstr_fd("Error\nMap content is incorrect!\n", 2);
	}
	if (num == 6)
	{
		ft_putstr_fd("Error\nMap does not have valid path!\n", 2);
		free_all(sl);
	}
}

void	free_two(t_sl *sl)
{
	free(sl->map_line);
	free_char_array(sl, sl->map);
}

void	free_char_array(t_sl *sl, char **str)
{
	int	i;

	i = 0;
	while (i < sl->h)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_end(t_sl *sl)
{
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
