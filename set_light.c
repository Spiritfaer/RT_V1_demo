#include "rt_v1.h"

static void	ft_set_light_position(char **current, t_master *master, int16_t *init)
{
	t_light	*light;
	ft_current_step(current, "position");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		light = get_last_list(master->scene.light, NULL);
		ft_set_v3d(current, &light->position);
		if (**current == '}')
		{
			*init |= POS;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

static void	ft_set_light_color(char **current, t_master *master, int16_t *init)
{
	t_light	*light;
	ft_current_step(current, "color");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		light = get_last_list(master->scene.light, NULL);
		ft_set_col(current, &light->color);
		if (**current == '}')
		{
			*init |= COL;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void		ft_light(char **current, t_master *master)
{
	int8_t	i;
	int16_t	flag;

	i = 3;
	flag = 0;
	ft_current_step(current, "light");
	get_light(&master->scene.light);
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		while (i-- && master->error_flag)
		{
			if (!(flag & POS) && ft_strstr(*current, "position") == *current)
				ft_set_light_position(current, master, &flag);
			else if (!(flag & COL) && ft_strstr(*current, "color") == *current)
				ft_set_light_color(current, master, &flag);
			else if ((flag & (POS | COL)) == (POS | COL) && **current == '}'
					 && ft_current_step(current, NULL)
					 && (master->init_flag |= SET_LIGHT))
				return ;
			else
				master->error_flag = BROKEN;
		}
	}
	else
		master->error_flag = BROKEN;
}
