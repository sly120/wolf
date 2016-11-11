/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:56:25 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 19:15:21 by sly              ###   ########.fr       */
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

int					key_event(int key, t_param *p)
{
//	printf("key : %d\n", key);
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
	if (key == KEY_SHIFT)
		{
			if (p->duck == 0)
				p->duck = 70;
			else
				p->duck = 0;
		}
	raycasting(p);
	return (0);
}
