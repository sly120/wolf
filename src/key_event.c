/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:56:25 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 20:55:10 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			move_forward(t_param *p)
{
	if ((p->map)[(int)(p->posy)][(int)(p->posx + p->dirx * p->movespeed)] == 0)
		p->posx += p->dirx * p->movespeed;
	if ((p->map)[(int)(p->posy + p->diry * p->movespeed)][(int)(p->posx)] == 0)
		p->posy += p->diry * p->movespeed;
}

static void			move_backward(t_param *p)
{
	if ((p->map)[(int)(p->posy)][(int)(p->posx - p->dirx * p->movespeed)] == 0)
		p->posx -= p->dirx * p->movespeed;
	if ((p->map)[(int)(p->posy - p->diry * p->movespeed)][(int)(p->posx)] == 0)
		p->posy -= p->diry * p->movespeed;
}

static void			key_event2(int key, t_param *p)
{
	if (key == KEY_SHIFT)
	{
		if (p->duck == 0)
			p->duck = 70;
		else
			p->duck = 0;
		if (p->walk == 1)
			p->walk = 0.1;
	}
	if (key == KEY_ENTER)
	{
		if (p->light == 0)
			p->light = 0x00FFFFFF;
		else
			p->light = 0;
	}
	if (key == KEY_SPACE)
	{
		if (p->legend == 0)
			p->legend = 1;
		else
			p->legend = 0;
	}
}

int					key_event(int key, t_param *p)
{
	if (key == KEY_W)
		move_forward(p);
	if (key == KEY_S)
		move_backward(p);
	if (key == KEY_D || key == KEY_A)
		sidestep(key, p);
	if (key == KEY_ESC)
		quit_program(p);
	if (key == KEY_CRTL)
	{
		if (p->walk == 1)
			p->walk = 0.1;
		else
			p->walk = 1;
	}
	if (key == KEY_SHIFT || key == KEY_ENTER || key == KEY_SPACE)
		key_event2(key, p);
	raycasting(p);
	return (0);
}
