/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyean-wa < yyean-wa@student.42kl.edu.my    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 00:50:58 by yyean-wa          #+#    #+#             */
/*   Updated: 2025/02/19 22:39:11 by yyean-wa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 4242

# define WIN_W 1280
# define WIN_H 720

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

# define ESCAPE_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363

typedef struct s_line
{
	int	x;
	int	y;
	int	y_sd;
	int	y_ed;
	int	x_texd;
	int	y_texd;
}				t_line;

typedef struct s_raycast
{
	int		scrpx_x;
	int		map_x;
	int		map_y;
	double	camera_x;
	double	raydirc_x;
	double	raydirc_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	pwall_dist;
	int		step_x;
	int		step_y;
	int		wall_hit;
	int		direction;
	int		draw_height;
	int		draw_start;
	int		draw_end;
}				t_raycast;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		width;
	int		height;
	int		endian;
}				t_img;

typedef struct s_coordinate
{
	double	x;
	double	y;
}				t_coordinate;

typedef struct s_player
{
	t_coordinate	position;
	t_coordinate	vec_direction;
	t_coordinate	camera_pl_vec;
	double			move_speed;
	double			sens;
}				t_player;

typedef struct s_game
{
	char		**map;
	int			player_found;
	t_player	*player;
}				t_game;

typedef struct s_control
{
	int	look_left;
	int	look_right;
	int	move_front;
	int	move_back;
	int	move_left;
	int	move_right;
}				t_control;

typedef struct s_c3dmlx
{
	void		*mlx;
	void		*mlx_win;
	t_img		*mlx_img;
	t_img		*no_texture;
	t_img		*so_texture;
	t_img		*we_texture;
	t_img		*ea_texture;
	int			floor_rgb;
	int			ceiling_rgb;
	t_game		*game;
	t_control	*control;
}				t_c3dmlx;

#endif
