/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 17:23:18 by sly               #+#    #+#             */
/*   Updated: 2016/11/08 19:18:07 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			init_values(t_param *p)
{
	p->option = 0;
	p->posx = 22.0;
	p->posy = 11.5;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0;
	p->planey = 0.66;
	p->walk = 1;
}

void			wolf(t_param *p)
{
	init_values(p);
	raycasting(p);
}
