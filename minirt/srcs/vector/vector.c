#include "shape.h"

void	vector_minus(t_vector *a, t_vector *b)
{
	a->x -= b->x;
}

void	vector_plus(t_vector *a, t_vector *b)
{
	a->x += b->x;
	// return (a->x + b->x, a->y + b->y, a->z + b->z);
}

void	vector_init(t_vector *a, int x, int y, int z)
{
	a->x = x;
	a->y = y;
	a->z = z;
}
