
#include "../include/vectors.h"

void	vector_init_multiple(int count, ...)
{
	va_list		args;
	int			i;
	VectorType	type;
	void		*vector_ptr;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		type = va_arg(args, VectorType);
		vector_ptr = va_arg(args, void *);
		if (type == TYPE_INT)
			vector_int_init((Vector_int *)vector_ptr);
		if (type == TYPE_FLOAT)
			vector_float_init((Vector_float *)vector_ptr);
		if (type == TYPE_DOUBLE)
			vector_double_init((Vector_double *)vector_ptr);
		if (type == TYPE_CHAR)
			vector_char_init((Vector_char *)vector_ptr);
		if (type == TYPE_BOOL)
			vector_bool_init((Vector_bool *)vector_ptr);
		if (type == TYPE_LONG)
			vector_long_init((Vector_long *)vector_ptr);
		if (type == TYPE_SHORT)
			vector_short_init((Vector_short *)vector_ptr);
		if (type == TYPE_UINT)
			vector_uint_init((Vector_uint *)vector_ptr);
		if (type == TYPE_ULONG)
			vector_ulong_init((Vector_ulong *)vector_ptr);
		if (type == TYPE_UCHAR)
			vector_uchar_init((Vector_uchar *)vector_ptr);
		if (type == TYPE_LLONG)
			vector_llong_init((Vector_llong *)vector_ptr);
		if (type == TYPE_ULLONG)
			vector_ullong_init((Vector_ullong *)vector_ptr);
		if (type == TYPE_SIZET)
			vector_sizet_init((Vector_sizet *)vector_ptr);
		if (type == TYPE_PTR)
			vector_ptr_init((Vector_ptr *)vector_ptr);
		i++;
	}
	va_end(args);
}

void	vector_free_multiple(int count, ...)
{
	va_list		args;
	int			i;
	VectorType	type;
	void		*vector_ptr;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		type = va_arg(args, VectorType);
		vector_ptr = va_arg(args, void *);
		if (type == TYPE_INT)
			vector_int_free((Vector_int *)vector_ptr);
		if (type == TYPE_FLOAT)
			vector_float_free((Vector_float *)vector_ptr);
		if (type == TYPE_DOUBLE)
			vector_double_free((Vector_double *)vector_ptr);
		if (type == TYPE_CHAR)
			vector_char_free((Vector_char *)vector_ptr);
		if (type == TYPE_BOOL)
			vector_bool_free((Vector_bool *)vector_ptr);
		if (type == TYPE_LONG)
			vector_long_free((Vector_long *)vector_ptr);
		if (type == TYPE_SHORT)
			vector_short_free((Vector_short *)vector_ptr);
		if (type == TYPE_UINT)
			vector_uint_free((Vector_uint *)vector_ptr);
		if (type == TYPE_ULONG)
			vector_ulong_free((Vector_ulong *)vector_ptr);
		if (type == TYPE_UCHAR)
			vector_uchar_free((Vector_uchar *)vector_ptr);
		if (type == TYPE_LLONG)
			vector_llong_free((Vector_llong *)vector_ptr);
		if (type == TYPE_ULLONG)
			vector_ullong_free((Vector_ullong *)vector_ptr);
		if (type == TYPE_SIZET)
			vector_sizet_free((Vector_sizet *)vector_ptr);
		if (type == TYPE_PTR)
			vector_ptr_free((Vector_ptr *)vector_ptr);
		i++;
	}
	va_end(args);
}
