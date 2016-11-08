/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:05:09 by sly               #+#    #+#             */
/*   Updated: 2016/11/01 20:34:43 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			hook(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	mlx_hook(p->win, 2, 1, key_event, p);
	mlx_hook(p->win, 17, 17, quit_program, p);
	mlx_loop(p->mlx);
}
