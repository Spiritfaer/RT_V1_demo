/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_v1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 22:24:18 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/14 22:24:19 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_V1_H
#define RT_V1_H

#include "struct.h"

void	ft_end(t_sdl *sdl);
int8_t	ft_init(t_sdl *sdl);
void		ft_revers_list(t_list **head);
uint16_t	ft_count_list(t_list *head);
char	**ft_space_split(char const *s);
int		ft_count_words(const char *s);
void		ft_split_del(char **head);
t_list		*open_file(const char *file);
int8_t	ft_parser(const char *file, t_master *master);
#endif
