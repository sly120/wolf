/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:50:24 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 21:06:18 by sly              ###   ########.fr       */
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

void			init_values3d(t_param *p)
{
	p->option = 1;
	p->posx = 22.0;
	p->posy = 11.5;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0;
	p->planey = 0.66;
	p->walk = 1;
	init_texture(p);
//	p->buffer = init_buffer();
}

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

void			generate_texture(t_param *p)
{
	if (!(p->texture[0].img = mlx_xpm_file_to_image(p->mlx, "./texture/mur.xpm", &p->texture[0].width, &p->texture[0].height)))
		exit(1);
	p->texture[0].imgad = mlx_get_data_addr(p->texture[0].img, &p->texture[0].bpp, &p->texture[0].size_line, &p->texture[0].endian);
}

void			wolf3d(t_param *p)
{
//	init_values3d(p);
	generate_texture(p);
	raycasting(p);
}
