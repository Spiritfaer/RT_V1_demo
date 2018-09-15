/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:24:25 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/14 22:24:26 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	STRUCT_H
# define STRUCT_H

# include <stdio.h>
# include <fcntl.h>
# include <get_next_line.h>

# include "SDL.h"
# include "libft.h"

enum e_object	{CAM, LIGHT, PLANE, SPHERE, CYLINDER, CONE, MAXOBJ};
enum e_base		{NAME, WINDOW, RENDER, MAXBASE};
enum e_xyz		{X, Y, Z};
enum e_render	{SOFTWARE, ACCELERATED};
enum e_pars		{START, SCENE, OBJECT, END};
enum e_error	{BROKEN, WORK};

# define MAX_SCREEN_WIDTH 1440
# define MIN_SCREEN_WIDTH 640
# define MAX_SCREEN_HEIGHT 840
# define MIN_SCREEN_HEIGHT 480
# define ERROR_FD 1
# define POS 1
# define ROT 2
# define COL 4
# define SCA 8

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
	t_v3d			rotate;
	t_v2i			window_size;
	int8_t			render_flag;
}					t_cam;

typedef struct 		s_light
{
	t_v3d			position;
	SDL_Color		color;
	struct s_light	*next;
}					t_light;

typedef struct		s_object
{
	int8_t			type;
	t_v3d			position;
	t_v3d			scale;
	SDL_Color		color;
	struct s_object	*next;
}					t_object;

typedef struct 		s_scene
{
	t_list			*head;
	t_cam			cam;
	t_light			*light;
	t_object		*object;
}					t_scene;

typedef struct		s_sdl
{
	SDL_Window		*winndow;
	SDL_Renderer	*render;
	SDL_Event		event;
	char			*win_name;
	int32_t			screen_width;
	int32_t			screen_height;
	uint8_t			render_flag;
}					t_sdl;

typedef struct		s_master
{
	t_sdl			sdl;
	t_scene			scene;
	int8_t			init_flag;
	uint8_t			error_flag;
}					t_master;

# endif
