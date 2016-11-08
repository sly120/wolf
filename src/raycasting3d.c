/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:28:40 by sly               #+#    #+#             */
/*   Updated: 2016/11/07 21:52:19 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			generate_texture(t_param *p)
{
	int			x;
	int			y;
	int			xorcolor;
	int			ycolor;
	int			xycolor;

	x = 0;
	y = 0;
	while (x < texwidth)
	{
		while (y < texheight)
		{
			xorcolor = (x * 256 / texwidth) ^ (y * 256 / texheight);
			ycolor = y * 256 / texheight;
			xycolor = x * 128 / texwidth + y * 128 / texheight;
			p->texture[0][texwidth * y + x] = 65536 * 254 * (x != y && x != texwidth - y); //flat red texture with black cross
			p->texture[1][texwidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			p->texture[2][texwidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			p->texture[3][texwidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			p->texture[4][texwidth * y + x] = 256 * xorcolor; //xor green
    		p->texture[5][texwidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    		p->texture[6][texwidth * y + x] = 65536 * ycolor; //red gradient
    		p->texture[7][texwidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
			y++;
		}
		x++;
	}
}

void			raycasting3d(t_param *p)
{
	generate_texture(p);
	raycasting3d2(p);
}
