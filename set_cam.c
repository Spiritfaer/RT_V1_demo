/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 08:03:12 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/16 08:03:13 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

static void	ft_set_cam_rotate(char **current, t_master *master, int16_t *init)
{
	ft_current_step(current, "rotate");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		ft_set_v3d(current, &master->scene.cam.rotate);
		if (**current == '}')
		{
			*init |= ROT;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void	ft_set_cam_position(char **current, t_master *master, int16_t *init)
{
	ft_current_step(current, "position");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		ft_set_v3d(current, &master->scene.cam.position);
		if (**current == '}')
		{
			*init |= POS;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void	ft_camera(char **current, t_master *master)
{
	int8_t	i;
	int16_t	*flag;

	i = 3;
	flag = &master->scene.cam.init_flag;
	ft_current_step(current, "camera");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		while (i-- && master->error_flag)
		{
			if (!(*flag & POS) && ft_strstr(*current, "position") == *current)
				ft_set_cam_position(current, master, flag);
			else if (!(*flag & ROT) && ft_strstr(*current, "rotate") == *current)
				ft_set_cam_rotate(current, master, flag);
			else if (*flag & (POS | ROT) && **current == '}'
				&& ft_current_step(current, NULL))
				return ;
			else
				master->error_flag = BROKEN;
		}
	}
	else
		master->error_flag = BROKEN;
}
