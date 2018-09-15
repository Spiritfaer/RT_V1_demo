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

uint8_t		set_position(t_master *master, char **split, uint16_t *i)
{

	return (WORK);
}

uint8_t		set_rotate(t_master *master, char **split, uint16_t *i)
{
	return (WORK);
}

void		set_camera(t_master *master, char **split, uint16_t *i, int8_t	*flag)
{
	if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "{") && master->error_flag)
	{
		if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "position"))
		{
			master->error_flag = set_position(master, split, i);
			return ;
		}
		else if (*(split + (*i)) && !ft_strcmp(*(split + (*i)), "rotate"))
		{
			master->error_flag = set_rotate(master, split, i);
			return ;
		}
	}
	else if (*(split + ++(*i)) && !ft_strcmp(*(split + (*i)), "}") && master->error_flag)
		*flag = -1;
}

void		ft_set_object(t_master *master, char **split, uint16_t *i)
{
	static int8_t	flag = -1;

	if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "camera")) || flag == CAM)
	{
		flag = CAM;
		set_camera(master, split, i, &flag);
	}
	else if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "light")) || flag == LIGHT)
	{
		flag = LIGHT;
//		set_light();
	}
	else if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "plane")) || flag == PLANE)
	{
		flag = PLANE;
//		set_plane();
	}
	else if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "sphere")) || flag == SPHERE)
	{
		flag = SPHERE;
//		set_sphere();
	}
	else if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "cylinder")) || flag == CYLINDER)
	{
		flag = CYLINDER;
//		set_cylinder;
	}
	else if ((*(split + (*i)) && !ft_strcmp(*(split + (*i)), "cone")) || flag == CONE)
	{
		flag = CONE;
//		set_cone();
	}
	else if (flag == -1)
		master->error_flag = BROKEN;
}

int8_t		ft_read_file(t_master *master)
{
	t_list		*list;
	char		**split;
	uint16_t	i;

	list = master->scene.head;

	while (list && master->error_flag)
	{
		split = ft_space_split((char*)list->content);
		i = 0;
		while (split[i] && master->error_flag)
		{
			printf("\t%s\t\t\t\t%d\n", split[i], i);
			if (master->init_flag == START)
				ft_set_base(master, split[i]);
			else if (master->init_flag == SCENE)
				ft_set_scene(master, split, &i);
			else if (master->init_flag == OBJECT)
				ft_set_object(master, split, &i);
//			else if (master->init_flag == VAR)
//				;
			i++;

		}
		ft_split_del(split);
		list = list->next;
	}
//	printf("%s\n", master->sdl.win_name);
//	printf("width = %d\n", master->sdl.screen_width);
//	printf("height = %d\n", master->sdl.screen_height);
//	printf("render = %d\n", master->sdl.render_flag);
	printf("init_flag = %d\n", master->init_flag);
	(master->error_flag == BROKEN) ? printf("BROKEN\n") : printf("WORK\n");
	return (BROKEN);
}

void		to_lower(char *c)
{
	if (*c >= 65 && *c <= 90)
		*c += 32;
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
