/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 01:14:03 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/12 01:14:04 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

int		main(int argc, char **argv)
{
	t_master	master;
	master.init_flag = START;
	master.error_flag = WORK;
	master.sdl.render = NULL;
	master.sdl.winndow = NULL;
	if (argc != 2)
		return (0);
	if (ft_parser(argv[1], &master) == BROKEN)
		ft_putendl_fd("\nInvalid file!\n", ERROR_FD);
	else
	{
		printf("WORK BITCH\n");
	}
	ft_end(&master.sdl);
//	system("leaks -q RT_V1_demo");
	return 0;
}
