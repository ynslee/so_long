/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:34:22 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/01 19:05:45 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_function(int key, t_sl *sl)
{
	if (key == KEY_A)
		left(sl);
	else if (key == KEY_W)
		up(sl);
	else if (key == KEY_D)
		right(sl);
	else if (key == KEY_S)
		down(sl);
	else if (key == KEY_ESC)
		close_game(sl);
	else
		return (0);
	steps_on_window(sl);
	return (1);
}

void	up(t_sl *sl)
{
	if (sl->map[sl->p_x - 1][sl->p_y] == '1')
		return ;
	else if (sl->map[sl->p_x - 1][sl->p_y] == 'E')
	{
		if (sl->c_count == 0)
			close_game(sl);
		else
			return ;
	}
	else if (sl->map[sl->p_x - 1][sl->p_y] == 'C')
		sl->c_count--;
	sl->mv_count++;
	sl->map[sl->p_x][sl->p_y] = '0';
	mlx_put_image_to_window(sl->mlx, sl->window, sl->path, \
	sl->p_y * 64, sl->p_x * 64);
	sl->map[sl->p_x - 1][sl->p_y] = 'P';
	sl->p_x--;
	mlx_put_image_to_window(sl->mlx, sl->window, sl->p_up, \
	(sl->p_y) * 64, sl->p_x * 64);
	ft_printf("Total steps: %d\n", sl->mv_count);
}

void	left(t_sl *sl)
{
	if (sl->map[sl->p_x][sl->p_y - 1] == '1')
		return ;
	else if (sl->map[sl->p_x][sl->p_y - 1] == 'E')
	{
		if (sl->c_count == 0)
			close_game(sl);
		else
			return ;
	}
	else if (sl->map[sl->p_x][sl->p_y - 1] == 'C')
		sl->c_count--;
	sl->mv_count++;
	sl->map[sl->p_x][sl->p_y] = '0';
	mlx_put_image_to_window(sl->mlx, sl->window, sl->path, \
	sl->p_y * 64, sl->p_x * 64);
	sl->map[sl->p_x][sl->p_y - 1] = 'P';
	sl->p_y--;
	mlx_put_image_to_window(sl->mlx, sl->window, sl->p_left, \
	sl->p_y * 64, sl->p_x * 64);
	ft_printf("Total steps: %d\n", sl->mv_count);
}

void	right(t_sl *sl)
{
	if (sl->map[sl->p_x][sl->p_y + 1] == '1')
		return ;
	else if (sl->map[sl->p_x][sl->p_y + 1] == 'E')
	{
		if (sl->c_count == 0)
			close_game(sl);
		else
			return ;
	}
	else if (sl->map[sl->p_x][sl->p_y + 1] == 'C')
		sl->c_count--;
	sl->mv_count++;
	sl->map[sl->p_x][sl->p_y] = '0';
	mlx_put_image_to_window(sl->mlx, sl->window, sl->path, \
	sl->p_y * 64, sl->p_x * 64);
	sl->map[sl->p_x][sl->p_y + 1] = 'P';
	sl->p_y++;
	mlx_put_image_to_window(sl->mlx, sl->window, sl->p_right, \
	sl->p_y * 64, sl->p_x * 64);
	ft_printf("Total steps: %d\n", sl->mv_count);
}

void	down(t_sl *sl)
{
	if (sl->map[sl->p_x + 1][sl->p_y] == '1')
		return ;
	else if (sl->map[sl->p_x + 1][sl->p_y] == 'E')
	{
		if (sl->c_count == 0)
			close_game(sl);
		else
			return ;
	}
	else if (sl->map[sl->p_x + 1][sl->p_y] == 'C')
		sl->c_count--;
	sl->mv_count++;
	sl->map[sl->p_x][sl->p_y] = '0';
	mlx_put_image_to_window(sl->mlx, sl->window, sl->path, \
	sl->p_y * 64, sl->p_x * 64);
	sl->map[sl->p_x + 1][sl->p_y] = 'P';
	sl->p_x++;
	mlx_put_image_to_window(sl->mlx, sl->window, sl->p_down, \
	(sl->p_y) * 64, sl->p_x * 64);
	ft_printf("Total steps: %d\n", sl->mv_count);
}
