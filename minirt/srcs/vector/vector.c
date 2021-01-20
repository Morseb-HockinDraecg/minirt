#include "mini_rt.h"

void	v_copy(t_coord *a, t_coord *b)
{
	a->x = b->x;
	a->y = b->y;
	a->z = b->z;
}

void	v_normaliz(t_coord *a)
{
	float norm;

	norm = sqrt(v_norm2(a));
	a->x /= norm;
	a->y /= norm;
	a->z /= norm;
}

float	v_norm2(t_coord *a)
{
	return (a->x * a->x + a->y * a->y + a->z * a->z);
}

float	v_dot(t_coord *a, t_coord *b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

void	v_div(t_coord *a, t_coord *b)
{
	// a->x /= b;
	// a->y /= b;
	// a->z /= b;
	(void)a;
	(void)b;
}

void	v_mult(t_coord *a, float b)
{
	a->x *= b;
	a->y *= b;
	a->z *= b;
}

void	v_minus(t_coord *a, t_coord *b)
{
	a->x -= b->x;
	a->y -= b->y;
	a->z -= b->z;
}

void	v_plus(t_coord *a, t_coord *b)
{
	a->x += b->x;
	a->y += b->y;
	a->z += b->z;
}

void	v_init(t_coord *a, int x, int y, int z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}
