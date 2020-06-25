/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:16:53 by pmaldagu          #+#    #+#             */
/*   Updated: 2020/03/09 20:58:33 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# define TXT_HW 64

typedef struct s_index	t_index;

typedef struct	s_cell
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
}				t_cell;

typedef	struct	s_floor
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		raydirfx;
	float		raydirfy;
	float		raydircx;
	float		raydircy;
	int			p;
	float		posz;
	float		rowdist;
	float		fstepx;
	float		fstepy;
	float		floorx;
	float		floory;
}				t_floor;

typedef struct	s_move
{
	float		posx;
	float		posy;
	float		dirx;
	float		diry;
	float		planex;
	float		planey;
	char		**map;
	int			maxy;
	t_index		*idx;
}				t_move;

typedef struct	s_algo
{
	int			stepx;
	int			stepy;
	float		perpwdist;
	float		raydirx;
	float		raydiry;
	int			mapx;
	int			mapy;
	float		sidedistx;
	float		sidedisty;
	float		deltadistx;
	float		deltadisty;
	int			drstart;
	int			drend;
}				t_algo;

typedef struct	s_text
{
	void		*img[4];
	char		*addr[4];
	char		*path[4];
	int			wall;
	int			texx;
	float		wallx;
	float		step;
	float		textpos;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_text;

typedef struct	s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_sprite
{
	float		*smapx;
	float		*smapy;
	char		*path;
	void		*img;
	char		*addr;
	int			num;
	int			drawsx;
	int			drawsy;
	int			drawex;
	int			drawey;
	float		trsformy;
	float		trsformx;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		*zbuffer;
}				t_sprite;

struct			s_index
{
	void		*ptr;
	void		*win;
	int			h;
	int			w;
	char		dir;
	int			f;
	int			c;
	t_algo		*alg;
	t_move		*mv;
	t_img		*wall;
	t_text		*text;
	t_sprite	*sp;
	t_floor		*fl;
	t_cell		*cl;
};

/*
**cub3d
*/

/*
** parsing
*/
int				cub(int fd, t_index *idx);
int				cubcheck(char *line, t_index *idx);
int				rescheck(char *line, t_index *idx);
int				pathcheck(char *line, int data, t_text *text, t_sprite *sp);
int				colorcheck(char *line, int data, t_index *idx);
/*
**map
*/
int				dircheck(char c, t_index *idx, int y, int x);
int				checkline(char *line, t_index *idx, int l);
int				firstline(char *line);
int				mapcheck(t_index *idx);
int				storemap(int fd, t_index *idx);
/*
**map2
*/
int				newmap(t_index *idx, t_move *mv, int fd);
char			*mewline(char *oldline, int maxx);
int				checkentour(t_move *mv);
int				poswitch(t_move *mv, int i, int j);
/*
**error
*/
int				init(int argc, char **argv, t_index *idx);
int				cuberror(int fd, t_index *idx, t_img *wall);
int				s_init(int fd, t_index *idx);
int				texture_img(t_index *idx, t_text *text);
int				texture_addr(t_index *idx, t_text *text, t_sprite *sp);
/*
**transition
*/
int				parstostruct(t_index *idx, t_move *mv);
int				dirtostruct(t_index *idx, t_move *mv);
int				smaptostruct(t_index *idx, t_sprite *sp);
void			maxres(t_index *idx);
/*
**raycast
*/
void			raycast_loop(t_index *idx, t_algo *alg, t_move *mv);
void			ray_step(t_algo *alg, t_move *mv);
int				ray_dda(t_index *idx, t_algo *alg);
void			ray_draw(t_index *idx, t_algo *alg, int x, int side);
void			rays_side(t_algo *alg, t_move *mv, t_text *text, int side);
/*
**movement
*/
int				key_input(int key, t_move *mv);
void			rotation(int key, t_move *mv);
void			strife(int key, t_move *mv);
/*
**draw
*/
void			draw_column(t_index *idx, t_algo *alg, int x);
void			background(t_index *idx, t_img *back);
/*
**sprite
*/
void			sprite(t_index *idx, t_move *mv, t_sprite *sp);
void			sprite_sort(t_move *mv, t_sprite *sp);
void			dimension(t_index *idx, t_sprite *sp, int spscreenx);
void			sp_draw(t_index *idx, int spheight, int spwidth, int spscreenx);
void			sprite_y(t_index *idx, int spheight, int texx, int stripe);
/*
**utils
*/
size_t			ft_ostrlen(const char *str, char c);
char			*ft_ostrjoin(const char *s1, const char *s2, char o);
int				s_free(t_index *idx);
void			ft_swap(t_sprite *sp, int i, int j, char coord);
/*
**free
*/
int				freexit(t_index *idx, int err);
void			freestruct(t_index *idx);
void			freeimg(t_index *idx, t_sprite *sp, t_img *wall);
void			freemap(t_move *mv, t_text *text);
void			initptr(t_index *idx);
/*
**bmp
*/
int				bmp(t_index *idx);
void			bmp_header(t_index *idx, t_img *wall, int fd);
void			bitshift(char *header, unsigned int value);
/*
**main
*/
int				key_exit(t_index *idx);
int				bonusinit(t_index *idx);
/*
**floor
*/
void			draw_cell(t_index *idx, t_floor *fl, t_cell *cl, int y);
void			draw_floor(t_index *idx, t_move *mv, t_floor *fl, t_cell *cl);

#endif
