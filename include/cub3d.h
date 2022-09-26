/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naqua <naqua@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 20:39:35 by naqua             #+#    #+#             */
/*   Updated: 2022/07/12 19:22:22 by naqua            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include "../minilibx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define    NO 0
# define    WE 1
# define    EA 2
# define    SO 3

typedef struct s_ray
{
	double	len;
	double	x;
	double	y;
	double	angle;
	double	x_hit;
	double	y_hit;
	int		flag;
}	t_ray;

typedef struct s_player
{
	double	x;
	double	y;
	char	player_type;
}	t_player;

typedef struct s_mouse
{
	int	x;
	int	y;
}	t_mouse;

typedef struct s_camera
{
	double	x;
	double	y;
}	t_camera;

typedef struct s_color
{
	int		ceil;
	int		floor;
	int		c_col_r;
	int		c_col_g;
	int		c_col_b;
	int		f_col_r;
	int		f_col_g;
	int		f_col_b;
	int		duplicate_flag_f;
	int		duplicate_flag_c;
}	t_color;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		en;
	int		*pix;
	int		width;
	int		height;
}	t_data;

typedef struct s_pic
{
	int		no_duplicate_flag;
	int		so_duplicate_flag;
	int		we_duplicate_flag;
	int		ea_duplicate_flag;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
}	t_pic;

typedef struct s_game
{
	char		**map;
	int			map_flag;
	int			map_already_init_flag;
	int			map_width;
	int			map_height;
	void		*win;
	void		*mlx;
	double		d_anglee;
	t_ray		*rays;
	t_player	player;
	t_camera	camera;
	t_color		color;
	t_data		data;
	t_pic		pic;
	t_mouse		mouse;
	void		*gun_img1;
	void		*gun_img2;
	void		*gun_img3;
	void		*gun_img4;
	void		*gun_img5;
	void		*gun_img;
	int			anim;
	int			gun;
	int			tmp;
	double		gamma;
	double		x_prev;
	double		y_prev;
	char		*map_str;
}	t_game;

/* INIT */

void		map_reader(char *path, t_game *game, int fd, char *map_holder);
void		color_reader(char *path, t_game *game);
void		map_validate(char **map, t_game *game);
void		ft_free(char **result);
void		camera_player_pos(t_game *game);
void		map_size(t_game *game);
void		init(int argc, char **argv, t_game *game);
void		ft_argv_checker(char *argv);
void		ft_argc_num_checker(int argc);
void		set_imgages(t_game *game);
void		extern1(t_game *game);
void		pic_validate(t_game *game);
int			ft_exit(t_game *game);

/* RAYCAST */

double		h_c_s(t_ray ray, t_game *game, t_ray *luch);
double		h_l_s(t_ray ray, t_game *game, t_ray *luch);
double		h_c_f(t_ray ray, t_game *game, t_ray *luch);
double		h_l_f(t_ray ray, t_game *game, t_ray *luch);
double		h_c_t(t_ray ray, t_game *game, t_ray *luch);
double		h_l_t(t_ray ray, t_game *game, t_ray *luch);
double		h_c_h(t_ray ray, t_game *game, t_ray *luch);
double		h_l_h(t_ray ray, t_game *game, t_ray *luch);
void		first_line(t_game *game, t_ray *ray, t_ray *luch);
void		first_colmn(t_game *game, t_ray *ray, t_ray *luch);
void		second_line(t_game *game, t_ray *ray, t_ray *luch);
void		second_colmn(t_game *game, t_ray *ray, t_ray *luch);
void		third_line(t_game *game, t_ray *ray, t_ray *luch);
void		third_colmn(t_game *game, t_ray *ray, t_ray *luch);
void		fourth_line(t_game *game, t_ray *ray, t_ray *luch);
void		fourth_colmn(t_game *game, t_ray *ray, t_ray *luch);
void		floor_ceil(t_game *game, int i, int j);
void		init_angels(t_game *game);
int			update_screen(t_game *game);
double		pifogor(double x, double y, t_game *game);
void		raycast(t_game *game);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
double		pifogor_real(double x, double y);
void		ft_raycast(t_game *game, int i);

/* MOVES */

void		left_turn(t_game *game);
void		right_turn(t_game *game);
void		forward(t_game *game);
void		back(t_game *game);
void		left(t_game *game);
void		right(t_game *game);

/* BONUS */

int			wall_collion(t_game *game, int keycode);
void		minimap_draw(t_game *game, int i, int j, int k);
int			mouse_move(int x, int y, t_game *game);
int			gun_deact(int key, int x, int y, t_game *game);
int			gun_act(int key, int x, int y, t_game *game);
void		player_draw(t_game *game);

#endif
