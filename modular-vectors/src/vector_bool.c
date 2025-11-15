
#include "../include/vectors.h"

void	vector_bool_init(Vector_bool *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(int));
}

static void	vector_bool_resize(Vector_bool *v)
{
	size_t	new_cap;
	int		*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(int));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_bool_push_back(Vector_bool *v, int value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_bool_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

int	vector_bool_get(Vector_bool *v, size_t index)
{
	return (v->data[index]);
}

void	vector_bool_set(Vector_bool *v, size_t index, int value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_bool_size(Vector_bool *v)
{
	return (v->size);
}

size_t	vector_bool_capacity(Vector_bool *v)
{
	return (v->capacity);
}

void	vector_bool_free(Vector_bool *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
