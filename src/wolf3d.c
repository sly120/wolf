/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:50:24 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 22:10:53 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

/*void			init_texture(t_param *p)
{
	int			**texture;
	int			y;

	if (!(p->texture = (int**)malloc(8 * sizeof(int*))))
		exit(1);
	y = 0;
	while (y < 8)
		if (!(p->texture[y++] = (int*)malloc(sizeof(int) * TEXWIDTH * TEXHEIGHT)))
			exit(1);
}

*/void			init_values3d(t_param *p)
{
	p->option = 1;
	p->posx = 22.0;
	p->posy = 11.5;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0;
	p->planey = 0.66;
	p->walk = 1;
//	init_texture(p);
//	p->buffer = init_buffer();
}
/*
void			generate_texture(t_param *p)
{
	int			x;
	int			y;
	int			xorcolor;
	int			ycolor;
	int			xycolor;

	x = 0;
	y = 0;
	while (x < TEXWIDTH)
	{
		while (y < TEXHEIGHT)
		{
			xorcolor = (x * 256 / TEXWIDTH) ^ (y * 256 / TEXHEIGHT);
			ycolor = y * 256 / TEXHEIGHT;
			xycolor = x * 128 / TEXWIDTH + y * 128 / TEXHEIGHT;
			p->texture[0][TEXWIDTH * y + x] = 0x00FF0000;
			p->texture[1][TEXWIDTH * y + x] = 0x00FF0000;
			p->texture[2][TEXWIDTH * y + x] = 0x00FF0000;
			p->texture[3][TEXWIDTH * y + x] = 0x00FF0000;
			p->texture[4][TEXWIDTH * y + x] = 0x00FF0000;
    		p->texture[5][TEXWIDTH * y + x] = 0x00FF0000;
    		p->texture[6][TEXWIDTH * y + x] = 0x00FF0000;
    		p->texture[7][TEXWIDTH * y + x] = 0x00FF0000;
			p->texture[0][TEXWIDTH * y + x] = 65536 * 254 * (x != y && x != TEXWIDTH - y); //flat red texture with black cross
			p->texture[1][TEXWIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			p->texture[2][TEXWIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			p->texture[3][TEXWIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			p->texture[4][TEXWIDTH * y + x] = 256 * xorcolor; //xor green
    		p->texture[5][TEXWIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    		p->texture[6][TEXWIDTH * y + x] = 65536 * ycolor; //red gradient
    		p->texture[7][TEXWIDTH * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
			y++;
		}
		x++;
	}
}*/

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

void			wolf3d(t_param *p)
{
	init_values3d(p);
	generate_texture(p);
	raycasting(p);
}
