/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niboukha <niboukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:19:36 by niboukha          #+#    #+#             */
/*   Updated: 2023/10/15 11:08:10 by niboukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# define A 0
# define S 1
# define W 13
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define H_WIN 941.0
# define W_WIN 1507.0
# define SPEED 17
# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define SPACE 49

typedef struct t_mini
{
	int	f;
	int	e;
}		t_mini;

typedef struct t_textures
{
	double	x;
	double	y;
	int		direction;
}			t_textures;

typedef struct t_coor
{
	int		x;
	int		y;
	int		py;
	int		px;
	int		m_x;
	int		m_y;
	int		put;
	double	d_h;
	double	d_v;
	double	d;
	double	angle;
	int		up;
	int		down;
	int		right;
	int		left;
	int		flag_a;
	int		coll;
}			t_coor;

typedef struct t_dir
{
	void	*img;
	int		w;
	int		h;
}		t_dir;

typedef struct t_image
{
	int		h_img;
	int		w_img;
	void	*img;
	t_dir	img_n;
	t_dir	img_e;
	t_dir	img_s;
	t_dir	img_w;
	t_dir	img_d[5];
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_image;

typedef struct t_wall
{
	int		x;
	int		y;
	double	h_x;
	double	h_y;
	double	gh_x;
	double	gh_y;
	double	v_x;
	double	v_y;
	double	gv_x;
	double	gv_y;
	double	wall_height;
}			t_wall;

typedef struct t_dr
{
	int	i;
	int	j;
}		t_dr;

typedef struct t_map
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_win1;
	char			**map;
	int				index;
	t_coor			coor;
	t_wall			wall;
	t_image			image;
	t_image			textures;
	t_image			sprit;
	t_image			door;
	t_data			*data;
	t_textures		txt;
	t_mini			mini;
	t_dr			dr;
	pthread_mutex_t	mut;
}					t_map;

void			rendering(t_map *map);
void			put_pixel(t_map *map);
void			my_mlx_put_pixel(t_image *img, int x, int y, int color);
int				key(int key_code, t_map *map);
void			get_dist_wall(t_map *map);
void			mouve_player(t_map *map, int x, int y);
int				player_collisions(t_map *map, int x, int y);
int				check_if_wall(t_map *map, int x, int y);
void			draw_walls(t_map *map, double angle);
void			fill_map3(t_map *map);
void			inter_ver_wall(t_map *map, double angle);
void			inter_hori_wall(t_map *map, double angle);
void			coor_of_ver_wall(t_map *map, double x, double y);
void			coor_of_hor_wall(t_map *map, double x, double y);
double			distance_wall(t_map *map, double x, double y);
void			init_map(t_map *map);
void			fill_cub_p(t_map *map, int x, int y, int color);
int				close_win(void);
void			fill_minimap(t_map *map);
int				mouse_key(int key_code, int x, int y, t_map *map);
unsigned int	convert_color(int r, int g, int b);
void			get_coor_player(t_map *map);
int				animation(t_map *map);
unsigned int	get_color(t_map *map, int x, int y);
unsigned int	get_color_(t_map *map, int x, int y);
void			animation_gun(t_map *map, int key_code);
void			*routine(void *ptr);
int				check_doors(t_map *map, int x, int y, int c);
int				mouse_key(int key_code, int x, int y, t_map *map);
void			mouse_(t_map *map, int key_code);
void			map_(t_map *map);
void			mvmt_coll_down(t_map *map);
void			mvmt_coll_up(t_map *map);

#endif
