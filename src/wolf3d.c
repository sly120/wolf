/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 19:50:24 by sly               #+#    #+#             */
/*   Updated: 2016/11/10 17:14:49 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

/*long			**init_buffer(void)
{
	long		**buffer;
	int			y;
	int			x;

	if (!(buffer = (long**)malloc(MAX_Y * sizeof(long*))))
		exit(1);
	y = 0;
	while (y < MAX_Y)
		if (!(buffer[y++] = (long*)malloc(sizeof(long) * MAX_X)))
			exit(1);
	y = 0;
	while (y < MAX_Y)
	{
		x = 0;
		while (x < MAX_X)
			buffer[y][x++] = (long)0;
		y++;
	}
	return (buffer);
}
*/
int				**init_texture(void)
{
	int			**texture;
	int			y;

	if (!(texture = (int**)malloc(8 * sizeof(int*))))
		exit(1);
	y = 0;
	while (y < 8)
		if (!(texture[y++] = (int*)malloc(sizeof(int) * texwidth * texheight)))
			exit(1);
	return (texture);
}

void			init_values3d(t_param *p)
{
	p->option = 1;
	p->posx = 22.0;
	p->posy = 11.5;
	p->dirx = -1.0;
	p->diry = 0.0;
	p->planex = 0;
	p->planey = 0.66;
	p->walk = 1;
	p->texture = init_texture();
//	p->buffer = init_buffer();
}

void			wolf3d(t_param *p)
{
	init_values3d(p);
	raycasting3d(p);
}
