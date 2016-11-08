/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:31:22 by sly               #+#    #+#             */
/*   Updated: 2016/11/07 21:51:39 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef WOLF3D_H
#define WOLF3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <OpenCL/opencl.h>
#include <math.h>
#include <time.h>
#include "../minilibx_macos/mlx.h"
#include <libft.h>

#define MEM_SIZE 128
#define MAX_SOURCE_SIZE 0X100000
#define MAX_X 2000
#define MAX_Y 1100
#define texwidth 64
#define texheight 64

#define KEY_W 13
#define KEY_S 1
#define KEY_A 0
#define KEY_D 2
#define KEY_ESC 53
#define KEY_CRTL 256

typedef struct			s_param
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*imgad;
	int					bpp;
	int					sl;
	int					endian;
	cl_device_id		device_id;
	cl_context			context;
	cl_command_queue	command_queue;
	cl_mem				memobj;
	cl_program			program;
	cl_kernel			kernel;
	cl_platform_id		platform_id;
	cl_uint				ret_num_devices;
	cl_uint				ret_num_platforms;
	cl_int				ret;
	char				*source_str;
	size_t				source_size;
	int					tablenx;
	int					tableny;
	int					**map;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				olddirx;
	double				planex;
	double				planey;
	double				oldplanex;
	double				movespeed;
	double				rotspeed;
	double				walk;
	double				camerax;
	double				rayposx;
	double				rayposy;
	double				raydirx;
	double				raydiry;
	int					mapx;
	int					mapy;
	double				sidedistx;
	double				sidedisty;
	double				deltadistx;
	double				deltadisty;
	double				perpwalldist;
	int					stepx;
	int					stepy;
	int					hit;
	int					side;
	int					lineheight;
	int					drawstart;
	int					drawend;
	long				**buffer;
	int					**texture;
}						t_param;

int						**readfile(t_param *p, char *src);
int						open_file(char *src);
char					*copy_src(char *src, int i);
int						**createtab(t_param *p);
void					wolf(t_param *p);
void					wolf3d(t_param *p);
void					raycasting(t_param *p);
void					raycasting3d(t_param *p);
void					raycasting3d2(t_param *p);
void					color(int x, t_param *p);
void					manage_time(t_param *p);
void					hook(t_param *p);
int						key_event(int key, t_param *p);
int						quit_program(t_param *p);
#	endif
