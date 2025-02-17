/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:51:40 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 22:20:35 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	parse_fl(t_c3dmlx *c3d, int y, int x)
{
	--x;
	while (c3d->game->map[y][++x])
	{
		if (c3d->game->map[y][x] != '1' && c3d->game->map[y][x] != ' ')
			tutup_c3d(c3d, "Error: Map border not closed (FL)\n", 1);
	}
	return (0);
}

static int	map_len(char **map)
{
	int	a;

	a = 0;
	while (map[a])
		++a;
	return (a);
}

void	parse_map(t_c3dmlx *c3d)
{
	int		y;
	int		x;
	int		len;
	char	**map;

	map = c3d->game->map;
	len = map_len(map);
	y = -1;
	while (++y < len)
	{
		x = -1;
		while (map[y][++x] && map[y][x] == ' ')
			;
		if ((y == 0 || y == len - 1) && !parse_fl(c3d, y, x))
			continue ;
		if (map[y][x--] != '1')
			tutup_c3d(c3d, "Error: Map border not closed (L)\n", 1);
		if (map[y][ft_strlen(map[y]) - 1] != '1')
			tutup_c3d(c3d, "Error: Map border not closed (R)\n", 1);
		while (map[y][++x])
			parse_map2(c3d, map, y, x);
	}
	if (!c3d->game->player_found)
		tutup_c3d(c3d, "Error: No player found\n", 1);
}
