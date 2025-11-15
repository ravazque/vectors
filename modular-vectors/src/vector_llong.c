
#include "../include/vectors.h"

void	vector_llong_init(Vector_llong *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(long long));
}

static void	vector_llong_resize(Vector_llong *v)
{
	size_t		new_cap;
	long long	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(long long));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_llong_push_back(Vector_llong *v, long long value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_llong_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

long long	vector_llong_get(Vector_llong *v, size_t index)
{
	return (v->data[index]);
}

void	vector_llong_set(Vector_llong *v, size_t index, long long value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_llong_size(Vector_llong *v)
{
	return (v->size);
}

size_t	vector_llong_capacity(Vector_llong *v)
{
	return (v->capacity);
}

void	vector_llong_free(Vector_llong *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
