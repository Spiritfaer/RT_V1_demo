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

static void	ft_name(char **current, t_master *master, int16_t *init_flag)
{
	*current += ft_strlen("name");
	*current = find(*current);
	if (**current == '{')
	{
		(*current)++;
		*current = find(*current);
		master->sdl.win_name = get_word(*current);
//		printf("%s\n", master->sdl.win_name);
		*current += ft_strlen(master->sdl.win_name);
		*current = find(*current);
		if (**current == '}')
		{
			(*current)++;
			*current = find(*current);
			*init_flag |= SET_NAME;
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void ft_window(char **current, t_master *master, int16_t *init_flag)
{
	*current += ft_strlen("window");
	*current = find(*current);
	if (**current == '{')
	{
		(*current)++;
		*current = find(*current);
		set_window(current, master);
//		printf("width = %d\nheight = %d\n", master->scene.cam.window_size.x,
//				master->scene.cam.window_size.y);
		if (**current == '}')
		{
			*init_flag |= SET_WINDOWS;
			(*current)++;
			*current = find(*current);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void ft_render(char **current, t_master *master, int16_t *init_flag)
{
	*current += ft_strlen("render");
	*current = find(*current);
	if (**current == '{')
	{
		(*current)++;
		*current = find(*current);
		master->sdl.render_flag = set_render(current);
//		printf("%d\n", master->sdl.render_flag);
		if (**current == '}')
		{
			*init_flag |= SET_RENDER;
			(*current)++;
			*current = find(*current);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void	pars_scene(char **current, t_master *master)
{
	int16_t init_flag = 0;
	int16_t i = 0;
	*current = find(*current);
	while (i < MAXBASE && master->error_flag)
	{
		if (!(init_flag & SET_NAME)
			&& ft_strstr(*current, "name") == *current)
			ft_name(current, master, &init_flag);
		else if (!(init_flag & SET_WINDOWS)
			&& ft_strstr(*current, "window") == *current)
			ft_window(current, master, &init_flag);
		else if (!(init_flag & SET_RENDER)
			&& ft_strstr(*current, "render") == *current)
			ft_render(current, master, &init_flag);
		i++;
	}
	if (!(init_flag & (SET_NAME | SET_WINDOWS | SET_RENDER)))
		master->error_flag = BROKEN;
}
