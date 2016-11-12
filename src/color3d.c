/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:21:36 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 19:37:36 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			color3d(int x, t_param *p)
{
	int			y;
	int			d;
	int			texy;

	y = -1;
	while (++y < MAX_Y)
	{
		if (y >= p->drawstart - p->duck && y <= p->drawend - p->duck)
		{
			d = (y + p->duck) * 256 - MAX_Y * 128 + p->lineheight * 128;
			texy = ((d * TEXHEIGHT) / p->lineheight) / 256;
			p->imgad[p->sl * y + 4 * x] = p->texture[p->texnum].
				imgad[p->texture[p->texnum].size_line * texy + 4 * p->texx];
			p->imgad[p->sl * y + 4 * x + 1] = p->texture[p->texnum].
				imgad[p->texture[p->texnum].size_line * texy + 4 * p->texx + 1];
			p->imgad[p->sl * y + 4 * x + 2] = p->texture[p->texnum].
				imgad[p->texture[p->texnum].size_line * texy + 4 * p->texx + 2];
		}
		else
		{
			p->imgad[p->sl * y + 4 * x] = p->light;
			p->imgad[p->sl * y + 4 * x + 1] = p->light >> 8;
			p->imgad[p->sl * y + 4 * x + 2] = p->light >> 16;
		}
	}
}
