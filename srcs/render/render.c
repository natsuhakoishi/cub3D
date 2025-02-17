/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:17:27 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 23:18:18 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	ft_render(void *arg)
{
	t_c3dmlx	*c3d;
	t_raycast	*ray;

	c3d = (t_c3dmlx *)arg;
	ray = malloc(sizeof(t_raycast));
	ft_memset(ray, 0, sizeof(t_raycast));
	while (ray->scrpx_x < WIN_W)
		ft_raycasting(c3d, ray);
	mlx_put_image_to_window(c3d->mlx, c3d->mlx_win,
		c3d->mlx_img->img_ptr, 0, 0);
	free(ray);
	event_exec(c3d);
	return (0);
}
