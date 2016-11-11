/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_calculation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 21:14:10 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 19:13:26 by sly              ###   ########.fr       */
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
	p->wallx -= floor((p->wallx));
	p->texx = (int)(p->wallx * (double)TEXWIDTH);
	if (p->side == 0 && p->raydirx > 0)
		p->texx = TEXWIDTH - p->texx - 1;
	if (p->side == 1 && p->raydiry < 0)
		p->texx = TEXWIDTH - p->texx - 1;
}
