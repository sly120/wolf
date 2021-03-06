/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 12:26:10 by sly               #+#    #+#             */
/*   Updated: 2016/11/12 19:25:50 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int				open_file(char *file)
{
	int			fd;
	int			ret;
	int			total;
	char		c;

	if ((fd = open(file, O_RDONLY)) == -1)
		exit(1);
	total = 0;
	ret = 1;
	while (ret)
	{
		if ((ret = read(fd, &c, 1)) == -1)
			exit(1);
		if (!(ft_isdigit(c) || c == '\n' || c == '\0' || c == '-' || c == ' '))
			exit(1);
		total++;
	}
	close(fd);
	return (total);
}
