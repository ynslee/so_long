/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:29:15 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/02 15:22:48 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char **argv, t_sl *sl)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error(0, sl);
	line = get_next_line(fd);
	sl->w = (int)ft_strlen(line) - 1;
	sl->map_line = ft_strdup(line);
	free(line);
	while (++sl->h)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		sl->map_line = ft_strjoin_gnl(sl->map_line, line);
		free(line);
	}
	map_validation(sl, sl->map_line, i);
	free(sl->map_line);
	close(fd);
}

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (argc != 2)
		print_error(1, &sl);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		print_error(2, &sl);
	sl.mlx = mlx_init();
	init_solong(&sl);
	read_map(argv, &sl);
	sl.window = mlx_new_window(sl.mlx, sl.w * sl.img_len, sl.h * sl.img_len, \
				"so_long");
	init_image(&sl);
	make_map(&sl);
	mlx_hook(sl.window, 17, 1L << 5, &close_game, &sl);
	mlx_hook(sl.window, 2, 1L << 0, &key_function, &sl);
	mlx_loop(sl.mlx);
	return (0);
}
