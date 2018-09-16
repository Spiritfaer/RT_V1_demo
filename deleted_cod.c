#include "rt_v1.h"

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

uint8_t		set_position(t_master *master, char **split, uint16_t *i)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{") && master->error_flag)
	{
		master->scene.cam.position.x = atof(*(split + ++(*i)));
		master->scene.cam.position.y = atof(*(split + ++(*i)));
		master->scene.cam.position.z = atof(*(split + ++(*i)));
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
			return (WORK);
	}
	return (BROKEN);
}

uint8_t		set_rotate(t_master *master, char **split, uint16_t *i)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{") && master->error_flag)
	{
		master->scene.cam.rotate.x = atof(*(split + ++(*i)));
		master->scene.cam.rotate.y = atof(*(split + ++(*i)));
		master->scene.cam.rotate.z = atof(*(split + ++(*i)));
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
			return (WORK);
	}
	return (BROKEN);
}

uint8_t		set_light_color(t_light *light, char **split, uint16_t *i)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{"))
	{
		light->color.r = (uint8_t)atoi(*(split + ++(*i)));
		light->color.g = (uint8_t)atoi(*(split + ++(*i)));
		light->color.b = (uint8_t)atoi(*(split + ++(*i)));
		light->color.a = 0;
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
			return (WORK);
	}
	return (BROKEN);
}

uint8_t		set_light_position(t_light *light, char **split, uint16_t *i)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{"))
	{
		light->position.x = atof(*(split + ++(*i)));
		light->position.y = atof(*(split + ++(*i)));
		light->position.z = atof(*(split + ++(*i)));
		if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}"))
			return (WORK);
	}
	return (BROKEN);
}

void		set_camera(t_master *master, char **split, uint16_t *i, int8_t	*flag)
{
	if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "position") && master->error_flag)
	{
		master->error_flag = set_position(master, split, i);
		return ;
	}
	else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "rotate") && master->error_flag)
	{
		master->error_flag = set_rotate(master, split, i);
		return ;
	}
	else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "}") && master->error_flag)
		*flag = -1;
}

t_light		*get_last_light(t_scene *scene)
{
	t_light *last;

	last = scene->light;
	if (last)
	{
		while (last->next)
			last = last->next;
	}
	return (last);
}

void		set_light(t_master *master, char **split, uint16_t *i, int8_t	*flag)
{
	if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "position") && master->error_flag)
	{
		master->error_flag = set_light_position(get_last_light(&master->scene), split, i);
		return ;
	}
	else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "color") && master->error_flag)
	{
		master->error_flag = set_light_color(get_last_light(&master->scene), split, i);
		return ;
	}
	else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "}") && master->error_flag)
		*flag = -1;
}

void	get_light(t_light **head)
{
	t_light *back;
	t_light *light;

	if (!head)
		return ;
	if (!(*head))
	{
		light = (t_light*)malloc(sizeof(t_light));
		ft_bzero(light, sizeof(t_light));
		(*head) = light;
	}
	else
	{
		back = (*head);
		while (back->next)
			back = back->next;
		back->next = (t_light*)malloc(sizeof(t_light));
		ft_bzero(back->next, sizeof(t_light));
	}
}

void		ft_set_object(t_master *master, char **split, uint16_t *i)
{
	static int8_t	flag = -1;

	if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "camera")) || flag == CAM)
	{
		if (flag != CAM && (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{")))
			flag = CAM;
		else if (flag == CAM)
			set_camera(master, split, i, &flag);
	}
	else if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "light")) || flag == LIGHT)
	{
		if (flag != LIGHT && (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{")))
		{
			flag = LIGHT;
			get_light(&master->scene.light);
		}
		else if (flag == LIGHT)
			set_light(master, split, i, &flag);
	}
	else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "object"))
		master->init_flag = SHAPE;
	else if (flag == -1)
		master->error_flag = BROKEN;
}

void		ft_set_shape(t_master *master, char **split, uint16_t *i)
{
	printf("SHAPE------------------\n");
	master->error_flag = BROKEN;
	static int8_t	flag = -1;
	printf("=======%s======\n", split[*i]);

}