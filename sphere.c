/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: istalevs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/22 20:40:53 by istalevs          #+#    #+#             */
/*   Updated: 2018/09/22 20:40:54 by istalevs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_v1.h"

SDL_Color	get_sphere_color(const void *data)
{
	const t_sphere	*sphere;

	sphere = data;
	return (sphere->color);
}

t_v3d		get_sphere_normal_vector(const void *data,
										const t_v3d intersection_point)
{
	t_v3d			normal;
	const t_sphere	*sphere;

	sphere = data;
	normal = vec_3sub(sphere->centr, intersection_point);
	return (vec_3norm(normal));
}

void		free_sphere_data(void *data)
{
	t_sphere	*sphere;

	sphere = data;
	free(sphere);
}

int8_t		sphere_intersection(const void *data,
								const t_v3d vector_start,
								const t_v3d vector_dir,
								t_v3d *intersection_point)
{
	const t_sphere *sphere = data;
	t_v3d	oc = vec_3sub(vector_start, sphere->centr);
	double	a = vec_3dot(vector_dir, vector_dir);
	double	b = 2.0 * vec_3dot(vector_dir, oc);
	double	dot1 = vec_3dot(sphere->centr, sphere->centr);
	double	dot2 = vec_3dot(vector_start, vector_start);
	double	c = dot1 + dot2 - 2.0 * vec_3dot(vector_start, sphere->centr)
			- sphere->radius * sphere->radius;
	double	d = b *b - 4 * a * c;
	if (d < 0)
		return (0);
	double	sqrt_d = sqrt(d);
	double	a_2 = a * 2.0;
	double	t1 = (-b + sqrt_d) / a_2;
	double	t2 = (-b - sqrt_d) / a_2;
	double	min_t = (t1 < t2) ? t1 : t2;
	double	max_t = (t1 > t2) ? t1 : t2;
	double	t = (min_t > EPSILON) ? min_t : max_t;

	if(t < EPSILON)
		return (0);
	*intersection_point = vec_3add(vector_start, vec_3fmul(vector_dir, t));
	return (0);
}
