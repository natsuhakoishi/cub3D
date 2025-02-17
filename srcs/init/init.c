/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:48:41 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 23:18:00 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

static void	init_control(t_c3dmlx *c3d)
{
	c3d->control = malloc(sizeof(t_control));
	if (!c3d->control)
		tutup_c3d(c3d, "Error: Failure: malloc() in c3d->control\n", 1);
	c3d->control->look_left = 0;
	c3d->control->look_right = 0;
	c3d->control->move_left = 0;
	c3d->control->move_right = 0;
	c3d->control->move_front = 0;
	c3d->control->move_back = 0;
}

static void	init_game(t_c3dmlx *c3d, char *path)
{
	c3d->game = (t_game *)malloc(sizeof(t_game));
	if (!c3d->game)
		tutup_c3d(c3d, "Error: Failure: malloc() in c3d->game\n", 1);
	c3d->game->map = 0;
	c3d->game->player_found = 0;
	init_player(c3d);
	open_cub(c3d, path);
}

static void	init_renderer(t_c3dmlx *c3d)
{
	c3d->mlx = mlx_init();
	if (!c3d->mlx)
		tutup("Error: Failure: mlx_init()\n", 1);
	c3d->mlx_win = mlx_new_window(c3d->mlx, WIN_W, WIN_H, "cub3D");
	if (!c3d->mlx_win)
		tutup("Error: Failure: mlx_init()\n", 1);
	c3d->mlx_img->img_ptr = mlx_new_image(c3d->mlx, WIN_W, WIN_H);
	if (!c3d->mlx_img->img_ptr)
		tutup_c3d(c3d, "Error: Failure: mlx_new_image()\n", 1);
	c3d->mlx_img->width = WIN_W;
	c3d->mlx_img->height = WIN_H;
	c3d->mlx_img->addr = mlx_get_data_addr(c3d->mlx_img->img_ptr,
			&c3d->mlx_img->bits_per_pixel, &c3d->mlx_img->size_line,
			&c3d->mlx_img->endian);
}

static void	init_textures(t_c3dmlx *c3d)
{
	c3d->mlx_img = malloc(sizeof(t_img));
	c3d->ea_texture = malloc(sizeof(t_img));
	c3d->so_texture = malloc(sizeof(t_img));
	c3d->we_texture = malloc(sizeof(t_img));
	c3d->no_texture = malloc(sizeof(t_img));
	c3d->floor_rgb = 0;
	c3d->ceiling_rgb = 0;
	ft_memset(c3d->mlx_img, 0, sizeof(t_img));
	ft_memset(c3d->ea_texture, 0, sizeof(t_img));
	ft_memset(c3d->so_texture, 0, sizeof(t_img));
	ft_memset(c3d->we_texture, 0, sizeof(t_img));
	ft_memset(c3d->no_texture, 0, sizeof(t_img));
}

t_c3dmlx	*init_c3dmlx(char *path)
{
	t_c3dmlx	*c3d;

	c3d = malloc(sizeof(t_c3dmlx));
	init_textures(c3d);
	init_renderer(c3d);
	init_game(c3d, path);
	init_control(c3d);
	return (c3d);
}
