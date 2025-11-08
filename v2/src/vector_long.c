
#include "../include/vectors.h"

void	vector_long_init(Vector_long *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(long));
}

static void	vector_long_resize(Vector_long *v)
{
	size_t	new_cap;
	long	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(long));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_long_push_back(Vector_long *v, long value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_long_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

long	vector_long_get(Vector_long *v, size_t index)
{
	return (v->data[index]);
}

void	vector_long_set(Vector_long *v, size_t index, long value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_long_size(Vector_long *v)
{
	return (v->size);
}

size_t	vector_long_capacity(Vector_long *v)
{
	return (v->capacity);
}

void	vector_long_free(Vector_long *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
