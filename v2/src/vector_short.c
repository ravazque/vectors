
#include "../include/vectors.h"

void	vector_short_init(Vector_short *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(short));
}

static void	vector_short_resize(Vector_short *v)
{
	size_t	new_cap;
	short	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(short));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_short_push_back(Vector_short *v, short value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_short_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

short	vector_short_get(Vector_short *v, size_t index)
{
	return (v->data[index]);
}

void	vector_short_set(Vector_short *v, size_t index, short value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_short_size(Vector_short *v)
{
	return (v->size);
}

size_t	vector_short_capacity(Vector_short *v)
{
	return (v->capacity);
}

void	vector_short_free(Vector_short *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
