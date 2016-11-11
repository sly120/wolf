/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:51:18 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 12:45:50 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			ocl_init(t_param *p)
{
	p->device_id = NULL;
	p->context = NULL;
	p->command_queue = NULL;
	p->memobj = NULL;
	p->program = NULL;
	p->kernel = NULL;
	p->platform_id = NULL;
}

void			ocl_load_source(t_param *p)
{
	int			fd;

	fd = open("./src/wolf.cl", O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Failed to load kernel.", 2);
		exit(1);
	}
	p->source_str = (char*)malloc(MAX_SOURCE_SIZE);
	p->source_size = read(fd, p->source_str, MAX_SOURCE_SIZE);
//	printf("source_size : %lu\n", source_size);
	close(fd);
}

void			ocl_prepare(t_param *p)
{
	p->ret = clGetPlatformIDs(1, &p->platform_id, &p->ret_num_platforms);
	p->ret = clGetDeviceIDs(p->platform_id, CL_DEVICE_TYPE_GPU, 1,
			&p->device_id, &p->ret_num_devices);
	p->context = clCreateContext(NULL, 1, &p->device_id, NULL, NULL, &p->ret);
	p->command_queue = clCreateCommandQueue(p->context, p->device_id, 0,
			&p->ret);
	p->program = clCreateProgramWithSource(p->context, 1,
			(const char **)&p->source_str,
			(const size_t *)&p->source_size, &p->ret);
	p->ret = clBuildProgram(p->program, 1, &p->device_id, NULL, NULL, NULL);
	p->kernel = clCreateKernel(p->program, "hello", &p->ret);
}

void			mlx_initialization(t_param *p)
{
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, MAX_X, MAX_Y, "Wolf3D");
	p->img = mlx_new_image(p->mlx, MAX_X, MAX_Y);
	p->imgad = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->endian);
	if (p->bpp != 32 || p->endian != 0)
	{
		ft_putendl_fd("This program doesn't work on this computer\n", 2);
		exit(1);
	}
}

/*void			readtab(int **tab, t_param *p)
{
	int			x;
	int			y;

	printf("map :\n");
	y = 0;
	while (y < p->tableny)
	{
		x = 0;
		while (x < p->tablenx)
		{
			ft_putstr(ft_itoa(tab[y][x++]));
			ft_putstr(" ");
		}
		ft_putstr("\n");
		y++;
	}
}*/

int				main(int argc, char **argv)
{
	t_param		p;

	ocl_init(&p);
	ocl_load_source(&p);
	ocl_prepare(&p);
	mlx_initialization(&p);
	if (argc == 1)
	{
		p.map = readfile(&p, "./map/map.txt");
		wolf(&p);
	}
	else
	{
		p.map = readfile(&p, "./map/map2.txt");
		wolf3d(&p);
	}
//	readtab(p.map, &p);
	return (0);
}
