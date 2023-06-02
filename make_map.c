/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:31:40 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/01 19:03:12 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_sl *sl, char content, int i, int j)
{
	mlx_put_image_to_window(sl->mlx, sl->window, sl->path, i, j);
	if (content == 'P')
		mlx_put_image_to_window(sl->mlx, sl->window, sl->p_collect, i, j);
	else if (content == '1')
		mlx_put_image_to_window(sl->mlx, sl->window, sl->wall, i, j);
	else if (content == 'C')
		mlx_put_image_to_window(sl->mlx, sl->window, sl->collect, i, j);
	else if (content == 'E')
		mlx_put_image_to_window(sl->mlx, sl->window, sl->exit, i, j);
}

void	make_map(t_sl *sl)
{
	int		i;
	int		j;

	i = 0;
	mlx_clear_window(sl->mlx, sl->window);
	while (i < sl->h)
	{
		j = 0;
		while (j < sl->w)
		{
			put_image(sl, sl->map[i][j], j * sl->img_len, i * sl->img_len);
			j++;
		}
		i++;
	}
	steps_on_window(sl);
}

void	init_image(t_sl *sl)
{
	sl->path = mlx_xpm_file_to_image(sl->mlx, "./assets/path.xpm", \
				&sl->img_len, &sl->img_len);
	sl->wall = mlx_xpm_file_to_image(sl->mlx, "./assets/wall.xpm", \
				&sl->img_len, &sl->img_len);
	sl->p_collect = mlx_xpm_file_to_image(sl->mlx, "./assets/player_c.xpm", \
				&sl->img_len, &sl->img_len);
	sl->p_right = mlx_xpm_file_to_image(sl->mlx, "./assets/player.xpm", \
				&sl->img_len, &sl->img_len);
	sl->p_left = mlx_xpm_file_to_image(sl->mlx, "./assets/player_left.xpm", \
				&sl->img_len, &sl->img_len);
	sl->p_up = mlx_xpm_file_to_image(sl->mlx, "./assets/player_up.xpm", \
				&sl->img_len, &sl->img_len);
	sl->p_down = mlx_xpm_file_to_image(sl->mlx, "./assets/player_down.xpm", \
				&sl->img_len, &sl->img_len);
	sl->collect = mlx_xpm_file_to_image(sl->mlx, \
				"./assets/collectible.xpm", &sl->img_len, &sl->img_len);
	sl->exit = mlx_xpm_file_to_image(sl->mlx, "./assets/exit.xpm", \
				&sl->img_len, &sl->img_len);
}

void	steps_on_window(t_sl *sl)
{
	char	*str;

	mlx_put_image_to_window(sl->mlx, sl->window, sl->wall, 0 * 64, 0 * 64);
	mlx_string_put(sl->mlx, sl->window, 0, 0, 0x0000FF00, "total steps:");
	str = ft_itoa(sl->mv_count);
	mlx_put_image_to_window(sl->mlx, sl->window, sl->wall, 2 * 64, 0 * 64);
	mlx_string_put(sl->mlx, sl->window, 140, 0, 0x0000FF00, str);
	free(str);
}
