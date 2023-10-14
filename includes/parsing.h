/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:14:36 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/14 10:15:09 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct texture
{
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
}			t_texture;

typedef struct s_ppos
{
	int		x;
	int		y;
	char	dir;
}			t_ppos;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	error;
}			t_color;

typedef struct c_c
{
	t_color	*f;
	t_color	*c;
	int		floor;
	int		ceiling;
}				t_c_c;

typedef struct s_deriction
{
	int	no;
	int	so;
	int	we;
	int	ea;
}			t_deriction;

typedef struct files
{
	char		**file;
	char		*d;
	char		**d_spl;
	char		*clr;
	char		*map;
	char		**map_spl;
	t_texture	texture;
}			t_files;

typedef struct data
{
	int			wall;
	int			player;
	t_c_c		*c_c;
	t_deriction	*deriction;
	t_files		*files;
	t_ppos		*pos;
}					t_data;

/*=========================Check_texture=======================*/
int		is_texture(t_data *data, int i);
void	joint(t_data *data, int i);
int		check_texture_path(t_data *data);
int		check_deriction(t_data *data);
void	check_empty_path(char **tmp);
/*=============================================================*/

/*=========================Check_colors=========================*/
int		check_colors(t_data *data);
void	check_coma(char *s);
void	split_rgb(t_color *color, char *str, int i);
void	joinc(t_data *data, int i);
int		is_color(char *s);
/*==============================================================*/

/*=========================Check_map============================*/
void	check_player_pos(t_data *data);
int		check_char(char c);
int		valid_char(char c);
void	check_door(char **map, int i, int j);
void	check_map(t_data *data);
int		is_map(char *buffer);
void	empty_line(t_data *data, int i);
void	invalid_char(t_data *data, int i);
void	joinm(t_data *data, int i);
/*==============================================================*/

/*=========================help_func==========================*/
int		is_valid(char c);
void	read_file(t_data *data, int fd);
void	split_file(t_data *data);
int		ft_new_atoi(char *str);
int		free_string(char **str);
int		check_split_count(char **str, int n);
/*=============================================================*/

#endif