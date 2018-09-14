/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 01:13:54 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/12 01:13:54 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RT_V1_H
# define RT_V1_H

# include <stdio.h>
# include <fcntl.h>
# include <get_next_line.h>

# include "SDL.h"
# include "libft.h"

enum e_object	{CAM, LIGHT, PLANE, SPHERE, CYLINDER, CONE};
enum e_xyz		{X, Y, Z};
enum e_render	{SOFTWARE, ACCELERATED};
enum e_pars		{SCENE, OBJECT, VAR};
enum e_error	{BROKEN, WORK};

# define DEF_SCREEN_WIDTH 1440
# define DEF_SCREEN_HEIGHT 840
# define ERROR_FD 1

typedef struct		s_v2i
{
	int32_t			x;
	int32_t			y;
}					t_v2i;

typedef struct		s_v2d
{
	double			x;
	double			y;
}					t_v2d;

typedef struct		s_v3i
{
	int32_t			x;
	int32_t			y;
	int32_t			z;
}					t_v3i;

typedef struct		s_v3d
{
	double			x;
	double			y;
	double			z;
}					t_v3d;

typedef struct		s_cam
{
	t_v3d			position;
	t_v2i			window_size;
	int8_t			render_flag;
}					t_cam;

typedef struct 		s_light
{
	t_v3d			position;
	SDL_Color		color;
}					t_light;

typedef struct		s_object
{
	int8_t			type;
	t_v3d			position;
	t_v3d			scale;
}					t_object;

typedef struct 		s_scene
{
	t_list			*head;
	t_cam			cam;
	t_light			**light;
	t_object		**object;
}					t_scene;

typedef struct		s_sdl
{
	SDL_Window		*winndow;
	SDL_Renderer	*render;
	SDL_Event		*event;
}					t_sdl;

typedef struct		s_master
{
	t_sdl			sdl;
	t_scene			scene;
}					t_master;

# endif