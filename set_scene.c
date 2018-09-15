/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 12:43:34 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/15 12:43:34 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

uint8_t		ft_set_name(t_master *master, char **split, uint16_t *i)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{"))
	{
		if (*(split + ++(*i)))
			master->sdl.win_name = ft_strdup(*(split + (*i)));
		else if (!ft_strcmp(*(split + (*i)), "}"))
		{
			master->sdl.win_name = ft_strdup("Default name");
			(*i)++;
			return (WORK);
		}
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
			return (WORK);
	}
	master->error_flag = BROKEN;
	return (BROKEN);
}

uint8_t		ft_set_win(t_master *master, char **split, uint16_t *i)
{
	int32_t	tmp;

	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{"))
	{
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
		{
			master->sdl.screen_width = MIN_SCREEN_WIDTH;
			master->sdl.screen_height = MIN_SCREEN_HEIGHT;
		}
		else
		{
			if (*(split + (*i)))
			{
				tmp = (uint16_t)ft_atoi(*(split + (*i)));
				master->sdl.screen_width = (tmp > 640) ? (uint16_t)ft_atoi(*(split + (*i))) : MIN_SCREEN_WIDTH;
				(*i)++;
			}
			if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "}"))
				master->sdl.screen_height = MIN_SCREEN_HEIGHT;
			else if (*(split + (*i)))
			{
				tmp = (uint16_t) ft_atoi(*(split + (*i)));
				master->sdl.screen_height = (tmp > 480) ? (uint16_t)ft_atoi(*(split + (*i))) : MIN_SCREEN_WIDTH;
				(*i)++;
				if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "}"))
					return (WORK);
			}
		}
	}
	master->error_flag = BROKEN;
	return (BROKEN);
}


uint8_t		ft_set_render(t_master *master, char **split, uint16_t *i)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{"))
	{
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "accelerated"))
		{
			master->sdl.render_flag = ACCELERATED;
			if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
				return (WORK);
		}
		else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "software"))
			master->sdl.render_flag = SOFTWARE;
		else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "}"))
		{
			master->sdl.render_flag = SOFTWARE;
			return (WORK);
		}
		else if (*(split + (*i)) && ft_strcmp(*(split + (*i)), "}"))
		{
			master->sdl.render_flag = SOFTWARE;
			master->error_flag = BROKEN;
			return (BROKEN);
		}
	}
	master->error_flag = BROKEN;
	return (BROKEN);
}

void 		ft_set_scene(t_master *master, char **split, uint16_t *i)
{
	static uint8_t	set[MAXBASE] = {0, 0, 0};

	if (master->error_flag == WORK)
	{
		if (!ft_strcmp(*split, "name"))
			set[NAME] = ft_set_name(master, split, i);
		else if (!ft_strcmp(*split, "window"))
			set[WINDOW] = ft_set_win(master, split, i);
		else if (!ft_strcmp(*split, "render"))
			set[RENDER] = ft_set_render(master, split, i);
	}
	if (ft_check_set_scene(set) == WORK)
		master->init_flag = OBJECT;
}

void		ft_set_base(t_master *master, char *split)
{
	static int8_t braket = 0;
	if (!ft_strcmp(split, "scene") && !braket)
		braket = 1;
	else if (!ft_strcmp(split, "{") && braket++)
		master->init_flag = SCENE;
	else if (master->init_flag == OBJECT && !ft_strcmp(split, "}") && braket == 2)
		return ;
	else
		master->error_flag = BROKEN;
}
