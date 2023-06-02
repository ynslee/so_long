/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:58:29 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/01 18:32:09 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>
# include "libft/libft.h"

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

/* w is width, h is height. p_x :player x poistion, p_y: player y position.*/
typedef struct s_sl
{
	void	*mlx;
	void	*window;
	void	*p_right;
	void	*p_left;
	void	*p_collect;
	void	*p_down;
	void	*p_up;
	void	*collect;
	void	*wall;
	void	*path;
	void	*exit;
	int		img_len;
	char	**map;
	char	**map_check;
	char	*map_line;
	int		map_validity;
	int		w;
	int		h;
	int		x;
	int		y;
	int		p_count;
	int		c_count;
	int		e_count;
	int		mv_count;
	int		collected_c;
	int		exited_c;
	int		p_x;
	int		p_y;
}		t_sl;

/*reading the map and check if the map is validate*/
void	read_map(char **argv, t_sl *sl);
void	map_validation(t_sl *sl, char *map_line, int i);
void	validate_map_rectangular(t_sl *sl);
void	validate_map_char(t_sl *sl);
void	validate_map_walls(t_sl *sl);
void	validate_map_path(t_sl *sl, int i, int j);

/*make map and handle it properly*/
void	init_image(t_sl *sl);
void	make_map(t_sl *sl);
void	put_image(t_sl *sl, char map, int i, int j);
void	steps_on_window(t_sl *sl);

/*error handling*/
void	print_error(int num, t_sl *sl);
void	print_error2(int num, t_sl *sl);
void	free_all(t_sl *sl);
void	free_end(t_sl *sl);
void	free_char_array(t_sl *sl, char **str);
int		close_game(t_sl *sl);
void	free_two(t_sl *sl);

/*utilities to help*/
void	player_location(t_sl *sl, int i, int j);
void	copy_map(t_sl *sl);
void	init_solong(t_sl *sl);

/*movement with keyboard handling*/
int		key_function(int key, t_sl *sl);
void	up(t_sl *sl);
void	left(t_sl *sl);
void	right(t_sl *sl);
void	down(t_sl *sl);

/*functions to delete later*/
void	print_maps(t_sl *sl, char **str);
void	print_player_loc(t_sl *sl);

#endif
