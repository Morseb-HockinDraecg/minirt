#include "mini_rt.h"

t_coord	v_copy(t_coord b)
{
	t_coord a;

	a.x = b.x;
	a.y = b.y;
	a.z = b.z;
	return (a);
}

t_coord	v_normaliz(t_coord a)
{
	float	norm;
	t_coord b;

	norm = sqrt(v_norm2(&a));
	b.x = a.x / norm;
	b.y = a.y / norm;
	b.z = a.z / norm;
	return (b);
}

float	v_norm2(t_coord *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

float	v_dot(t_coord a, t_coord b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

void	v_div(t_coord *a, t_coord *b)
{
	// a->x /= b;
	// a->y /= b;
	// a->z /= b;
	(void)a;
	(void)b;
}

t_coord	v_mult(t_coord *a, float b)
{
	t_coord	c;

	c.x = a->x * b;
	c.y = a->y * b;
	c.z = a->z * b;
	return (c);
}

t_coord	v_minus(t_coord a, t_coord b)
{
	t_coord	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_coord	v_plus(t_coord a, t_coord b)
{
	t_coord	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

// t_coord	v_add(t_coord a, float b)
// {
// 	t_coord	c;

// 	c.x = a.x + b;
// 	c.y = a.y + b;
// 	c.z = a.z + b;
// 	return (c);
// }

void	v_init(t_coord *a, int x, int y, int z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}
