/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:52:17 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/20 04:16:37 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	tutup(char *msg, int status)
{
	if (!ft_strncmp("\nThanks for Playing !!!\n\n", msg, 28))
		write(1, "\033[38;5;178m", 12);
	else
		write(1, "\033[38;5;160m", 12);
	ft_putstr_fd(msg, 0);
	write(1, "\033[0m", 5);
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
