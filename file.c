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

int8_t find_scene(char **current, char *needle, t_master *master)
{
	if (ft_strstr(*current, needle))
	{
		*current += ft_strlen(needle);
		*current = find(*current);
		if (**current != '{')
			return (-1);
		else
			(*current)++;
		pars_scene(current, master);
	}
	else
		master->error_flag = BROKEN;
	if (**current == '}' && *(*current + 1) == '\0')
		return (END);
	return (-1);
}

int8_t		ft_read_file(t_master *master)
{
	char		*content;
	char 		*current;
	int16_t		i;

	i = -1;
	content = get_list_contenr(master->scene.head);
//	printf("%s\n", content);
	current = content;

	i = find_scene(&current, "scene", master);
//	printf("current = %s\ni = %d\n", current, i);
//	while (current)
//	{
//		current = find(content);
//
//	}
//	current = ft_strstr(content, "scene");
//	if (!current)
//		return (BROKEN);
//	printf("%s\n", current);
/*
	while (list && master->error_flag)
	{
		split = ft_space_split((char*)list->content);
		i = 0;
		while (split[i] && master->error_flag && master->init_flag != END)
		{
			printf("\t%s\t\t\t\t%d\n", split[i], i);

//			if (!list->next)
//			{
//				if (!ft_strcmp(*split, "}") && master->error_flag)
//					master->init_flag = END;
//			}
//			if (master->init_flag == START)
//				ft_set_base(master, split[i]);
//			else if (master->init_flag == SCENE)
//				ft_set_scene(master, split, &i);
//			else if (master->init_flag == OBJECT)
//				ft_set_object(master, split, &i);
//			else if (master->init_flag == SHAPE)
//				ft_set_shape(master, split, &i);
			i++;
		}
		ft_split_del(split);
		list = list->next;
	}
	(master->error_flag == BROKEN) ? printf("BROKEN\n") : printf("WORK\n");
	return (master->error_flag);
 */

	free(content);
	return (WORK);
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
