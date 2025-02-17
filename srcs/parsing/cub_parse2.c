/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:09:09 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/14 01:40:21 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

void	read_textures(t_c3dmlx *c3d, int fd)
{
	int		textures_flag;
	char	*line;
	char	**split;

	textures_flag = 0;
	line = get_next_line(fd);
	while (!textures_flag && line)
	{
		split = ft_split(line, ' ');
		if (parse_line(c3d, split))
		{
			free(line);
			free_dptr(split);
			tutup_c3d(c3d, "Error: Failure: Textures/Colors", 1);
		}
		textures_flag = check_textures(c3d);
		free(line);
		free_dptr(split);
		line = get_next_line(fd);
	}
	free(line);
	if (!textures_flag)
		tutup_c3d(c3d, "Error: Invalid textures indentity\n", 1);
}

static void	read_buffer(char **buffer, char **line, int fd)
{
	char	*temp;

	temp = ft_strdup(*buffer);
	free(*buffer);
	*buffer = ft_strjoin(temp, *line);
	free(temp);
	free(*line);
	*line = get_next_line(fd);
}

void	read_map(t_c3dmlx *c3d, int fd)
{
	char	*line;
	char	*buffer;

	line = get_next_line(fd);
	while (line && !ft_strcmp(line, "\n"))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
	{
		close(fd);
		tutup_c3d(c3d, "Error: Map not exist\n", 1);
	}
	buffer = ft_bzero(0);
	while (line)
		read_buffer(&buffer, &line, fd);
	c3d->game->map = ft_split(buffer, '\n');
	parse_map(c3d);
	free(buffer);
}
