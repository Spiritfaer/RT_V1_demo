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

void	ft_set_v3d(char **current, t_v3d *vector)
{
	char	*str_vec[VECTOR + 1];
	int8_t	i;

	i = -1;
	while (++i < VECTOR)
	{
		str_vec[i] = get_word(*current);
		*current += ft_strlen(str_vec[i]);
		*current = find(*current);
	}
	vector->x = atof(str_vec[X]);
	vector->y = atof(str_vec[Y]);
	vector->z = atof(str_vec[Z]);
	i = -1;
	while (++i < VECTOR)
		free(str_vec[i]);
}

void	ft_set_rotate(char **current, t_master *master)
{
	*current += ft_strlen("rotate");
	*current = find(*current);
	if (**current == '{')
	{
		(*current)++;
		*current = find(*current);
		ft_set_v3d(current, &master->scene.cam.rotate);
		if (**current == '}')
		{
			(*current)++;
			*current = find(*current);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void	ft_set_position(char **current, t_master *master)
{
	*current += ft_strlen("position");
	*current = find(*current);
	if (**current == '{')
	{
		(*current)++;
		*current = find(*current);
		ft_set_v3d(current, &master->scene.cam.position);
		if (**current == '}')
		{
			(*current)++;
			*current = find(*current);
		}
		else
			master->error_flag = BROKEN;
	}
	else
		master->error_flag = BROKEN;
}

void	ft_camera(char **current, t_master *master)
{
	int8_t	i;
	int8_t	init;

	i = 3;
	init = 0;
	*current += ft_strlen("camera");
	*current = find(*current);
	if (**current == '{')
	{
		(*current)++;
		*current = find(*current);
		while (i-- && master->error_flag)
		{
			if (!(init & POS) && ft_strstr(*current, "position") == *current)
				ft_set_position(current, master);
			else if (!(init & ROT) && ft_strstr(*current, "rotate") == *current)
				ft_set_rotate(current, master);
			else if (init & (POS | ROT))
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
			printf("00000000\n");
		else if (ft_strstr(*current, "light") == *current)
			printf("11111111\n");
		else if (!(master->init_flag & SET_CAMERA) && ft_strstr(*current, "camera") == *current)
			ft_camera(current, master);
	}
	return (BROKEN);
}

int8_t		ft_read_file(t_master *master)
{
	char		*content;
	char 		*current;

	content = get_list_contenr(master->scene.head);
//	printf("%s\n", content);
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
