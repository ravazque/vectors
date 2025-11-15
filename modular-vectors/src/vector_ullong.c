
#include "../include/vectors.h"

void	vector_ullong_init(Vector_ullong *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(unsigned long long));
}

static void	vector_ullong_resize(Vector_ullong *v)
{
	size_t				new_cap;
	unsigned long long	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(unsigned long long));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_ullong_push_back(Vector_ullong *v, unsigned long long value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_ullong_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

unsigned long long	vector_ullong_get(Vector_ullong *v, size_t index)
{
	return (v->data[index]);
}

void	vector_ullong_set(Vector_ullong *v, size_t index, unsigned long long value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_ullong_size(Vector_ullong *v)
{
	return (v->size);
}

size_t	vector_ullong_capacity(Vector_ullong *v)
{
	return (v->capacity);
}

void	vector_ullong_free(Vector_ullong *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
