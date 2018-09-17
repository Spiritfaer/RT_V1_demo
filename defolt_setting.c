//
// Created by Igor STALEVSKIY on 9/17/18.
//

#include "rt_v1.h"

void	defolt_master (t_master *master)
{
	master->init_flag = START;
	master->error_flag = WORK;
	ft_bzero(&master->scene, sizeof(master->scene));
	ft_bzero(&master->sdl, sizeof(master->sdl));
}
