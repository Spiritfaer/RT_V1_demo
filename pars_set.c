//
// Created by Igor STALEVSKIY on 9/16/18.
//

#include "rt_v1.h"

int8_t set_render(char **current)
{
	if (ft_strstr(*current, "accelerated") == *current)
	{
		ft_current_step(current, "accelerated");
		return (ACCELERATED);
	}
	else if (ft_strstr(*current, "software") == *current)
	{
		ft_current_step(current, "software");
		return (SOFTWARE);
	}
	return (-1);
}

void	set_window(char **current, t_master *master)
{
	char *width;
	char *height;

	width = get_word(*current);
	ft_current_step(current, width);
	height = get_word(*current);
	ft_current_step(current, height);
	master->sdl.screen_size.x = ft_atoi(width);
	master->sdl.screen_size.y = ft_atoi(height);
	free(width);
	free(height);
}

void	ft_set_v3d(char **current, t_v3d *vector)
{
	char	*str_vec[VECTOR + 1];
	int8_t	i;

	i = -1;
	while (++i < VECTOR)
	{
		str_vec[i] = get_word(*current);
		ft_current_step(current, str_vec[i]);
	}
	vector->x = atof(str_vec[X]);
	vector->y = atof(str_vec[Y]);
	vector->z = atof(str_vec[Z]);
	i = -1;
	while (++i < VECTOR)
		free(str_vec[i]);
}

int8_t	ft_current_step(char **current, char *str)
{
	if (!str)
		(*current)++;
	else
		*current += ft_strlen(str);
	*current = find(*current);
	return (1);
}

void	ft_set_col(char **current, SDL_Color *color)
{
	char	*str_col[RGBA + 1];
	int8_t	i;

	i = -1;
	while (++i < RGBA)
	{
		str_col[i] = get_word(*current);
		ft_current_step(current, str_col[i]);
	}
	color->r = (uint8_t)strtol(str_col[RED], NULL, 16);
	color->g = (uint8_t)strtol(str_col[GREEN], NULL, 16);
	color->b = (uint8_t)strtol(str_col[BLUE], NULL, 16);
	color->a = (uint8_t)strtol(str_col[ALPHA], NULL, 16);
	i = -1;
	while (++i < RGBA)
		free(str_col[i]);
}

void	*get_last_list(t_light *light, t_object *object)
{
	t_light		*ltmp;
	t_object	*otmp;

	if (!light)
	{
		otmp = object;
		while (otmp->next)
			otmp = otmp->next;
		return (otmp);
	}
	ltmp = light;
	while (ltmp->next)
		ltmp = ltmp->next;
	return (ltmp);
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

void	get_object(t_object **head)
{
	t_object *back;
	t_object *object;

	if (!head)
		return ;
	if (!(*head))
	{
		object = (t_object*)malloc(sizeof(t_object));
		ft_bzero(object, sizeof(t_object));
		(*head) = object;
	}
	else
	{
		back = (*head);
		while (back->next)
			back = back->next;
		back->next = (t_object*)malloc(sizeof(t_object));
		ft_bzero(back->next, sizeof(t_object));
	}
}

void	ft_set_typ(char **current, t_object	*object)
{
	if (ft_strstr(*current, "sphere") == *current && (object->type = SPHERE))
		ft_current_step(current, "sphere");
	else if (ft_strstr(*current, "cylinder") == *current && (object->type = CYLINDER))
		ft_current_step(current, "cylinder");
	else if (ft_strstr(*current, "cone") == *current && (object->type = CONE))
		ft_current_step(current, "cone");
	else if (ft_strstr(*current, "plane") == *current && (object->type = PLANE))
		ft_current_step(current, "plane");
	else
		object->type = -1;
}
