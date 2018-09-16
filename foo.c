/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foo.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:18:53 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/14 22:18:54 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

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

uint8_t		ft_check_set_scene(const uint8_t *set)
{
	uint16_t	i;

	i = 0;
	while (i < MAXBASE)
	{
		if (set[i++] == BROKEN)
			return (BROKEN);
	}
	return (WORK);
}

void		ft_print_split(char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
}

char	*get_word(char *end)
{
	char *start;
	char *name;

	start = end;
	while (!ft_isspase(*end))
		end++;
	name = strndup(start, end - start);
	return (name);
}

char *find(const char *str)
{
	char *tmp;

	tmp = (char*)str;
	while (ft_isspase(*tmp))
		tmp++;
	return (tmp);
}

char	*get_list_contenr(t_list *head)
{
	t_list		*tmp;
	uint32_t	size;
	char		*new_str;

	tmp = head;
	size = 0;
	while (tmp)
	{
		size += (uint32_t)tmp->content_size;
		tmp = tmp->next;
	}
	new_str = ft_strnew(size);
	tmp = head;
	while (tmp)
	{
		ft_strcat(new_str, tmp->content);
		tmp = tmp->next;
	}
	return (new_str);
}

void		to_lower(char *c)
{
	if (*c >= 65 && *c <= 90)
		*c += 32;
}
