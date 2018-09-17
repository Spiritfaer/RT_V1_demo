/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:19:18 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/14 22:19:18 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int8_t	ft_init(t_sdl *sdl)
{
	int8_t		result;
	uint32_t	render_flags;

	result = WORK;
	sdl->loop = WORK;
	render_flags = 0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 && result--)
		ft_putendl_fd(SDL_GetError(), 2);
	else
	{
		sdl->winndow = SDL_CreateWindow(sdl->win_name, 150, 150,
			sdl->screen_size.x, sdl->screen_size.y, SDL_WINDOW_SHOWN);
		if (!sdl->winndow && result--)
			ft_putendl_fd(SDL_GetError(), 2);
		else
		{
			render_flags &= (sdl->render_flag) ? SDL_RENDERER_ACCELERATED : SDL_RENDERER_SOFTWARE;
			render_flags |= SDL_RENDERER_PRESENTVSYNC;
			sdl->render = SDL_CreateRenderer(sdl->winndow, -1, render_flags);
			if (!sdl->render && result--)
				ft_putendl_fd(SDL_GetError(), 2);
		}
	}
	return (result);
}

void	ft_end(t_sdl *sdl)
{
	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->winndow)
		SDL_DestroyWindow(sdl->winndow);
	SDL_Quit();
}