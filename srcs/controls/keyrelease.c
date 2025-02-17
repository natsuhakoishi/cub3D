/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyrelease.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:51:48 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/14 01:39:59 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	listen_keyrelease(int key, t_c3dmlx *c3d)
{
	if (key == LEFT_KEY)
		c3d->control->look_left = 0;
	if (key == RIGHT_KEY)
		c3d->control->look_right = 0;
	if (key == W_KEY)
		c3d->control->move_front = 0;
	if (key == A_KEY)
		c3d->control->move_left = 0;
	if (key == S_KEY)
		c3d->control->move_back = 0;
	if (key == D_KEY)
		c3d->control->move_right = 0;
	return (0);
}
