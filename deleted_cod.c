t_ray	set_ray(t_v3d A, t_v3d B)
{
	t_ray ray = {A, B};
	return (ray);
}

double	ft_hit_sphere_one(t_v3d *center, double radius, t_ray *ray)
{
	t_v3d oc = vec_3sub(ray->origin, *center);
	double a = vec_3dot(ray->direction, ray->direction);
	double b = 2.0 * vec_3dot(oc, ray->direction);
	double c = vec_3dot(oc, oc) - radius * radius;
	double discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0);
	return ((-b - sqrt(discriminant)) / (2.0 * a)); //что за формула?
}

t_v3d	point_at_parametr(double t, t_ray *ray)
{
	t_v3d result;

	result = vec_3fmul(ray->direction, t);
	result = vec_3add(ray->origin, result);
	return (result);
}

t_v3d	vec_3fdiv(t_v3d vec, double f)
{
	return ((t_v3d){vec.x / f, vec.y / f, vec.z / f});
}

int8_t	ft_hit_sphere(t_ray *ray, double t_min, double t_max, t_hit_record *rec, t_object *sphere)
{
	t_v3d oc = vec_3sub(ray->origin, sphere->position);
	double a = vec_3dot(ray->direction, ray->direction);
	double b = vec_3dot(oc, ray->direction);
	double c = vec_3dot(oc, oc) - sphere->size * sphere->size;
	double discriminant = b * b - a * c;
	if (discriminant > 0)
	{
		double temp = (-b - sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec->t = temp;
			rec->p = point_at_parametr(rec->t, ray);
			rec->normal = vec_3fdiv(vec_3sub(rec->p, sphere->position), sphere->size);
			return (1);
		}
		temp = (-b + sqrt(discriminant)) / a;
		if (temp < t_max && temp > t_min)
		{
			rec->t = temp;
			rec->p = point_at_parametr(rec->t, ray);
			rec->normal = vec_3fdiv(vec_3sub(rec->p, sphere->position), sphere->size);
			return (1);
		}
	}
	return (0);
}

int8_t	ft_hit_list(t_hitable_list *hit_list, t_ray *ray,
					  double t_min, double t_max, t_hit_record *rec)
{
	t_hit_record temp_rec;
	int8_t hit_anything = 0;
	double closest_so_far = t_max;
	for (int i = 0; i < hit_list->list_size; i++)
	{
		if (ft_hit_list(&hit_list[i], ray, t_min, closest_so_far, &temp_rec))
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
	}
	return (hit_anything);
}

t_v3d	ray_color(t_ray *ray, t_object *sphere)
{
	double t = ft_hit_sphere_one(&sphere->position, sphere->size, ray);
//	double t = ft_hit_sphere(ray, 0,1,NULL,sphere);
	if (t > 0.0)
	{
		t_v3d back = {0, 0, -1};
		t_v3d N = vec_3norm(vec_3sub(point_at_parametr(t, ray), back));
		t_v3d tmp = {N.x + 1, N.y + 1, N.z + 1};
		return (vec_3fmul(tmp, 0.5));
	}
	t_v3d unit_direction;
	unit_direction = vec_3norm(ray->direction);
	t = 0.5 * (unit_direction.y + 1.0);
	t_v3d A = {1.0, 1.0, 1.0};
	t_v3d B = {0.5, 0.7, 1.0};
	A = vec_3fmul(A, 1.0 - t);
	B = vec_3fmul(B, t);
	return (vec_3add(A, B));
}