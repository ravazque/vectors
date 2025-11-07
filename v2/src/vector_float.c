
#include "../include/vectors.h"

void	vector_float_init(Vector_float *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(float));
}

void	vector_float_resize(Vector_float *v)
{
	size_t	new_cap;
	float	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(float));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_float_push_back(Vector_float *v, float value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_float_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

float	vector_float_get(Vector_float *v, size_t index)
{
	return (v->data[index]);
}

void	vector_float_set(Vector_float *v, size_t index, float value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_float_size(Vector_float *v)
{
	return (v->size);
}

size_t	vector_float_capacity(Vector_float *v)
{
	return (v->capacity);
}

void	vector_float_free(Vector_float *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
