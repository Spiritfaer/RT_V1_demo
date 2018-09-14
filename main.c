/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 01:14:03 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/12 01:14:04 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

void		ft_split_del(char **head)
{
	uint_fast32_t	i;

	i = 0;
	while (head[i])
	{
		free(head[i]);
		head[i] = NULL;
		i++;
	}
	free(head);
	head = NULL;
}

int		ft_count_words(const char *s)
{
	int count;
	int word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s != '\0' && !ft_isspase(*s))
			count++;
		if ((*(s + 1) == '\0' || ft_isspase(*s)) && count > 0)
		{
			word++;
			count = 0;
		}
		s++;
	}
	return (word);
}


char	**ft_space_split(char const *s)
{
	const char	*tmp;
	char		**demo;
	int			words;
	int			count;

	if (s == NULL)
		return (NULL);
	count = 0;
	words = ft_count_words(s) + 1;
	if ((demo = (char**)malloc(words * sizeof(char*))) == NULL)
		return (NULL);
	(void)ft_memset(demo, '\0', words-- * sizeof(char*));
	while (count < words)
	{
		while (*s && ft_isspase(*s))
			s++;
		tmp = s;
		while (*tmp && !ft_isspase(*tmp))
			tmp++;
		if (ft_isspase(*tmp) || *tmp == '\0')
			if ((demo[count++] = ft_strndup(s, (tmp++ - s))) == NULL)
				return (NULL);
		s = tmp;
	}
	return (demo);
}

int8_t	ft_init(t_sdl *sdl)
{
	int8_t	result;

	result = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0 && result--)
		ft_putendl_fd(SDL_GetError(), 2);
	else
	{
		sdl->winndow = SDL_CreateWindow("RT_V1", 150, 150,
				DEF_SCREEN_WIDTH, DEF_SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (!sdl->winndow && result--)
			ft_putendl_fd(SDL_GetError(), 2);
		else
		{
			sdl->render = SDL_CreateRenderer(sdl->winndow, -1,
				SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (!sdl->render && result--)
				ft_putendl_fd(SDL_GetError(), 2);
		}
	}
	return (result);
}

void	ft_end(t_sdl *sdl)
{
	if (sdl->render)
		SDL_DestroyRenderer(sdl->render);
	if (sdl->winndow)
		SDL_DestroyWindow(sdl->winndow);
	SDL_Quit();
}

void		ft_revers_list(t_list **head)
{
	t_list			*prev;
	t_list			*current;
	t_list			*next;

	current = *head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

uint16_t	ft_count_list(t_list *head)
{
	uint16_t coun;

	coun = 0;
	while (head)
	{
		head = head->next;
		coun++;
	}
	return (coun);
}

int8_t		init_scene()
{}

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

int8_t	rerere(const char *file, t_master *master)
{

	master->scene.head = open_file(file);
	if (!master->scene.head)
		return (BROKEN);
	if (!ft_read_file(master))
		return (BROKEN);
	return (WORK);
}

int		main(int argc, char **argv)
{
	t_master	master;
	if (argc != 2)
		return (0);
	if (rerere(argv[1], &master) == BROKEN)
		ft_putendl_fd("\nInvalid file!\n", ERROR_FD);
	else
	{
		printf("WORK BITCH\n");
	}
	ft_end(&master.sdl);
	system("leaks -q RT_V1_demo");
	return 0;
}
