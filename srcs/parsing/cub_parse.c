/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:55:14 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/14 01:40:16 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	check_cub(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (!path)
		tutup("Error: only .cub accepted\n", 1);
	if (len < 5)
		tutup("Error: only .cub accepted\n", 1);
	if (ft_strncmp(path + len - 4, ".cub", len) != 0)
		tutup("Error: only .cub accepted\n", 1);
	return (0);
}

void	open_cub(t_c3dmlx *c3d, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0 || check_cub(path))
	{
		close(fd);
		tutup_c3d(c3d, "Error: Invalid fd in open()\n", 1);
	}
	read_textures(c3d, fd);
	read_map(c3d, fd);
}
