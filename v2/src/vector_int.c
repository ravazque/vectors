
#include "../include/vectors.h"

void	vector_int_init(Vector_int *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(int));
}

void	vector_int_resize(Vector_int *v)
{
	size_t	new_cap;
	int		*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(int));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_int_push_back(Vector_int *v, int value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_int_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

int	vector_int_get(Vector_int *v, size_t index)
{
	return (v->data[index]);
}

void	vector_int_set(Vector_int *v, size_t index, int value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_int_size(Vector_int *v)
{
	return (v->size);
}

size_t	vector_int_capacity(Vector_int *v)
{
	return (v->capacity);
}

void	vector_int_free(Vector_int *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
