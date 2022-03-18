/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idouidi <idouidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:19:17 by idouidi           #+#    #+#             */
/*   Updated: 2021/01/14 13:55:06 by idouidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "../../project/libft/libft.h"
# include <math.h>
# include "../../mlx_linux/mlx.h"

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_player
{
	char		letter;
	double		pos_x;
	double		pos_y;
	int			map_x;
	int			map_y;
	double		dir_x;
	double		dir_y;
	float		sp;
}				t_player;

typedef struct	s_ray
{
	double		sidedist_x;
	double		sidedist_y;
	double		deltadist_x;
	double		deltadist_y;
	double		step_x;
	double		step_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		perpwalldist;
	int			hit;
	int			hit_side;
	int			line_height;
}				t_ray;

typedef	struct	s_square
{
	int			width;
	int			height;
	int			imgx;
	int			imgy;
}				t_square;

typedef	struct	s_texture
{
	void		*tex[6];
	char		*addr[6];
	int			width[6];
	int			height[6];
	int			bpp[6];
	int			szl[6];
	int			endian[6];
}				t_texture;

typedef	struct	s_sprite
{
	float		x;
	float		y;
	double		dist;
}				t_sprite;

typedef	struct	s_img
{
	void		*ptr[5];
	char		*addr[5];
	int			line_length;
	int			bits_per_pixel;
	int			endian;
}				t_img;

typedef struct	s_data
{
	t_square	square;
	t_vars		vars;
	t_player	player;
	t_ray		ray;
	t_img		img;
	t_texture	texture;
	t_sprite	*spt;
	char		**map;
	char		*sprite;
	char		*north;
	char		*east;
	char		*south;
	char		*west;
	char		*tmp;
	char		*tmp1;
	char		*resolution;
	char		*floor;
	char		*ceiling;
	int			count_spt;
	int			map_x;
	int			map_y;
	int			f_color;
	int			c_color;
	int			save;
	int			w_x;
	int			w_y;
	int			spritescreen_x;
	int			spriteheight;
	int			spritewidth;
	int			drawstart_x;
	int			drawend_x;
	int			drawstart_y;
	int			drawend_y;
	int			sizex;
	int			sizey;
	int			fd;
	double		camera_x;
	double		*rays;
	double		sprite_x;
	double		sprite_y;
	double		invdet;
	double		transform_x;
	double		transform_y;
	float		x;
	float		y;
	long		res[2];

}				t_data;

int				flags(char c);
int				check_empty_line(t_data *d);
int				is_flags(char *s, int i);
int				r_f_c(char *s);
int				pars_info_map(t_data *d);
int				pars_map(t_data *d, int len);
int				pars_file(t_data *data);
int				border(char *s);
int				check_textures(t_data *d);
char			*fill_str(char *s1, char *s2, int i, int j);
char			*noblank(char *s, int c);
char			**noblank_2(char **s, int c, char *set);
void			set_position(t_data *d);
void			info_map_setup(char *s, int i, int *j, int *k);
void			set_var(t_data *d);
void			adjust_map(t_data *d);
int				set_rfc(t_data *d);
void			init_player(t_data *d);
int				cub3d(t_data *d);
void			window(t_data *d);
void			raycasting(t_data *d);
void			set_position(t_data *d);
void			my_mlx_pixel_put(t_data *d, int color);
void			drawfov(t_data *d);
void			drawline(t_data *d, double dir, int i, int color);
void			drawplayer(t_data *d);
void			which_dir(t_data *d, int keycode);
void			which_dir2(t_data *d, int keycode);
void			drawsquare(t_data *d, int color);
void			create_img(t_data *d, int i, int width, int height);
void			get_ray_size(t_data *d);
void			rotation(t_data *d, int keycode);
void			dda(t_data *d);
void			draw_wall(t_data *d);
void			catch_sprite(t_data *d, int b);
void			dda_sprite(t_data *d);
void			check_dist(t_data *d, double dist);
void			create_bitmap(t_data *d);
void			sort_sprites(t_data *d);
void			adjust_sprites_order(t_data *d);
void			set_drawsprites(t_data *d, int i);
void			limit_to_draw(t_data *d);
void			drawsprites(t_data *d, int stripe, int col, int color);
void			do_sprites(t_data *d);
void			clean(t_data *d);
int				get_spt_color(t_data *d, int stripe);
int				cross_window(t_data *d);
void			leak(void *str);
void			leak_2(char **str);
int				checksizemap(t_data *d, int **check);
int				create_trgb(int t, int r, int g, int b);
int				get_r(int color);
int				get_g(int color);
int				get_b(int color);
int				add_shade(t_data *d, int trgb, float dist);
#endif
