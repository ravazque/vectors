
#include "../include/vectors.h"

void	vector_double_init(Vector_double *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(double));
}

void	vector_double_resize(Vector_double *v)
{
	size_t	new_cap;
	double	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(double));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_double_push_back(Vector_double *v, double value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_double_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

double	vector_double_get(Vector_double *v, size_t index)
{
	return (v->data[index]);
}

void	vector_double_set(Vector_double *v, size_t index, double value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_double_size(Vector_double *v)
{
	return (v->size);
}

size_t	vector_double_capacity(Vector_double *v)
{
	return (v->capacity);
}

void	vector_double_free(Vector_double *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
