
#include "../include/vectors.h"

void	vector_ulong_init(Vector_ulong *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(unsigned long));
}

static void	vector_ulong_resize(Vector_ulong *v)
{
	size_t			new_cap;
	unsigned long	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(unsigned long));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_ulong_push_back(Vector_ulong *v, unsigned long value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_ulong_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

unsigned long	vector_ulong_get(Vector_ulong *v, size_t index)
{
	return (v->data[index]);
}

void	vector_ulong_set(Vector_ulong *v, size_t index, unsigned long value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_ulong_size(Vector_ulong *v)
{
	return (v->size);
}

size_t	vector_ulong_capacity(Vector_ulong *v)
{
	return (v->capacity);
}

void	vector_ulong_free(Vector_ulong *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
