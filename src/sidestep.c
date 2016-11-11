/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sidestep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:21:58 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 18:41:56 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			rotate_right(t_param *p)
{
	p->olddirx = p->dirx;
	p->dirx = p->diry;
	p->diry = -p->olddirx;
	p->oldplanex = p->planex;
	p->planex = p->planey;
	p->planey = -p->oldplanex;
}

static void			rotate_left(t_param *p)
{
	p->olddirx = p->dirx;
	p->dirx = -p->diry;
	p->diry = p->olddirx;
	p->oldplanex = p->planex;
	p->planex = -p->planey;
	p->planey = p->oldplanex;
}

static void			move_forward(t_param *p)
{
	if ((p->map)[(int)(p->posy)][(int)(p->posx + p->dirx * p->movespeed)] == 0)
		p->posx += p->dirx * p->movespeed;
	if ((p->map)[(int)(p->posy + p->diry * p->movespeed)][(int)(p->posx)] == 0)
		p->posy += p->diry * p->movespeed;
}

void				sidestep(int key, t_param *p)
{
	if (key == KEY_D)
	{
		rotate_right(p);
		move_forward(p);
		rotate_left(p);
	}
	else
	{
		rotate_left(p);
		move_forward(p);
		rotate_right(p);
	}
}
