/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: m-boukel <m-boukel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 12:58:47 by m-boukel          #+#    #+#             */
/*   Updated: 2023/10/06 17:01:34 by m-boukel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARS_H
# define PARS_H

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

typedef struct c_c //color and coord
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
	char	**file;
	char	*d;
	char	**d_spl;
	char	*clr;
	char	*map;
	char	**map_spl;
}			t_files;

typedef struct texture
{
	char *_no;
	char *_so;
	char *_we;
	char *_ea;
}			t_texture;

typedef struct data
{
	int			wall;
	int			player;
	t_c_c		*c_c;
	t_deriction	*deriction;
	t_files		*files;
	t_ppos		*pos;
	t_texture	*texture;
}					t_data;

void	check_map(t_data *data);
int	is_valid(char c);
int	is_map(char *buffer);
void	read_file(t_data *data, int fd);
void	read_map(t_data *data, int fd);
void	split_file(t_data *data);
int	check_Deriction(t_data *data);
int	check_colors(t_data *data);
int	ft_new_atoi(char *str);
void	check_player_pos(t_data *data);
int	check_texture_path(t_data *data);

#endif