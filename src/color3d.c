/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:21:36 by sly               #+#    #+#             */
/*   Updated: 2016/11/10 17:14:10 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			color3d(int x, t_param *p)
{
	int			y;
	int			color;
	int			d;
	int			texy;

	y = 0;
	while (y < MAX_Y)
	{
		if (y >= p->drawstart && y <= p->drawend)
		{
			d = y * 256 - MAX_Y * 128 + p->lineheight * 128;
			texy = d * texheight / p->lineheight / 256;
			color = p->texture[p->texnum][texheight * texy + p->texx];
			if (p->side == 1)
				color = color >> 1 & 8355711;
			p->imgad[p->sl * y + 4 * x] = color >> 16;
			p->imgad[p->sl * y + 4 * x + 1] = color >> 8;
			p->imgad[p->sl * y + 4 * x + 2] = color;
		}
		else
		{
			p->imgad[p->sl * y + 4 * x] = 0;
			p->imgad[p->sl * y + 4 * x + 1] = 0;
			p->imgad[p->sl * y + 4 * x + 2] = 0;
		}
		y++;
	}
//		p->buffer[y][x] = color;
}
