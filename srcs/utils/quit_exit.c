/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:52:17 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/18 03:09:02 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	tutup(char *msg, int status)
{
	ft_putstr_fd(msg, 0);
	exit(status);
}

void	tutup_c3d(t_c3dmlx *c3d, char *msg, int status)
{
	(void)c3d;
	tutup(msg, status);
}

int	tutup_game(void)
{
	tutup("\nThanks for Playing !!!\n\n", 0);
	return (0);
}
