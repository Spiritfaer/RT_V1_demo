/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:18:22 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/14 22:18:23 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void		ft_object(char **current, t_master *master)
{
	int8_t	i;
	int16_t	flag;

	i = 7;
	flag = 0;
	ft_current_step(current, "object");
	get_object(&master->scene.object);
	if (**current == '{')
	{
		ft_current_step(current, NULL);
		while (i-- && master->error_flag)
		{
			if (!(flag & POS) && ft_strstr(*current, "position") == *current)
				ft_set_obj_position(current, master, &flag);
			else if (!(flag & COL) && ft_strstr(*current, "color") == *current)
				ft_set_obj_color(current, master, &flag);
			else if (!(flag & ROT) && ft_strstr(*current, "rotate") == *current)
				ft_set_obj_rotate(current, master, &flag);
			else if (!(flag & SCA) && ft_strstr(*current, "scale") == *current)
				ft_set_obj_scale(current, master, &flag);
			else if (!(flag & TYP) && ft_strstr(*current, "type") == *current)
				ft_set_obj_type(current, master, &flag);
			else if (!(flag & SIZ) && ft_strstr(*current, "size") == *current)
				ft_set_obj_size(current, master, &flag);
			else if ((flag & ALL) ==  ALL && **current == '}'
				&& ft_current_step(current, NULL)
				&& (master->init_flag |= SET_OBJECTS))
				return ;
			else
				master->error_flag = BROKEN;
		}
	}
	else
		master->error_flag = BROKEN;
}

int8_t		find_object(char **current, t_master *master)
{
	while (master->error_flag == WORK)
	{
		if (**current == '}' && *(*current + 1) == '\0')
			return (WORK);
		else if (ft_strstr(*current, "object") == *current)
			ft_object(current, master);
		else if (ft_strstr(*current, "light") == *current)
			ft_light(current, master);
		else if (!(master->init_flag & SET_CAMERA) && ft_strstr(*current, "camera") == *current)
			ft_camera(current, master);
//		printf("OK\n");
	}
	return (BROKEN);
}

int8_t		ft_read_file(t_master *master)
{
	char		*content;
	char 		*current;

	content = get_list_contenr(master->scene.head);
	current = content;
	if (find_scene(&current, "scene", master) <= 0 ||
			find_object(&current, master) <= 0)
	{
		free(content);
		return (BROKEN);
	}
	if (*current == '}' && *(current + 1) == '\0')
	{
		free(content);
		return (WORK);
	}
	return (BROKEN);
}



t_list		*open_file(const char *file)
{
	int32_t	fd;
	char 	*line;
	t_list	*head;

	line = NULL;
	head = NULL;
	if ((fd = open(file, O_RDONLY)) < 1)
		ft_putendl_fd("\nFD open error!\n", ERROR_FD);
	else
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_striter(line, &to_lower);
			ft_lstadd(&head, ft_lstnew(line, ft_strlen(line) + 1));
			free(line);
		}
		ft_revers_list(&head);
	}
	return (head);
}

int8_t	ft_parser(const char *file, t_master *master)
{
	if (!(master->scene.head = open_file(file)))
		return (BROKEN);
	if (!ft_read_file(master))
		return (BROKEN);
	return (WORK);
}
