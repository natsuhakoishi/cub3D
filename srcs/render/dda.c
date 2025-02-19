/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:08:15 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/19 22:45:14 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	calc_wall_height(t_raycast *ray, t_player *player)
{
	if (ray->direction == WEST || ray->direction == EAST)
		ray->pwall_dist = ((double) ray->map_x - player->position.x
				+ (1 - ray->step_x) / 2) / ray->raydirc_x;
	else
		ray->pwall_dist = ((double) ray->map_y - player->position.y
				+ (1 - ray->step_y) / 2) / ray->raydirc_y;
	ray->draw_height = WIN_H / ray->pwall_dist;
	ray->draw_start = -ray->draw_height / 2 + (WIN_H / 2);
	if (ray->draw_start <= 0)
		ray->draw_start = 0;
	ray->draw_end = ray->draw_height / 2 + (WIN_H / 2);
	if (ray->draw_end >= WIN_H)
		ray->draw_end = WIN_H - 1;
}

static void	add_axis(t_raycast *ray)
{
	if (ray->sidedist_x < ray->sidedist_y)
	{
		ray->sidedist_x += ray->deltadist_x;
		ray->map_x += ray->step_x;
		if (ray->step_x == -1)
			ray->direction = WEST;
		else
			ray->direction = EAST;
	}
	else
	{
		ray->sidedist_y += ray->deltadist_y;
		ray->map_y += ray->step_y;
		if (ray->step_y == -1)
			ray->direction = NORTH;
		else
			ray->direction = SOUTH;
	}
}

void	ft_dda(t_c3dmlx *c3d, t_raycast *ray)
{
	while (!ray->wall_hit)
	{
		add_axis(ray);
		if (c3d->game->map[ray->map_y][ray->map_x] == '1')
			ray->wall_hit = 1;
	}
}
