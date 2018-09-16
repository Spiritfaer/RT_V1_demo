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
	*current += ft_strlen(width);
	*current = find(*current);
	height = get_word(*current);
	*current += ft_strlen(height);
	*current = find(*current);
	master->scene.cam.window_size.x = ft_atoi(width);
	master->scene.cam.window_size.y = ft_atoi(height);
	free(width);
	free(height);
}