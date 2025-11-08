
#include "../include/vectors.h"

void	vector_char_init(Vector_char *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(char));
}

static void	vector_char_resize(Vector_char *v)
{
	size_t	new_cap;
	char	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(char));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_char_push_back(Vector_char *v, char value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_char_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

char	vector_char_get(Vector_char *v, size_t index)
{
	return (v->data[index]);
}

void	vector_char_set(Vector_char *v, size_t index, char value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_char_size(Vector_char *v)
{
	return (v->size);
}

size_t	vector_char_capacity(Vector_char *v)
{
	return (v->capacity);
}

void	vector_char_free(Vector_char *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
