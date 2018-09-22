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

void	print_test(t_master *master)
{
	printf("win_name >%s<\n", master->sdl.win_name);
	printf("win_size %d %d\n", master->sdl.screen_size.x, master->sdl.screen_size.y);
	if (master->sdl.render_flag == ACCELERATED)
		printf("render_type = \"ACCELERATED\"\n");
	else if (master->sdl.render_flag == SOFTWARE)
		printf("render_type = \"SOFTWARE\"\n");
	else
		printf("render_type = \"WTF?!\"\n");
	if (master->init_flag & SET_CAMERA)
		printf("camera was set\n");
	else
		printf("camera wasn't set\n");
	if (master->init_flag & SET_LIGHT)
		printf("light was set\n");
	else
		printf("light wasn't set\n");
	if (master->init_flag & SET_OBJECTS)
		printf("objects was set\n");
	else
		printf("objects wasn't set\n");
}

int		main(int argc, char **argv)
{
	t_master	master;
	defolt_master(&master);
	if (argc != 2)
		return (0);
	if (ft_parser(argv[1], &master) == BROKEN)
		ft_putendl_fd("\nInvalid file!\n", ERROR_FD);
	else
	{
		print_test(&master);
		process(&master);
		printf("\nWORK BITCH\n\n");
	}
	ft_end(&master.sdl);
	system("leaks -q RT_V1_demo");
	return 0;
}
