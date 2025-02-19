/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:28:08 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/19 22:46:02 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

static void	draw_texline(t_c3dmlx *c3d, t_raycast *ray, t_line *line,
							double wall_x)
{
	t_img	*img;
	int		tex_x;

	img = c3d->no_texture;
	if (ray->direction == EAST)
		img = c3d->ea_texture;
	else if (ray->direction == SOUTH)
		img = c3d->so_texture;
	else if (ray->direction == WEST)
		img = c3d->we_texture;
	else if (ray->direction == NORTH)
		img = c3d->no_texture;
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->direction == WEST || ray->direction == EAST)
		&& ray->raydirc_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((ray->direction == NORTH || ray->direction == SOUTH)
		&& ray->raydirc_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y_sd = ray->draw_start;
	line->y_ed = ray->draw_end;
	line->x_texd = tex_x;
	draw_teximg(c3d, ray, line, img);
}

void	draw_textures(t_c3dmlx *c3d, t_raycast *ray, t_player *player)
{
	t_line	*line;
	double	wall_x;

	line = malloc(sizeof(t_line));
	ft_memset(line, 0, sizeof(t_line));
	if (ray->direction == WEST || ray->direction == EAST)
		wall_x = player->position.y + ray->pwall_dist * ray->raydirc_y;
	else
		wall_x = player->position.x + ray->pwall_dist * ray->raydirc_x;
	wall_x -= floor(wall_x);
	line->x = ray->scrpx_x;
	if (c3d->game->map[ray->map_y][ray->map_x] == '1')
		draw_texline(c3d, ray, line, wall_x);
	line->y_sd = 0;
	line->y_ed = ray->draw_start;
	draw_fcline(c3d, line, c3d->ceiling_rgb);
	line->y_sd = WIN_H;
	line->y_ed = ray->draw_end;
	draw_fcline(c3d, line, c3d->floor_rgb);
	free(line);
}
