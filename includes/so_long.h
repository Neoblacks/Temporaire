/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2023/02/13 15:24:13 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
 * Section 1 : Includes different libs and defines some macros
 */

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdbool.h>
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define F_KEY 102
# define G_KEY 103
# define H_KEY 104
# define J_KEY 106
# define SUCCESS 0
# define FAIL 1
# define NEXT 2

typedef enum e_component
{
	IMG_WALL,
	IMG_WALL_BREAK,
	IMG_PLAYER_IDLE1,
	IMG_PLAYER_IDLE2,
	IMG_PLAYER_IDLE3,
	IMG_PLAYER_IDLE4,
	IMG_COLLECTIBLE_1,
	IMG_COLLECTIBLE_2,
	IMG_COLLECTIBLE_3,
	IMG_COLLECTIBLE_4,
	IMG_FLOOR,
	IMG_EXIT_ACTIVATE,
	IMG_EXIT_DESACTIVATE,
}	t_component;

/*
 * Section 2 : Initialisation of Structs
 */

typedef struct s_vars
{
	int		i;
}	t_vars;

typedef struct coord_move_s
{
	int	x;
	int	y;
}	t_coord_move;

typedef struct pos_s
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_queue
{
	int		debut;
	int		fin;
	t_pos	*array;
}	t_queue;

typedef struct s_near
{
	int		x_near;
	int		y_near;
	bool	**visits;
}	t_near;

typedef struct content_s
{
	char	wall;
	char	player;
	char	collectible;
	char	empty;
	char	exit;
	char	other;
	int		count_player;
	int		count_exit;
	int		remaning_other;
	int		total_other;
	int		count_collectible;
}	t_content;

typedef struct image_s
{
	int		img_height;
	int		img_width;
	void	*img_wall;
	void	*img_player;
	void	*img_player_idle1;
	void	*img_player_idle2;
	void	*img_player_idle3;
	void	*img_player_idle4;
	void	*img_collectible_1;
	void	*img_collectible_2;
	void	*img_collectible_3;
	void	*img_collectible_4;
	void	*img_floor;
	void	*img_exit_activate;
	void	*img_exit_desactivate;
	void	*img_wall_break;
	char	*player;
	char	*player_idle1;
	char	*player_idle2;
	char	*player_idle3;
	char	*player_idle4;
	char	*floor;
	char	*wall;
	char	*wall_break;
	char	*collectible_1;
	char	*collectible_2;
	char	*collectible_3;
	char	*collectible_4;
	char	*exit_activate;
	char	*exit_desactivate;
}	t_image;

typedef struct s_data
{
	void			*mlx;

	void			*image_new;
	char			*image_new_addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	void			*win;
	char			**map;
	int				fd3;
	int				count;
	unsigned int	total_count_move;
	int				total_count_collect;
	int				total_count_other;
	int				nb_take_collect;
	int				nb_total_take_collect;
	int				nb_take_other;
	int				nb_total_take_other;
	int				width;
	int				height;
	int				counter;
	int				anim;
	int				exit_found;
	int				collect_found;
	int				remaning_collect;
	int				size_x;
	int				size_y;
	unsigned int	nb_map;
	t_image			image;
	t_vars			vars;
	t_content		content;
	t_pos			position;
	t_near			near;
	t_queue			queue;
	t_coord_move	coord_move;
}	t_data;

/*
 * Section 3 : Prototypes of functions
 */
void	ft_create_new_image(t_data *data);
void	put_text(t_data *data);

/* GESTION_WINDOW.C */
int		esc_close(int keycode, t_data *data);
int		cross_close(t_data *data);
int		move_key(int keycode, t_data *data);

/* CHECK_MAP.C */

int		ft_check_format(char **map);
int		ft_check_other(char *map_line, t_content *content);
int		ft_check_line(char *map_line, char wall);
int		ft_check_column(char *map_line, char wall, t_data *data);
void	ft_check_content(t_data *data);

/* END.C + END_UTILS.c */

int		ft_urgency(t_data *data);
int		ft_critical(t_data *data);
void	ft_stop(t_data *data, int code);
void	ft_free_array(t_data *data);
void	ft_free_visits(t_data *data);
void	*ft_clean_map(t_data *data);
void	ft_destroy_img(t_data *data);

void	ft_error(char *str);
void	ft_error_exit(char *str);

/* GESTION_MAP.c */

char	**ft_parse_map(int fd, t_data *data);
char	**ft_get_map(int fd);
void	map(char *str, t_data *data);
void	ft_check_map(int fd, t_data *data);
void	ft_check_nb_symbols(t_data *data);
void	ft_open_file(char *str);
void	ft_check_file_empty(int fd);
void	ft_start_map(char *str, t_data *data);

/* MAIN.C */

void	ft_count_collect(t_data *data);
int		ft_strstr(const char *str, char *comp);
void	ft_check_data_map(t_data *data, int deplacements[4][2]);

/* MOVE.C */

void	ft_move_all(t_data *data, int dy, int dx);

void	ft_next_map(t_data *data);

/* RENDER.C */

int		render_main(t_data *data);
void	render_bg(t_data *data);
void	render_other(t_data *data);
void	window_utils(t_data *data);
void	display_img(t_data *data, void *img, int x, int y);
void	render_collec(t_data *data, int i, int j);
void	render_exit(t_data *data, int i, int j);
void	render_player(t_data *data, int i, int j);

/* TEXTURE.C */

void	ft_content(t_content *content);
void	ft_texture(t_data *data);
void	ft_check_file(t_data *data);
void	ft_destroy(t_data *data, t_component component);
void	ft_check_collectible(t_data *data);
void	ft_check_player(t_data *data);
void	ft_choose_img(t_data *data, t_component component);
void	ft_texture_player(t_data *data);
void	ft_texture_collec(t_data *data);

/* VALIDATE_MAP.C */

int		browse_grid(t_data *data, int deplacements[4][2]);
int		find_collect_exit(t_data *data, int deplacements[4][2]);
bool	is_valid(int x, int y, t_data *data);
void	check_find_collect_exit(t_data *data, int deplacements[4][2]);
void	check_near(t_data *data, int deplacements[4][2]);

/* VALIDATE_MAP_UTILS.C */

void	set_pos(t_pos *pos, const int x, const int y);
void	init_deplacement(int deplacements[4][2]);
void	alloc_array(t_data *data);
void	alloc_visits(t_data *data);
void	init_visits(t_data *data);

/* VALIDATE_MAP_UTILS2.C */

void	set_queue(t_data *data, t_pos *pos);
void	find_player(t_data *data);
void	ft_check_malloc_visit(t_data *data);
int		ft_check_exit(t_data *data, int deplacements[4][2]);

#endif
