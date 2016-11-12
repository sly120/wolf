/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:51:41 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 19:39:17 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void		drawvertline(int x, int color, t_param *p)
{
	int			y;

	y = 0;
	while (y < MAX_Y)
	{
		if (y >= p->drawstart - p->duck && y <= p->drawend - p->duck)
		{
			p->imgad[p->sl * y + 4 * x] = color;
			p->imgad[p->sl * y + 4 * x + 1] = color >> 8;
			p->imgad[p->sl * y + 4 * x + 2] = color >> 16;
		}
		else
		{
			p->imgad[p->sl * y + 4 * x] = p->light;
			p->imgad[p->sl * y + 4 * x + 1] = p->light >> 8;
			p->imgad[p->sl * y + 4 * x + 2] = p->light >> 16;
		}
		y++;
	}
}

void			color(int x, t_param *p)
{
	int			color;

	if (p->map[p->mapy][p->mapx] == 1)
		color = 0x00FF0000;
	else if (p->map[p->mapy][p->mapx] == 2)
		color = 0x0000FF00;
	else if (p->map[p->mapy][p->mapx] == 3)
		color = 0x000000FF;
	else if (p->map[p->mapy][p->mapx] == 4)
		color = 0x00FFFFFF;
	else
		color = 0x00FFD700;
	if (p->side == 1)
		color /= 2;
	drawvertline(x, color, p);
}
