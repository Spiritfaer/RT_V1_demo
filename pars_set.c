//
// Created by Igor STALEVSKIY on 9/16/18.
//

#include "rt_v1.h"

uint8_t		set_render(char **current)
{
	if (ft_strstr(*current, "accelerated") == *current)
	{
		*current += ft_strlen("accelerated");
		*current = find(*current);
		return (ACCELERATED);
	}
	return (SOFTWARE);
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