
#include "../include/vectors.h"

void	print_separator(void)
{
	printf("\n========================================\n");
}

void	test_vector_int(void)
{
	Vector_int	v;
	size_t		i;

	printf("TEST VECTOR INT\n");
	vector_int_init(&v);

	printf("Initial capacity: %zu\n", vector_int_capacity(&v));
	printf("Initial size: %zu\n", vector_int_size(&v));

	printf("\nAdding elements: 10, 20, 30, 40, 50\n");
	vector_int_push_back(&v, 10);
	vector_int_push_back(&v, 20);
	vector_int_push_back(&v, 30);
	vector_int_push_back(&v, 40);
	vector_int_push_back(&v, 50);

	printf("Size after push_back: %zu\n", vector_int_size(&v));
	printf("Capacity after push_back: %zu\n", vector_int_capacity(&v));

	printf("\nVector content:\n");
	i = 0;
	while (i < vector_int_size(&v))
	{
		printf("v[%zu] = %d\n", i, vector_int_get(&v, i));
		i++;
	}

	printf("\nModifying v[2] to 999\n");
	vector_int_set(&v, 2, 999);
	printf("New value of v[2] = %d\n", vector_int_get(&v, 2));

	vector_int_free(&v);
	printf("\nVector freed successfully\n");
}

void	test_vector_float(void)
{
	Vector_float	v;
	size_t			i;

	printf("TEST VECTOR FLOAT\n");
	vector_float_init(&v);

	printf("Adding elements: 1.1, 2.2, 3.3, 4.4\n");
	vector_float_push_back(&v, 1.1f);
	vector_float_push_back(&v, 2.2f);
	vector_float_push_back(&v, 3.3f);
	vector_float_push_back(&v, 4.4f);

	printf("\nVector content:\n");
	i = 0;
	while (i < vector_float_size(&v))
	{
		printf("v[%zu] = %.2f\n", i, vector_float_get(&v, i));
		i++;
	}

	vector_float_free(&v);
	printf("\nVector freed successfully\n");
}

void	test_vector_double(void)
{
	Vector_double	v;
	size_t			i;

	printf("TEST VECTOR DOUBLE\n");
	vector_double_init(&v);

	printf("Adding elements: 3.141592, 2.718281, 1.414213\n");
	vector_double_push_back(&v, 3.141592);
	vector_double_push_back(&v, 2.718281);
	vector_double_push_back(&v, 1.414213);

	printf("\nVector content:\n");
	i = 0;
	while (i < vector_double_size(&v))
	{
		printf("v[%zu] = %.6f\n", i, vector_double_get(&v, i));
		i++;
	}

	vector_double_free(&v);
	printf("\nVector freed successfully\n");
}

void	test_vector_char(void)
{
	Vector_char	v;
	size_t		i;

	printf("TEST VECTOR CHAR\n");
	vector_char_init(&v);

	printf("Adding characters: 'H', 'e', 'l', 'l', 'o'\n");
	vector_char_push_back(&v, 'H');
	vector_char_push_back(&v, 'e');
	vector_char_push_back(&v, 'l');
	vector_char_push_back(&v, 'l');
	vector_char_push_back(&v, 'o');

	printf("\nVector content:\n");
	i = 0;
	while (i < vector_char_size(&v))
	{
		printf("v[%zu] = '%c'\n", i, vector_char_get(&v, i));
		i++;
	}

	vector_char_free(&v);
	printf("\nVector freed successfully\n");
}

void	test_vector_bool(void)
{
	Vector_bool	v;
	size_t		i;

	printf("TEST VECTOR BOOL\n");
	vector_bool_init(&v);

	printf("Adding values: 1, 0, 1, 1, 0\n");
	vector_bool_push_back(&v, 1);
	vector_bool_push_back(&v, 0);
	vector_bool_push_back(&v, 1);
	vector_bool_push_back(&v, 1);
	vector_bool_push_back(&v, 0);

	printf("\nVector content:\n");
	i = 0;
	while (i < vector_bool_size(&v))
	{
		printf("v[%zu] = %d\n", i, vector_bool_get(&v, i));
		i++;
	}

	vector_bool_free(&v);
	printf("\nVector freed successfully\n");
}

void	test_vector_long(void)
{
	Vector_long	v;
	size_t		i;

	printf("TEST VECTOR LONG\n");
	vector_long_init(&v);

	printf("Adding elements: 1000000, 2000000, 3000000\n");
	vector_long_push_back(&v, 1000000L);
	vector_long_push_back(&v, 2000000L);
	vector_long_push_back(&v, 3000000L);

	printf("\nVector content:\n");
	i = 0;
	while (i < vector_long_size(&v))
	{
		printf("v[%zu] = %ld\n", i, vector_long_get(&v, i));
		i++;
	}

	vector_long_free(&v);
	printf("\nVector freed successfully\n");
}

void	test_multiple_init(void)
{
	Vector_int		v_int;
	Vector_float	v_float;
	Vector_char		v_char;
	size_t			i;

	printf("TEST MULTIPLE INITIALIZATION\n");

	printf("Initializing 3 vectors with vector_init_multiple\n");
	vector_init_multiple(3,
		TYPE_INT, &v_int,
		TYPE_FLOAT, &v_float,
		TYPE_CHAR, &v_char);

	printf("Adding data to each vector...\n");
	vector_int_push_back(&v_int, 42);
	vector_int_push_back(&v_int, 84);

	vector_float_push_back(&v_float, 9.99f);
	vector_float_push_back(&v_float, 8.88f);

	vector_char_push_back(&v_char, 'A');
	vector_char_push_back(&v_char, 'B');

	printf("\nINT Vector:\n");
	i = 0;
	while (i < vector_int_size(&v_int))
	{
		printf("  [%zu] = %d\n", i, vector_int_get(&v_int, i));
		i++;
	}

	printf("\nFLOAT Vector:\n");
	i = 0;
	while (i < vector_float_size(&v_float))
	{
		printf("  [%zu] = %.2f\n", i, vector_float_get(&v_float, i));
		i++;
	}

	printf("\nCHAR Vector:\n");
	i = 0;
	while (i < vector_char_size(&v_char))
	{
		printf("  [%zu] = '%c'\n", i, vector_char_get(&v_char, i));
		i++;
	}

	printf("\nFreeing multiple vectors with vector_free_multiple\n");
	vector_free_multiple(3,
		TYPE_INT, &v_int,
		TYPE_FLOAT, &v_float,
		TYPE_CHAR, &v_char);

	printf("Vectors freed successfully\n");
}

int	main(void)
{
	printf("\n========== VECTORS LIBRARY - TEST SUITE ==========\n");

	print_separator();
	test_vector_int();

	print_separator();
	test_vector_float();

	print_separator();
	test_vector_double();

	print_separator();
	test_vector_char();

	print_separator();
	test_vector_bool();

	print_separator();
	test_vector_long();

	print_separator();
	test_multiple_init();

	print_separator();
	printf("\n========== ALL TESTS COMPLETED ==========\n\n");

	return (0);
}
