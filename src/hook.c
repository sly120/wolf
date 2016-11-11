/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:05:09 by sly               #+#    #+#             */
/*   Updated: 2016/11/11 17:45:22 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int				turn(int x, int y, t_param *p)
{
	double		rotation;

	if (x - p->mousex < 0)
		rotation = p->rotspeed;
	else
		rotation = -p->rotspeed;
	p->mousex = x;
//	printf("%d\n", x);
	p->olddirx = p->dirx;
	p->dirx = p->dirx * cos(rotation) - p->diry * sin(rotation);
	p->diry = p->olddirx * sin(rotation) + p->diry * cos(rotation);
	p->oldplanex = p->planex;
	p->planex = p->planex * cos(rotation) - p->planey * sin(rotation);
	p->planey = p->oldplanex * sin(rotation) + p->planey * cos(rotation);
	raycasting(p);
	return (0);
}

void			hook(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_hook(p->win, 2, 1, key_event, p);
	mlx_hook(p->win, 17, 17, quit_program, p);
	mlx_hook(p->win, MOTIONNOTIFY, POINTERMOTIONMASK, turn, p);
	mlx_loop(p->mlx);
}
