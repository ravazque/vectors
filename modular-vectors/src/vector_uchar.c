
#include "../include/vectors.h"

void	vector_uchar_init(Vector_uchar *v)
{
	v->size = 0;
	v->capacity = 4;
	v->data = malloc(v->capacity * sizeof(unsigned char));
}

static void	vector_uchar_resize(Vector_uchar *v)
{
	size_t			new_cap;
	unsigned char	*new_data;

	new_cap = v->capacity * 2;
	new_data = realloc(v->data, new_cap * sizeof(unsigned char));
	v->data = new_data;
	v->capacity = new_cap;
}

void	vector_uchar_push_back(Vector_uchar *v, unsigned char value)
{
	size_t	is_full;

	is_full = v->size >= v->capacity;
	if (is_full)
	{
		vector_uchar_resize(v);
	}
	v->data[v->size] = value;
	v->size++;
}

unsigned char	vector_uchar_get(Vector_uchar *v, size_t index)
{
	return (v->data[index]);
}

void	vector_uchar_set(Vector_uchar *v, size_t index, unsigned char value)
{
	int	is_valid;

	is_valid = index < v->size;
	if (is_valid)
	{
		v->data[index] = value;
	}
}

size_t	vector_uchar_size(Vector_uchar *v)
{
	return (v->size);
}

size_t	vector_uchar_capacity(Vector_uchar *v)
{
	return (v->capacity);
}

void	vector_uchar_free(Vector_uchar *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
	v->capacity = 0;
}
