/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:56:25 by sly               #+#    #+#             */
/*   Updated: 2016/10/27 15:57:16 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			move_forward(t_param *p)
{
	if ((p->map)[(int)(p->posy)][(int)(p->posx + p->dirx * p->movespeed)] == 0)
		p->posx += p->dirx * p->movespeed;
	if ((p->map)[(int)(p->posy + p->diry * p->movespeed)][(int)(p->posx)] == 0)
		p->posy += p->diry * p->movespeed;
}

void			move_backward(t_param *p)
{
	if ((p->map)[(int)(p->posy)][(int)(p->posx - p->dirx * p->movespeed)] == 0)
		p->posx -= p->dirx * p->movespeed;
	if ((p->map)[(int)(p->posy - p->diry * p->movespeed)][(int)(p->posx)] == 0)
		p->posy -= p->diry * p->movespeed;
}

void			rotate_right(t_param *p)
{
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(-(p->rotspeed)) - p->diry * sin(-(p->rotspeed));
	p->diry = p->olddirx * sin(-(p->rotspeed)) + p->diry * cos(-(p->rotspeed));
	p->oldplanex = p->planex;
	p->planex = p->planex * cos(-(p->rotspeed))
		- p->planey * sin(-(p->rotspeed));
	p->planey = p->oldplanex * sin(-(p->rotspeed))
		+ p->planey * cos(-(p->rotspeed));
}

void			rotate_left(t_param *p)
{
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(p->rotspeed) - p->diry * sin(p->rotspeed);
	p->diry = p->olddirx * sin(p->rotspeed) + p->diry * cos(p->rotspeed);
	p->oldplanex = p->planex;
	p->planex = p->planex * cos(p->rotspeed) - p->planey * sin(p->rotspeed);
	p->planey = p->oldplanex * sin(p->rotspeed) + p->planey * cos(p->rotspeed);
}

int				key_event(int key, t_param *p)
{
//	printf("key : %d\n", key);
	if (key == KEY_W)
		move_forward(p);
	if (key == KEY_S)
		move_backward(p);
	if (key == KEY_D)
		rotate_right(p);
	if (key == KEY_A)
		rotate_left(p);
	if (key == KEY_ESC)
		quit_program(p);
	if (key == KEY_CRTL)
	{
		if (p->walk == 1)
			p->walk = 0.1;
		else
			p->walk = 1;
	}
	raycasting(p);
	return (0);
}
