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

uint 	ft_3rgb_to_int(int r, int g, int b)
{
	uint color;

	color = (uint)((r << 16) & 0xFF0000);
	color |= ((g << 8) & 0x00FF00);
	color |= ((b) & 0x0000FF);
	return (color);
}

void	ft_render(t_master *master)
{
	t_v3i i = {0,0,0};

	SDL_Surface *tmp = SDL_CreateRGBSurface(0, master->sdl.screen_size.x,
			master->sdl.screen_size.y, 32, 0, 0, 0, 0);
	uint *pixel = tmp->pixels;

/*
	i.y = master->sdl.screen_size.y;
	while (i.y >= 0)
	{
		i.x = 0;
		while (i.x < master->sdl.screen_size.x)
		{
			t_v3d col;
			col.x = (float)i.x / (float)master->sdl.screen_size.x;
			col.y = (float)i.y / (float)master->sdl.screen_size.y;
			col.z = 0.2;
			int ir = (int)(255.99 * col.x);
			int ig = (int)(255.99 * col.y);
			int ib = (int)(255.99 * col.z);
			uint color = ft_3rgb_to_int(ir, ig, ib);
			pixel[i.z++] = color;
			i.x++;
		}
		i.y--;
	}
*/ //заливка, чтобы посмотреть хоть на что-то :)


	SDL_Texture *texture = SDL_CreateTextureFromSurface(master->sdl.render, tmp);
	SDL_RenderCopy(master->sdl.render, texture, 0, 0);
	SDL_RenderPresent(master->sdl.render);
	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(texture);
}

int8_t	process(t_master *master)
{
	if (ft_init(&master->sdl) < 1)
		return (BROKEN);

	while (master->sdl.loop)
	{
		events(&master->sdl);
		ft_render(master);
	}
	return (WORK);
}
