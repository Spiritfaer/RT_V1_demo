/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:40:03 by istalevs          #+#    #+#             */
/*   Updated: 2018/05/13 18:06:28 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vmth.h"

t_v2d	vec_2d(double x, double y)
{
	t_v2d	new;

	new = (t_v2d){x, y};
	return (new);
}