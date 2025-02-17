/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:14:59 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 21:19:01 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	init_camera(t_c3dmlx *c3d, double dv_y, double pl_x, double pl_y)
{
	if (c3d->game->player_found)
		tutup_c3d(c3d, "Error: Multiple player detected\n", 1);
	c3d->game->player->vec_direction.y = dv_y;
	c3d->game->player->camera_pl_vec.x = pl_x;
	c3d->game->player->camera_pl_vec.y = pl_y;
	c3d->game->player_found++;
}
