/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:44:41 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/19 22:00:16 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	init_player(t_c3dmlx *c3d)
{
	c3d->game->player = malloc(sizeof(t_player));
	if (!c3d->game->player)
		tutup_c3d(c3d, "Error: Failure: malloc() in root->game->player\n", 1);
	c3d->game->player->position.x = 5;
	c3d->game->player->position.y = 5;
	c3d->game->player->vec_direction.x = 0;
	c3d->game->player->vec_direction.y = 0;
	c3d->game->player->camera_pl_vec.x = 0;
	c3d->game->player->camera_pl_vec.y = 0;
	c3d->game->player->move_speed = 0.08;
	c3d->game->player->sens = 0.07;
}
