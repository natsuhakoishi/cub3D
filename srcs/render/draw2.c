/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:51:31 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/19 23:09:23 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

static void	draw_fcrgb(int rgb, int x, int y, t_img *img)
{
	int	r;
	int	g;
	int	b;

	r = (rgb >> 16) & 0xFF;
	g = (rgb >> 8) & 0xFF;
	b = rgb & 0xFF;
	img->addr[y * img->size_line + x * img->bits_per_pixel / 8] = b;
	img->addr[y * img->size_line + x * img->bits_per_pixel / 8 + 1] = g;
	img->addr[y * img->size_line + x * img->bits_per_pixel / 8 + 2] = r;
}

void	draw_fcline(t_c3dmlx *c3d, t_line *line, int rgb)
{
	int	y;
	int	y_max;

	if (line->y_sd < line->y_ed)
	{
		y = line->y_sd;
		y_max = line->y_ed;
	}
	else
	{
		y = line->y_ed;
		y_max = line->y_sd;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			draw_fcrgb(rgb, line->x, y, c3d->mlx_img);
			y++;
		}
	}
}

static void	draw_texrgb(t_c3dmlx *c3d, t_raycast *ray, t_line *line,
								t_img *texture)
{
	int	scale;

	scale = line->y * texture->size_line
		- WIN_H * texture->size_line / 2 + ray->draw_height
		* texture->size_line / 2;
	line->y_texd = ((scale * texture->height) / ray->draw_height)
		/ texture->size_line;
	if (line->x_texd < 0 || line->x_texd >= texture->width ||
			line->y_texd < 0 || line->y_texd >= texture->height)
		return ;
	c3d->mlx_img->addr[line->y * c3d->mlx_img->size_line + line-> x
		* c3d->mlx_img->bits_per_pixel / 8] = texture->addr[line->y_texd
		* texture->size_line + line->x_texd
		* (texture->bits_per_pixel / 8)];
	c3d->mlx_img->addr[line->y * c3d->mlx_img->size_line + line-> x
		* (c3d->mlx_img->bits_per_pixel / 8) + 1] = texture->addr[line->y_texd
		* texture->size_line + line->x_texd
		* (texture->bits_per_pixel / 8) + 1];
	c3d->mlx_img->addr[line->y * c3d->mlx_img->size_line + line-> x
		* (c3d->mlx_img->bits_per_pixel / 8) + 2] = texture->addr[line->y_texd
		* texture->size_line + line->x_texd
		* (texture->bits_per_pixel / 8) + 2];
}

void	draw_teximg(t_c3dmlx *c3d, t_raycast *ray, t_line *line, t_img *img)
{
	int	y_max;

	if (line->y_sd < line->y_ed)
	{
		line->y = line->y_sd;
		y_max = line->y_ed;
	}
	else
	{
		line->y = line->y_ed;
		y_max = line->y_sd;
	}
	if (line->y >= 0)
	{
		line->y--;
		while (++line->y < y_max)
			draw_texrgb(c3d, ray, line, img);
	}
}
