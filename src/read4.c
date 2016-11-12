/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:25:20 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 19:25:52 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

char			*copy_src(char *src, int size)
{
	char		*mapstr;
	int			fd;

	if ((fd = open(src, O_RDONLY)) == -1)
		exit(1);
	if (!(mapstr = (char*)malloc(sizeof(char) * (size + 1))))
		exit(1);
	read(fd, mapstr, size);
	mapstr[size] = '\0';
	close(fd);
	return (mapstr);
}
