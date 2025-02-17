/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:52:01 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/18 02:16:35 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

static void	init_raycast(t_raycast *ray, t_player *player)
{
	ray->camera_x = (2 * ray->scrpx_x) / (double) WIN_W - 1;
	ray->raydirc_x = player->vec_direction.x + player->camera_pl_vec.x
		* ray->camera_x;
	ray->raydirc_y = player->vec_direction.y + player->camera_pl_vec.y
		* ray->camera_x;
	ray->map_x = (int) player->position.x;
	ray->map_y = (int) player->position.y;
	ray->deltadist_x = fabs(1 / ray->raydirc_x);
	ray->deltadist_y = fabs(1 / ray->raydirc_y);
	ray->wall_hit = 0;
}

static void	decide_raystep(t_raycast *ray, t_player *player)
{
	if (ray->raydirc_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->position.x - ray->map_x)
			* ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->position.x)
			* ray->deltadist_x;
	}
	if (ray->raydirc_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->position.y - ray->map_y)
			* ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->position.y)
			* ray->deltadist_y;
	}
}

void	ft_raycasting(t_c3dmlx *c3d, t_raycast *ray)
{
	t_player	*player;

	player = c3d->game->player;
	init_raycast(ray, player);
	decide_raystep(ray, player);
	ft_dda(c3d, ray);
	calc_wall_height(ray, player);
	draw_textures(c3d, ray, player);
	ray->scrpx_x++;
}
