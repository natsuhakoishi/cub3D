/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 21:29:50 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/18 02:17:01 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	move_forward(t_c3dmlx *c3d)
{
	t_player	*player;
	t_game		*game;

	game = c3d->game;
	player = c3d->game->player;
	if (game->map
		[(int)(player->position.y)]
		[(int)(player->position.x + player->vec_direction.x
		* ceil(player->move_speed))] != '1')
		player->position.x += (player->move_speed * player->vec_direction.x);
	if (game->map
		[(int)(player->position.y + player->vec_direction.y
			* ceil(player->move_speed))]
		[(int)(player->position.x)] != '1')
		player->position.y += (player->move_speed * player->vec_direction.y);
}

void	move_backward(t_c3dmlx *c3d)
{
	t_player	*player;
	t_game		*game;

	game = c3d->game;
	player = c3d->game->player;
	if (game->map
		[(int)(player->position.y)]
		[(int)(player->position.x - player->vec_direction.x
		* ceil(player->move_speed))] != '1')
		player->position.x -= (player->move_speed * player->vec_direction.x);
	if (game->map
		[(int)(player->position.y - player->vec_direction.y
			* ceil(player->move_speed))]
		[(int)(player->position.x)] != '1')
		player->position.y -= (player->move_speed * player->vec_direction.y);
}

void	move_left(t_c3dmlx *c3d)
{
	t_player	*player;
	t_game		*game;

	game = c3d->game;
	player = c3d->game->player;
	if (game->map
		[(int)(player->position.y)]
		[(int)(player->position.x - player->camera_pl_vec.x
		* ceil(player->move_speed))] != '1')
		player->position.x -= (player->move_speed * player->camera_pl_vec.x);
	if (game->map
		[(int)(player->position.y - player->camera_pl_vec.y
			* ceil(player->move_speed))]
		[(int)(player->position.x)] != '1')
		player->position.y -= (player->move_speed * player->camera_pl_vec.y);
}

void	move_right(t_c3dmlx *c3d)
{
	t_player	*player;
	t_game		*game;

	game = c3d->game;
	player = c3d->game->player;
	if (game->map
		[(int)(player->position.y)]
		[(int)(player->position.x + player->camera_pl_vec.x
			* ceil(player->move_speed))] != '1')
		player->position.x += (player->move_speed * player->camera_pl_vec.x);
	if (game->map
		[(int)(player->position.y + player->camera_pl_vec.y
			* ceil(player->move_speed))]
		[(int)(player->position.x)] != '1')
		player->position.y += (player->move_speed * player->camera_pl_vec.y);
}
