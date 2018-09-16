//
// Created by Igor STALEVSKIY on 9/16/18.
//

#include "rt_v1.h"

void	ft_set_obj_position(char **current, t_master *master, int16_t *init)
{
	t_object	*object;
	ft_current_step(current, "position");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		object = get_last_list(NULL, master->scene.object);
		ft_set_v3d(current, &object->position);
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

void	ft_set_obj_color(char **current, t_master *master, int16_t *init)
{
	t_object	*object;
	ft_current_step(current, "color");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		object = get_last_list(NULL, master->scene.object);
		ft_set_col(current, &object->color);
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

void	ft_set_obj_rotate(char **current, t_master *master, int16_t *init)
{
	t_object	*object;
	ft_current_step(current, "rotate");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		object = get_last_list(NULL, master->scene.object);
		ft_set_v3d(current, &object->rotate);
		if (**current == '}')
		{
			*init |= ROT;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void	ft_set_obj_scale(char **current, t_master *master, int16_t *init)
{
	t_object	*object;
	ft_current_step(current, "scale");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		object = get_last_list(NULL, master->scene.object);
		ft_set_v3d(current, &object->scale);
		if (**current == '}')
		{
			*init |= SCA;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void	ft_set_obj_type(char **current, t_master *master, int16_t *init)
{
	t_object	*object;
	ft_current_step(current, "type");
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		object = get_last_list(NULL, master->scene.object);
		ft_set_typ(current, object);
		if (object->type > 0 && **current == '}')
		{
			*init |= TYP;
			ft_current_step(current, NULL);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}