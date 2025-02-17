/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:48:08 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 17:51:00 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	event_exec(t_c3dmlx *c3d)
{
	if (c3d->control->look_left)
		turn_left(c3d);
	if (c3d->control->look_right)
		turn_right(c3d);
	if (c3d->control->move_front)
		move_forward(c3d);
	if (c3d->control->move_back)
		move_backward(c3d);
	if (c3d->control->move_left)
		move_left(c3d);
	if (c3d->control->move_right)
		move_right(c3d);
}
