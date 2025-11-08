
#include "../include/vectors.h"

void	vector_sizet_init(Vector_sizet *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(size_t));
}

static void	vector_sizet_resize(Vector_sizet *v)
{
	size_t	new_cap;
	size_t	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(size_t));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_sizet_push_back(Vector_sizet *v, size_t value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_sizet_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

size_t	vector_sizet_get(Vector_sizet *v, size_t index)
{
	return (v->data[index]);
}

void	vector_sizet_set(Vector_sizet *v, size_t index, size_t value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_sizet_size(Vector_sizet *v)
{
	return (v->size);
}

size_t	vector_sizet_capacity(Vector_sizet *v)
{
	return (v->capacity);
}

void	vector_sizet_free(Vector_sizet *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
