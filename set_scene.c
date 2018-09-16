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

static void		ft_name(char **current, t_master *master, int16_t *init_flag)
{
	ft_current_step(current, "name");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		master->sdl.win_name = get_word(*current);
		ft_current_step(current, master->sdl.win_name);
		if (**current == '}')
		{
			ft_current_step(current, NULL);
			*init_flag |= SET_NAME;
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void		ft_window(char **current, t_master *master, int16_t *init_flag)
{
	ft_current_step(current, "window");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		set_window(current, master);
		if (**current == '}')
		{
			*init_flag |= SET_WINDOWS;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void		ft_render(char **current, t_master *master, int16_t *init_flag)
{
	ft_current_step(current, "render");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		master->sdl.render_flag = set_render(current);
		if (**current == '}' && master->sdl.render_flag >= 0)
		{
			*init_flag |= SET_RENDER;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void		pars_scene(char **current, t_master *master)
{
	int16_t i;

	master->init_flag = 0;
	i = 0;
	*current = find(*current);
	while (i < MAXBASE && master->error_flag)
	{
		if (!(master->init_flag & SET_NAME)
			&& ft_strstr(*current, "name") == *current)
			ft_name(current, master, &master->init_flag);
		else if (!(master->init_flag & SET_WINDOWS)
			&& ft_strstr(*current, "window") == *current)
			ft_window(current, master, &master->init_flag);
		else if (!(master->init_flag & SET_RENDER)
			&& ft_strstr(*current, "render") == *current)
			ft_render(current, master, &master->init_flag);
		i++;
	}
	if (!(master->init_flag & (SET_NAME | SET_WINDOWS | SET_RENDER)))
		master->error_flag = BROKEN;
}

int8_t			find_scene(char **current, char *needle, t_master *master)
{
	if (ft_strstr(*current, needle))
	{
		*current += ft_strlen(needle);
		*current = find(*current);
		if (**current != '{')
			return (-1);
		else
			(*current)++;
		pars_scene(current, master);
	}
	else
		master->error_flag = BROKEN;
	if (!master->error_flag)
		return (-1);
	return (WORK);
}
