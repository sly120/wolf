/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:21:36 by sly               #+#    #+#             */
/*   Updated: 2016/11/08 21:52:04 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			color3d(int x, t_param *p)
{
	int			y;
	int			color;
	int			d;
	int			texy;

	y = p->drawstart;
	while (y < p->drawstart)
	{
		d = y * 256 - MAX_Y * 128 + p->lineheight * 128;
		texy = d * texheight / p->lineheight / 256;
		color = p->texture[p->texnum][texheight * texy + p->texx];
		if (p->side == 1)
			color = color >> 1 & 8355711;
		p->buffer[y][x] = color;
		y++;
	}
}
