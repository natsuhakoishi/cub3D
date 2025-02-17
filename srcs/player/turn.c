/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:19:18 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 21:28:09 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	turn_left(t_c3dmlx *c3d)
{
	double	ori_dir_x;
	double	ori_pl_x;
	double	sens;

	ori_dir_x = c3d->game->player->vec_direction.x;
	ori_pl_x = c3d->game->player->camera_pl_vec.x;
	sens = c3d->game->player->sens;
	c3d->game->player->vec_direction.x
		= c3d->game->player->vec_direction.x * cos(-sens)
		- c3d->game->player->vec_direction.y * sin(-sens);
	c3d->game->player->vec_direction.y = ori_dir_x * sin(-sens)
		+ c3d->game->player->vec_direction.y * cos(-sens);
	c3d->game->player->camera_pl_vec.x
		= c3d->game->player->camera_pl_vec.x * cos(-sens)
		- c3d->game->player->camera_pl_vec.y * sin(-sens);
	c3d->game->player->camera_pl_vec.y = ori_pl_x * sin(-sens)
		+ c3d->game->player->camera_pl_vec.y * cos(-sens);
}

void	turn_right(t_c3dmlx *c3d)
{
	double	ori_dir_x;
	double	ori_pl_x;
	double	sens;

	ori_dir_x = c3d->game->player->vec_direction.x;
	ori_pl_x = c3d->game->player->camera_pl_vec.x;
	sens = c3d->game->player->sens;
	c3d->game->player->vec_direction.x
		= c3d->game->player->vec_direction.x * cos(sens)
		- c3d->game->player->vec_direction.y * sin(sens);
	c3d->game->player->vec_direction.y = ori_dir_x * sin(sens)
		+ c3d->game->player->vec_direction.y * cos(sens);
	c3d->game->player->camera_pl_vec.x
		= c3d->game->player->camera_pl_vec.x * cos(sens)
		- c3d->game->player->camera_pl_vec.y * sin(sens);
	c3d->game->player->camera_pl_vec.y = ori_pl_x * sin(sens)
		+ c3d->game->player->camera_pl_vec.y * cos(sens);
}
