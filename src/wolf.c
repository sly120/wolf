/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:23:18 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 18:55:30 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			init_values(t_param *p)
{
	p->posx = 22.0;
	p->posy = 11.5;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0;
	p->planey = 0.66;
	p->walk = 1;
	p->duck = 0;
	p->light = 0;
}

void			generate_texture2(t_param *p)
{
	p->texture[4].img = mlx_xpm_file_to_image(p->mlx, "./texture/4.xpm", &p->texture[4].width, &p->texture[4].height);
	p->texture[4].imgad = mlx_get_data_addr(p->texture[4].img, &p->texture[4].bpp, &p->texture[4].size_line, &p->texture[4].endian);
	p->texture[5].img = mlx_xpm_file_to_image(p->mlx, "./texture/5.xpm", &p->texture[5].width, &p->texture[5].height);
	p->texture[5].imgad = mlx_get_data_addr(p->texture[5].img, &p->texture[5].bpp, &p->texture[5].size_line, &p->texture[5].endian);
	p->texture[6].img = mlx_xpm_file_to_image(p->mlx, "./texture/6.xpm", &p->texture[6].width, &p->texture[6].height);
	p->texture[6].imgad = mlx_get_data_addr(p->texture[6].img, &p->texture[6].bpp, &p->texture[6].size_line, &p->texture[6].endian);
	p->texture[7].img = mlx_xpm_file_to_image(p->mlx, "./texture/7.xpm", &p->texture[7].width, &p->texture[7].height);
	p->texture[7].imgad = mlx_get_data_addr(p->texture[7].img, &p->texture[7].bpp, &p->texture[7].size_line, &p->texture[7].endian);
}

void			generate_texture(t_param *p)
{
	p->texture[0].img = mlx_xpm_file_to_image(p->mlx, "./texture/0.xpm", &p->texture[0].width, &p->texture[0].height);
	p->texture[0].imgad = mlx_get_data_addr(p->texture[0].img, &p->texture[0].bpp, &p->texture[0].size_line, &p->texture[0].endian);
	p->texture[1].img = mlx_xpm_file_to_image(p->mlx, "./texture/1.xpm", &p->texture[1].width, &p->texture[1].height);
	p->texture[1].imgad = mlx_get_data_addr(p->texture[1].img, &p->texture[1].bpp, &p->texture[1].size_line, &p->texture[1].endian);
	p->texture[2].img = mlx_xpm_file_to_image(p->mlx, "./texture/2.xpm", &p->texture[2].width, &p->texture[2].height);
	p->texture[2].imgad = mlx_get_data_addr(p->texture[2].img, &p->texture[2].bpp, &p->texture[2].size_line, &p->texture[2].endian);
	p->texture[3].img = mlx_xpm_file_to_image(p->mlx, "./texture/3.xpm", &p->texture[3].width, &p->texture[3].height);
	p->texture[3].imgad = mlx_get_data_addr(p->texture[3].img, &p->texture[3].bpp, &p->texture[3].size_line, &p->texture[3].endian);
	generate_texture2(p);
}

void			wolf(t_param *p)
{
	init_values(p);
	if (p->option == 1)
		generate_texture(p);
	raycasting(p);
}
