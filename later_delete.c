/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   later_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:35:40 by yoonslee          #+#    #+#             */
/*   Updated: 2023/06/01 13:35:52 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_maps(t_sl *sl, char **str)
{
	int	i;

	i = -1;

	while (++i < sl->h)
		ft_printf("%s\n", str[i]);
}

void	print_player_loc(t_sl *sl)
{
	ft_printf("player[x][y] is [%d][%d]\n", sl ->p_x, sl ->p_y);
	ft_printf("player[x][y] is %c\n", sl->map_check[sl ->p_x][sl ->p_y]);
}
