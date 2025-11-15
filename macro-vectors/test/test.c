
#include "../include/vectors.h"
#include <stdio.h>

void	print_vector_int(Vector_int *vector)
{
	size_t	i;
	size_t	vector_size;

	i = 0;
	vector_size = vector_int_size(vector);
	printf("[");
	while (i < vector_size)
	{
		printf("%d", vector_int_get(vector, i));
		if (i < vector_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

void	print_vector_float(Vector_float *vector)
{
	size_t	i;
	size_t	vector_size;

	i = 0;
	vector_size = vector_float_size(vector);
	printf("[");
	while (i < vector_size)
	{
		printf("%.2f", vector_float_get(vector, i));
		if (i < vector_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

void	print_vector_double(Vector_double *vector)
{
	size_t	i;
	size_t	vector_size;

	i = 0;
	vector_size = vector_double_size(vector);
	printf("[");
	while (i < vector_size)
	{
		printf("%.2lf", vector_double_get(vector, i));
		if (i < vector_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

void	print_vector_char(Vector_char *vector)
{
	size_t	i;
	size_t	vector_size;

	i = 0;
	vector_size = vector_char_size(vector);
	printf("[");
	while (i < vector_size)
	{
		printf("'%c'", vector_char_get(vector, i));
		if (i < vector_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

void	print_vector_bool(Vector_bool *vector)
{
	size_t	i;
	size_t	vector_size;
	int		value;

	i = 0;
	vector_size = vector_bool_size(vector);
	printf("[");
	while (i < vector_size)
	{
		value = vector_bool_get(vector, i);
		if (value)
		{
			printf("true");
		}
		if (!value)
		{
			printf("false");
		}
		if (i < vector_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

void	print_vector_long(Vector_long *vector)
{
	size_t	i;
	size_t	vector_size;

	i = 0;
	vector_size = vector_long_size(vector);
	printf("[");
	while (i < vector_size)
	{
		printf("%ld", vector_long_get(vector, i));
		if (i < vector_size - 1)
		{
			printf(", ");
		}
		i++;
	}
	printf("]\n");
}

void	test_vector_int(void)
{
	Vector_int	integers;

	vector_int_init(&integers);
	vector_int_push_back(&integers, 10);
	vector_int_push_back(&integers, 20);
	vector_int_push_back(&integers, 30);
	vector_int_push_back(&integers, 40);
	vector_int_push_back(&integers, 50);
	printf("Vector int: ");
	print_vector_int(&integers);
	printf("Size: %zu, Capacity: %zu\n\n", vector_int_size(&integers),
		vector_int_capacity(&integers));
	vector_int_free(&integers);
}

void	test_vector_float(void)
{
	Vector_float	floats;

	vector_float_init(&floats);
	vector_float_push_back(&floats, 3.14f);
	vector_float_push_back(&floats, 2.71f);
	vector_float_push_back(&floats, 1.41f);
	printf("Vector float: ");
	print_vector_float(&floats);
	printf("Size: %zu, Capacity: %zu\n\n", vector_float_size(&floats),
		vector_float_capacity(&floats));
	vector_float_free(&floats);
}

void	test_vector_double(void)
{
	Vector_double	doubles;

	vector_double_init(&doubles);
	vector_double_push_back(&doubles, 3.141592);
	vector_double_push_back(&doubles, 2.718281);
	vector_double_push_back(&doubles, 1.414213);
	printf("Vector double: ");
	print_vector_double(&doubles);
	printf("Size: %zu, Capacity: %zu\n\n", vector_double_size(&doubles),
		vector_double_capacity(&doubles));
	vector_double_free(&doubles);
}

void	test_vector_char(void)
{
	Vector_char	characters;

	vector_char_init(&characters);
	vector_char_push_back(&characters, 'H');
	vector_char_push_back(&characters, 'e');
	vector_char_push_back(&characters, 'l');
	vector_char_push_back(&characters, 'l');
	vector_char_push_back(&characters, 'o');
	printf("Vector char: ");
	print_vector_char(&characters);
	printf("Size: %zu, Capacity: %zu\n\n", vector_char_size(&characters),
		vector_char_capacity(&characters));
	vector_char_free(&characters);
}

void	test_vector_bool(void)
{
	Vector_bool	booleans;

	vector_bool_init(&booleans);
	vector_bool_push_back(&booleans, 1);
	vector_bool_push_back(&booleans, 0);
	vector_bool_push_back(&booleans, 1);
	vector_bool_push_back(&booleans, 1);
	vector_bool_push_back(&booleans, 0);
	printf("Vector bool: ");
	print_vector_bool(&booleans);
	printf("Size: %zu, Capacity: %zu\n\n", vector_bool_size(&booleans),
		vector_bool_capacity(&booleans));
	vector_bool_free(&booleans);
}

void	test_vector_long(void)
{
	Vector_long	longs;

	vector_long_init(&longs);
	vector_long_push_back(&longs, 1000000L);
	vector_long_push_back(&longs, 2000000L);
	vector_long_push_back(&longs, 3000000L);
	printf("Vector long: ");
	print_vector_long(&longs);
	printf("Size: %zu, Capacity: %zu\n\n", vector_long_size(&longs),
		vector_long_capacity(&longs));
	vector_long_free(&longs);
}

void	test_set_operation(void)
{
	Vector_int	integers;

	vector_int_init(&integers);
	vector_int_push_back(&integers, 10);
	vector_int_push_back(&integers, 20);
	vector_int_push_back(&integers, 30);
	printf("=== Testing set operation ===\n");
	vector_int_set(&integers, 0, 999);
	printf("Vector int after set(0, 999): ");
	print_vector_int(&integers);
	vector_int_free(&integers);
}

void	test_clear_operation(void)
{
	Vector_int	integers;

	vector_int_init(&integers);
	vector_int_push_back(&integers, 10);
	vector_int_push_back(&integers, 20);
	printf("\n=== Testing clear operation ===\n");
	vector_int_clear(&integers);
	printf("Vector int after clear - Size: %zu\n", vector_int_size(&integers));
	vector_int_free(&integers);
}

int	main(void)
{
	test_vector_int();
	test_vector_float();
	test_vector_double();
	test_vector_char();
	test_vector_bool();
	test_vector_long();
	test_set_operation();
	test_clear_operation();
	printf("\nAll vectors freed successfully!\n");
	return (0);
}
