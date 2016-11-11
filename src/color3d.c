/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:21:36 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 21:28:25 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			color3d(int x, t_param *p)
{
	int			y;
//	int			color;
	int			d;
	int			texy;

	y = 0;
	while (y < MAX_Y)
	{
		if (y >= p->drawstart - p->duck && y <= p->drawend - p->duck)
		{
			d = y * 256 - MAX_Y * 128 + p->lineheight * 128;
			texy = ((d * TEXHEIGHT) / p->lineheight) / 256;
//			color = p->texture[0].imgad[p->texture[0].size_line * texy + p->texx];
//			if (p->side == 1)
//				color = (color >> 1) & 8355711;
			p->imgad[p->sl * y + 4 * x] = p->texture[0].imgad[p->texture[0].size_line * texy + p->texx];//color;
			p->imgad[p->sl * y + 4 * x + 1] = p->texture[0].imgad[p->texture[0].size_line * texy + p->texx + 1];// color >> 8;
			p->imgad[p->sl * y + 4 * x + 2] = p->texture[0].imgad[p->texture[0].size_line * texy + p->texx + 2];// color >> 16;
		}
		else
		{
			p->imgad[p->sl * y + 4 * x] = p->light;
			p->imgad[p->sl * y + 4 * x + 1] = p->light >> 8;
			p->imgad[p->sl * y + 4 * x + 2] = p->light >> 16;
		}
		y++;
	}
//		p->buffer[y][x] = color;
}
