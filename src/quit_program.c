/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sly <sly@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:35:10 by sly               #+#    #+#             */
/*   Updated: 2016/10/25 21:48:08 by sly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		quit_program(t_param *p)
{
	clFlush(p->command_queue);
	clFinish(p->command_queue);
	clReleaseKernel(p->kernel);
	clReleaseProgram(p->program);
	clReleaseMemObject(p->memobj);
	clReleaseCommandQueue(p->command_queue);
	clReleaseContext(p->context);
	free(p->source_str);
	free(p->map);
	exit(0);
}
