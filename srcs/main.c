/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:46:52 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/17 22:59:22 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	main(int argc, char **argv)
{
	t_c3dmlx	*c3d;

	if (argc != 2)
		tutup("Invalid Arguments. Usage: ./cub3d [map path]\n", 1);
	c3d = init_c3dmlx(argv[1]);
	mlx_hook(c3d->mlx_win, 17, 0, tutup_game, c3d);
	mlx_hook(c3d->mlx_win, 2, 1L << 0, listen_keypress, c3d);
	mlx_hook(c3d->mlx_win, 3, 1L << 1, listen_keyrelease, c3d);
	mlx_loop_hook(c3d->mlx, ft_render, c3d);
	mlx_loop(c3d->mlx);
	return (0);
}
