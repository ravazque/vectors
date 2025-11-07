
#ifndef VECTORS_H
# define VECTORS_H

# include "structs.h"

// ==================== generic_Vector ====================

void					vector_init_multiple(int cantidad, ...);
void					vector_free_multiple(int cantidad, ...);

// ==================== Vector_int ====================

void		vector_int_init(Vector_int *v);
void		vector_int_resize(Vector_int *v);
void		vector_int_push_back(Vector_int *v, int valor);
int			vector_int_get(Vector_int *v, size_t index);
void		vector_int_set(Vector_int *v, size_t index, int valor);
size_t		vector_int_size(Vector_int *v);
size_t		vector_int_capacity(Vector_int *v);
void		vector_int_free(Vector_int *v);

// ==================== Vector_float ====================

void		vector_float_init(Vector_float *v);
void		vector_float_resize(Vector_float *v);
void		vector_float_push_back(Vector_float *v, float valor);
float		vector_float_get(Vector_float *v, size_t index);
void		vector_float_set(Vector_float *v, size_t index, float valor);
size_t		vector_float_size(Vector_float *v);
size_t		vector_float_capacity(Vector_float *v);
void		vector_float_free(Vector_float *v);

// ==================== Vector_double ====================

void		vector_double_init(Vector_double *v);
void		vector_double_resize(Vector_double *v);
void		vector_double_push_back(Vector_double *v, double valor);
double		vector_double_get(Vector_double *v, size_t index);
void		vector_double_set(Vector_double *v, size_t index, double valor);
size_t		vector_double_size(Vector_double *v);
size_t		vector_double_capacity(Vector_double *v);
void		vector_double_free(Vector_double *v);

// ==================== Vector_char ====================

void		vector_char_init(Vector_char *v);
void		vector_char_resize(Vector_char *v);
void		vector_char_push_back(Vector_char *v, char valor);
char		vector_char_get(Vector_char *v, size_t index);
void		vector_char_set(Vector_char *v, size_t index, char valor);
size_t		vector_char_size(Vector_char *v);
size_t		vector_char_capacity(Vector_char *v);
void		vector_char_free(Vector_char *v);

// ==================== Vector_bool ====================

void		vector_bool_init(Vector_bool *v);
void		vector_bool_resize(Vector_bool *v);
void		vector_bool_push_back(Vector_bool *v, int valor);
int			vector_bool_get(Vector_bool *v, size_t index);
void		vector_bool_set(Vector_bool *v, size_t index, int valor);
size_t		vector_bool_size(Vector_bool *v);
size_t		vector_bool_capacity(Vector_bool *v);
void		vector_bool_free(Vector_bool *v);

// ==================== Vector_long ====================

void		vector_long_init(Vector_long *v);
void		vector_long_resize(Vector_long *v);
void		vector_long_push_back(Vector_long *v, long valor);
long		vector_long_get(Vector_long *v, size_t index);
void		vector_long_set(Vector_long *v, size_t index, long valor);
size_t		vector_long_size(Vector_long *v);
size_t		vector_long_capacity(Vector_long *v);
void		vector_long_free(Vector_long *v);

#endif
