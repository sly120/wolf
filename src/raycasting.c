/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 19:35:55 by sly               #+#    #+#             */
/*   Updated: 2016/11/07 21:49:48 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			raycasting_part1(int x, t_param *p)
{
	p->camerax = 2 * x / (double)MAX_X - 1;
	p->rayposx = p->posx;
	p->rayposy = p->posy;
	p->raydirx = p->dirx + p->planex * p->camerax;
	p->raydiry = p->diry + p->planey * p->camerax;
	p->mapx = (int)p->rayposx;
	p->mapy = (int)p->rayposy;
	p->deltadistx =
		sqrt(1 + (p->raydiry * p->raydiry) / (p->raydirx * p->raydirx));
	p->deltadisty =
		sqrt(1 + (p->raydirx * p->raydirx) / (p->raydiry * p->raydiry));
	p->hit = 0;
}

static void			raycasting_part2(t_param *p)
{
	if (p->raydirx < 0)
	{
		p->stepx = -1;
		p->sidedistx = (p->rayposx - p->mapx) * p->deltadistx;
	}
	else
	{
		p->stepx = 1;
		p->sidedistx = (1.0 - p->rayposx + p->mapx) * p->deltadistx;
	}
	if (p->raydiry < 0)
	{
		p->stepy = -1;
		p->sidedisty = (p->rayposy - p->mapy) * p->deltadisty;
	}
	else
	{
		p->stepy = 1;
		p->sidedisty = (1.0 - p->rayposy + p->mapy) * p->deltadisty;
	}
}

static void			raycasting_part3(t_param *p)
{
	while (p->hit == 0)
	{
		if (p->sidedistx < p->sidedisty)
		{
			p->sidedistx += p->deltadistx;
			p->mapx += p->stepx;
			p->side = 0;
		}
		else
		{
			p->sidedisty += p->deltadisty;
			p->mapy += p->stepy;
			p->side = 1;
		}
		if ((p->map)[p->mapy][p->mapx] > 0)
			p->hit = 1;
	}
}

static void			raycasting_part4(t_param *p)
{
	if (p->side == 0)
		p->perpwalldist =
			(p->mapx - p->rayposx + (1 - p->stepx) / 2) / p->raydirx;
	else
		p->perpwalldist =
			(p->mapy - p->rayposy + (1 - p->stepy) / 2) / p->raydiry;
	p->lineheight = (int)(MAX_Y / p->perpwalldist);
	p->drawstart = -(p->lineheight) / 2 + MAX_Y / 2;
	if (p->drawstart < 0)
		p->drawstart = 0;
	p->drawend = p->lineheight / 2 + MAX_Y / 2;
	if (p->drawend >= MAX_Y)
		p->drawend = MAX_Y - 1;
}

void			raycasting(t_param *p)
{
	int			x;

	x = 0;
	while (x < MAX_X)
	{
		raycasting_part1(x, p);
		raycasting_part2(p);
		raycasting_part3(p);
		raycasting_part4(p);
		color(x, p);
		x++;
	}
	manage_time(p);
	hook(p);
}
