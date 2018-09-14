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

int8_t		ft_read_file(t_master *master)
{
//	uint16_t	size;
	t_list		*list;
	char		**split;
	int i = 0;

//	size = ft_count_list(master->scene.head);
	list = master->scene.head;
//	list = list->next;
//	list = list->next;
//	list = list->next;
//	list = list->next;
	split = ft_space_split((char*)list->content);
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	ft_split_del(split);
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
			ft_lstadd(&head, ft_lstnew(line, ft_strlen(line) + 1));
			free(line);
		}
		ft_revers_list(&head);
	}
	return (head);
}

int8_t	ft_parser(const char *file, t_master *master)
{

	master->scene.head = open_file(file);
	if (!master->scene.head)
		return (BROKEN);
	if (!ft_read_file(master))
		return (BROKEN);
	return (WORK);
}