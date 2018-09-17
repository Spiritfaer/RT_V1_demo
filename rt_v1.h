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

void		ft_end(t_sdl *sdl);
int8_t		ft_init(t_sdl *sdl);
void		ft_revers_list(t_list **head);
void		ft_print_split(char **split);
uint16_t	ft_count_list(t_list *head);
char		**ft_space_split(char const *s);
int			ft_count_words(const char *s);
void		ft_split_del(char **head);
t_list		*open_file(const char *file);
int8_t		ft_parser(const char *file, t_master *master);



uint8_t		ft_check_set_scene(const uint8_t *set);

char	*get_word(char *end);
char	*find(const char *str);
char	*get_list_contenr(t_list *head);
void	to_lower(char *c);
int8_t	set_render(char **current);
void	set_window(char **current, t_master *master);
int8_t	find_scene(char **current, char *needle, t_master *master);
void	ft_set_v3d(char **current, t_v3d *vector);
void	ft_camera(char **current, t_master *master);
int8_t	ft_current_step(char **current, char *str);
void	ft_set_col(char **current, SDL_Color *color);
void	*get_last_list(t_light *light, t_object *object);
void	get_light(t_light **head);
void	get_object(t_object **head);
void	ft_light(char **current, t_master *master);
void	ft_set_typ(char **current, t_object	*object);
void	ft_set_obj_position(char **current, t_master *master, int16_t *init);
void	ft_set_obj_color(char **current, t_master *master, int16_t *init);
void	ft_set_obj_rotate(char **current, t_master *master, int16_t *init);
void	ft_set_obj_scale(char **current, t_master *master, int16_t *init);
void	ft_set_obj_type(char **current, t_master *master, int16_t *init);
void	ft_set_obj_size(char **current, t_master *master, int16_t *init);
void	ft_set_size(char **current, t_object *object);
void	defolt_master (t_master *master);
int8_t	render(t_master *master);

#endif
