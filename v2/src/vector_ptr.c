
#include "../include/vectors.h"

void	vector_ptr_init(Vector_ptr *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(void *));
}

static void	vector_ptr_resize(Vector_ptr *v)
{
	size_t	new_cap;
	void	**new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(void *));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_ptr_push_back(Vector_ptr *v, void *value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_ptr_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

void	*vector_ptr_get(Vector_ptr *v, size_t index)
{
	return (v->data[index]);
}

void	vector_ptr_set(Vector_ptr *v, size_t index, void *value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_ptr_size(Vector_ptr *v)
{
	return (v->size);
}

size_t	vector_ptr_capacity(Vector_ptr *v)
{
	return (v->capacity);
}

void	vector_ptr_free(Vector_ptr *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
