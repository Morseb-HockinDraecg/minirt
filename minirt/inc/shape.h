#ifndef MINI_RT_H
# define MINI_RT_H

typedef struct	s_vector
{
	int		x;
	int 	y;
	int 	z;
}			t_vector;

typedef struct	s_sphere
{
	t_vector	cood;
	int			diametre;
	t_vector	rgb;
}		t_sphere;

void	vector_minus(t_vector *a, t_vector *b);
void	vector_plus(t_vector *a, t_vector *b);

# endif