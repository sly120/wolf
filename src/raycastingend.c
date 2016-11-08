/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastingend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:24:02 by sly               #+#    #+#             */
/*   Updated: 2016/11/08 21:51:54 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		texture_calculation(t_param *p)
{
	p->texnum = p->map[p->mapy][p->mapx] - 1;
	if (p->side == 0)
		p->wallx = p->rayposy + p->perpwalldist * p->raydiry;
	else
		p->wallx = p->rayposx + p->perpwalldist * p->raydirx;
	p->wallx -= floor(p->wallx);
	p->texx = (int)(p->wallx * (double)texwidth);
	if (p->side == 0 && p->raydirx > 0)
		p->texx = texwidth - p->texx - 1;
	if (p->side == 1 && p->raydiry < 0)
		p->texx = texwidth - p->texx - 1;
}

void		raycastingend(t_param *p)
{
	if (p->option == 1)
		texture_calculation(p);
	manage_time(p);
	hook(p);
}
