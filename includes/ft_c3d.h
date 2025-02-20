/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgoh <zgoh@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:12:09 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/20 01:13:37 by zgoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_C3D_H
# define FT_C3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include "cub3d.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

//init

t_c3dmlx	*init_c3dmlx(char *path);
void		init_player(t_c3dmlx *c3d);

//parsing

void		open_cub(t_c3dmlx *c3d, char *path);
int			check_cub(char *path);
void		read_map(t_c3dmlx *c3d, int fd);
void		read_textures(t_c3dmlx *c3d, int fd);
void		parse_map(t_c3dmlx *c3d);
int			parse_fl(t_c3dmlx *c3d, int y, int x);
void		parse_map2(t_c3dmlx *c3d, char **map, int y, int x);
void		parse_borders(char **map, int y, int x);
void		parse_player(t_c3dmlx *c3d, char **map, int y, int x);
void		parse_symbols(t_c3dmlx *c3d, char *mapline);
int			parse_line(t_c3dmlx *c3d, char **split);
void		load_texture(t_c3dmlx *c3d, t_img *img, char *tex_path);
int			process_colors(t_c3dmlx *c3d, char *cf, char **split);
int			check_textures(t_c3dmlx *c3d);

//controls

int			listen_keypress(int key, t_c3dmlx *c3d);
int			listen_keyrelease(int key, t_c3dmlx *c3d);
void		event_exec(t_c3dmlx *c3d);

//player

void		init_camera(t_c3dmlx *c3d, double dv_y, double pl_x, double pl_y);
void		move_forward(t_c3dmlx *c3d);
void		move_backward(t_c3dmlx *c3d);
void		move_left(t_c3dmlx *c3d);
void		move_right(t_c3dmlx *c3d);
void		turn_left(t_c3dmlx *c3d);
void		turn_right(t_c3dmlx *c3d);

//render && raycasting
int			ft_render(void *arg);
void		ft_raycasting(t_c3dmlx *c3d, t_raycast *ray);
void		ft_dda(t_c3dmlx *c3d, t_raycast *ray);
void		calc_wall_height(t_raycast *ray, t_player *player);
void		draw_textures(t_c3dmlx *c3d, t_raycast *ray, t_player *player);
void		draw_teximg(t_c3dmlx *c3d, t_raycast *ray, t_line *line,
				t_img *img);
void		draw_fcline(t_c3dmlx *c3d, t_line *line, int rgb);

//utils - helper
char		*get_next_line(int fd);

//utils - clean up
void		free_dptr(char **str);
void		tutup(char *msg, int status);
void		tutup_c3d(t_c3dmlx *c3d, char *msg, int status);
int			tutup_game(void);

#endif
