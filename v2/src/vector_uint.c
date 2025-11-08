
#include "../include/vectors.h"

void	vector_uint_init(Vector_uint *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(unsigned int));
}

static void	vector_uint_resize(Vector_uint *v)
{
	size_t			new_cap;
	unsigned int	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(unsigned int));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_uint_push_back(Vector_uint *v, unsigned int value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_uint_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

unsigned int	vector_uint_get(Vector_uint *v, size_t index)
{
	return (v->data[index]);
}

void	vector_uint_set(Vector_uint *v, size_t index, unsigned int value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_uint_size(Vector_uint *v)
{
	return (v->size);
}

size_t	vector_uint_capacity(Vector_uint *v)
{
	return (v->capacity);
}

void	vector_uint_free(Vector_uint *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
