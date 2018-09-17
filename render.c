//
// Created by Igor STALEVSKIY on 9/17/18.
//

#include "rt_v1.h"

void	events(t_sdl *sdl)
{
	SDL_PollEvent(&sdl->event);
	if (sdl->event.type == SDL_QUIT)
		sdl->loop = BROKEN;
	if (sdl->event.key.keysym.sym == SDLK_ESCAPE)
		sdl->loop = BROKEN;
}

int8_t	render(t_master *master)
{
	if (ft_init(&master->sdl) < 1)
		return (BROKEN);
	while (master->sdl.loop)
	{
		events(&master->sdl);
	}
	return (WORK);
}
