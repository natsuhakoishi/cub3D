/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:57:25 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/20 04:01:27 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_c3d.h"

int	check_textures(t_c3dmlx *c3d)
{
	if (!c3d->no_texture->img_ptr || !c3d->so_texture->img_ptr
		|| !c3d->we_texture->img_ptr || !c3d->ea_texture->img_ptr
		|| !c3d->floor_rgb || !c3d->ceiling_rgb)
		return (0);
	return (1);
}

int	process_colors(t_c3dmlx *c3d, char *cf, char **split)
{
	char	**colors;
	int		r;
	int		g;
	int		b;

	colors = ft_split(split[1], ',');
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free_dptr(colors);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		tutup_c3d(c3d, "Error: RGB value exceed range\n", 1);
	if (!ft_strcmp(cf, "F"))
		c3d->floor_rgb = (1 << 24 | r << 16 | g << 8 | b);
	else if (!ft_strcmp(cf, "C"))
		c3d->ceiling_rgb = (1 << 24 | r << 16 | g << 8 | b);
	else
		return (1);
	return (0);
}

void	load_texture(t_c3dmlx *c3d, t_img *img, char *tex_path)
{
	int	width;
	int	height;

	img->img_ptr = mlx_xpm_file_to_image(c3d->mlx, tex_path,
			&width, &height);
	if (!img->img_ptr)
		tutup_c3d(c3d, "Error: Failure: mlx_xpm_file_to_image\n", 1);
	img->width = width;
	img->height = height;
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel,
			&img->size_line, &img->endian);
}

static int	process_textures(t_c3dmlx *c3d, char *dirc, char **split)
{
	char	*tex_path;

	tex_path = ft_strtrim(split[1], "\n");
	if (!ft_strcmp(dirc, "NO"))
		load_texture(c3d, c3d->no_texture, tex_path);
	else if (!ft_strcmp(dirc, "SO"))
		load_texture(c3d, c3d->so_texture, tex_path);
	else if (!ft_strcmp(dirc, "WE"))
		load_texture(c3d, c3d->we_texture, tex_path);
	else if (!ft_strcmp(dirc, "EA"))
		load_texture(c3d, c3d->ea_texture, tex_path);
	else
	{
		free(tex_path);
		return (1);
	}
	free(tex_path);
	return (0);
}

int	parse_line(t_c3dmlx *c3d, char **split)
{
	if (!ft_strcmp(split[0], "NO") || !ft_strcmp(split[0], "SO")
		|| !ft_strcmp(split[0], "WE") || !ft_strcmp(split[0], "EA"))
		return (process_textures(c3d, split[0], split));
	else if (!ft_strcmp(split[0], "F") || !ft_strcmp(split[0], "C"))
		return (process_colors(c3d, split[0], split));
	else if (!strcmp(split[0], "\n"))
		return (0);
	return (1);
}
