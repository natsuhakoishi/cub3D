/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:56:56 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/20 03:45:30 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	parse_symbols(t_c3dmlx *c3d, char *mapline)
{
	int	x;

	x = -1;
	while (mapline[++x])
	{
		if (mapline[x] != '0' && mapline[x] != '1' && mapline[x] != 'N'
			&& mapline[x] != 'S' && mapline[x] != 'W' && mapline[x] != 'E'
			&& mapline[x] != ' ')
			tutup_c3d(c3d, "Error: Invalid symbols in map\n", 1);
	}
}

void	parse_player(t_c3dmlx *c3d, char **map, int y, int x)
{
	if (map[y][x] == 'N')
	{
		c3d->game->player->vec_direction.x = 0.00;
		init_camera(c3d, -1.00, 0.66, 0.00);
	}
	else if (map[y][x] == 'S')
	{
		c3d->game->player->vec_direction.x = 0.00;
		init_camera(c3d, 1.00, -0.66, 0.00);
	}
	else if (map[y][x] == 'W')
	{
		c3d->game->player->vec_direction.x = -1;
		init_camera(c3d, 0.00, 0.00, -0.66);
	}
	else if (map[y][x] == 'E')
	{
		c3d->game->player->vec_direction.x = 1.00;
		init_camera(c3d, 0.00, 0.00, 0.66);
	}
	else
		return ;
	c3d->game->player->position.x = (double) x + 0.5;
	c3d->game->player->position.y = (double) y + 0.5;
}

static int	parse_space(char **map, int y, int x)
{
	if (map[y][x] != ' ')
		return (0);
	if (x < (int)ft_strlen(map[y - 1]) && map[y - 1][x] == '0')
		tutup("Error: Map not closed <parse_space (up)>\n", 1);
	if (x < (int)ft_strlen(map[y + 1]) && map[y - 1][x] == '0')
		tutup("Error: Map not closed <parse_space (down)>\n", 1);
	if (map[y][x - 1] == '0')
		tutup("Error: Map not closed <parse_space (right)>\n", 1);
	if (map[y][x + 1] == '0')
		tutup("Error: Map not closed <parse_space (left)>\n", 1);
	return (1);
}

void	parse_borders(char **map, int y, int x)
{
	if (parse_space(map, y, x))
		return ;
	if (ft_strlen(map[y]) > ft_strlen(map[y - 1])
		&& x >= (int)ft_strlen(map[y - 1]))
	{
		if (map[y][x] != '1')
			tutup("Error: Map not closed <parse_border if(1)>\n", 1);
	}
	if (x < (int)ft_strlen(map[y - 1]) && map[y - 1][x] == ' ')
	{
		if (map[y][x] != '1')
			tutup("Error: Map not closed <parse_border if(2)>\n", 1);
	}
	if (ft_strlen(map[y]) > ft_strlen(map[y + 1])
		&& x >= (int)ft_strlen(map[y + 1]))
	{
		if (map[y][x] != '1')
			tutup("Error: Map not closed <parse_border if(3)>\n", 1);
	}
	if (x < (int)ft_strlen(map[y + 1]) && map[y + 1][x] == ' ')
	{
		if (map[y][x] != '1')
			tutup("Error: Map not closed <parse_border if(4)>\n", 1);
	}
}

void	parse_map2(t_c3dmlx *c3d, char **map, int y, int x)
{
	parse_symbols(c3d, map[y]);
	parse_player(c3d, map, y, x);
	parse_borders(map, y, x);
}
