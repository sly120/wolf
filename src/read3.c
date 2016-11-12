/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:23:57 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 19:25:11 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int				**createtab(t_param *p)
{
	int			y;
	int			**tab;

	if (!(tab = (int**)malloc(sizeof(int*) * p->tableny)))
		exit(1);
	y = 0;
	while (y < p->tableny)
		if (!(tab[y++] = (int*)malloc(sizeof(int) * p->tablenx)))
			exit(1);
	return (tab);
}
