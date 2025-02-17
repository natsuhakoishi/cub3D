/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:47:32 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/18 03:08:57 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	listen_keypress(int key, t_c3dmlx *c3d)
{
	if (key == ESCAPE_KEY)
		tutup("\nThanks for Playing !!!\n\n", 0);
	if (key == LEFT_KEY)
		c3d->control->look_left = 1;
	if (key == RIGHT_KEY)
		c3d->control->look_right = 1;
	if (key == W_KEY)
		c3d->control->move_front = 1;
	if (key == A_KEY)
		c3d->control->move_left = 1;
	if (key == S_KEY)
		c3d->control->move_back = 1;
	if (key == D_KEY)
		c3d->control->move_right = 1;
	return (0);
}
