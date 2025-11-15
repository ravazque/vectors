
#ifndef VECTORS_H
# define VECTORS_H

# include "structs.h"

// ==================== generic_Vector ====================

void				vector_init_multiple(int count, ...);
void				vector_free_multiple(int count, ...);

// ==================== Vector_int ====================

void				vector_int_init(Vector_int *v);
void				vector_int_push_back(Vector_int *v, int value);
int					vector_int_get(Vector_int *v, size_t index);
void				vector_int_set(Vector_int *v, size_t index, int value);
size_t				vector_int_size(Vector_int *v);
size_t				vector_int_capacity(Vector_int *v);
void				vector_int_free(Vector_int *v);

// ==================== Vector_float ====================

void				vector_float_init(Vector_float *v);
void				vector_float_push_back(Vector_float *v, float value);
float				vector_float_get(Vector_float *v, size_t index);
void				vector_float_set(Vector_float *v, size_t index, float value);
size_t				vector_float_size(Vector_float *v);
size_t				vector_float_capacity(Vector_float *v);
void				vector_float_free(Vector_float *v);

// ==================== Vector_double ====================

void				vector_double_init(Vector_double *v);
void				vector_double_push_back(Vector_double *v, double value);
double				vector_double_get(Vector_double *v, size_t index);
void				vector_double_set(Vector_double *v, size_t index, double value);
size_t				vector_double_size(Vector_double *v);
size_t				vector_double_capacity(Vector_double *v);
void				vector_double_free(Vector_double *v);

// ==================== Vector_char ====================

void				vector_char_init(Vector_char *v);
void				vector_char_push_back(Vector_char *v, char value);
char				vector_char_get(Vector_char *v, size_t index);
void				vector_char_set(Vector_char *v, size_t index, char value);
size_t				vector_char_size(Vector_char *v);
size_t				vector_char_capacity(Vector_char *v);
void				vector_char_free(Vector_char *v);

// ==================== Vector_bool ====================

void				vector_bool_init(Vector_bool *v);
void				vector_bool_push_back(Vector_bool *v, int value);
int					vector_bool_get(Vector_bool *v, size_t index);
void				vector_bool_set(Vector_bool *v, size_t index, int value);
size_t				vector_bool_size(Vector_bool *v);
size_t				vector_bool_capacity(Vector_bool *v);
void				vector_bool_free(Vector_bool *v);

// ==================== Vector_long ====================

void				vector_long_init(Vector_long *v);
void				vector_long_push_back(Vector_long *v, long value);
long				vector_long_get(Vector_long *v, size_t index);
void				vector_long_set(Vector_long *v, size_t index, long value);
size_t				vector_long_size(Vector_long *v);
size_t				vector_long_capacity(Vector_long *v);
void				vector_long_free(Vector_long *v);

// ==================== Vector_short ====================

void				vector_short_init(Vector_short *v);
void				vector_short_push_back(Vector_short *v, short value);
short				vector_short_get(Vector_short *v, size_t index);
void				vector_short_set(Vector_short *v, size_t index, short value);
size_t				vector_short_size(Vector_short *v);
size_t				vector_short_capacity(Vector_short *v);
void				vector_short_free(Vector_short *v);

// ==================== Vector_uint ====================

void				vector_uint_init(Vector_uint *v);
void				vector_uint_push_back(Vector_uint *v, unsigned int value);
unsigned int		vector_uint_get(Vector_uint *v, size_t index);
void				vector_uint_set(Vector_uint *v, size_t index, unsigned int value);
size_t				vector_uint_size(Vector_uint *v);
size_t				vector_uint_capacity(Vector_uint *v);
void				vector_uint_free(Vector_uint *v);

// ==================== Vector_ulong ====================

void				vector_ulong_init(Vector_ulong *v);
void				vector_ulong_push_back(Vector_ulong *v, unsigned long value);
unsigned long		vector_ulong_get(Vector_ulong *v, size_t index);
void				vector_ulong_set(Vector_ulong *v, size_t index, unsigned long value);
size_t				vector_ulong_size(Vector_ulong *v);
size_t				vector_ulong_capacity(Vector_ulong *v);
void				vector_ulong_free(Vector_ulong *v);

// ==================== Vector_uchar ====================

void				vector_uchar_init(Vector_uchar *v);
void				vector_uchar_push_back(Vector_uchar *v, unsigned char value);
unsigned char		vector_uchar_get(Vector_uchar *v, size_t index);
void				vector_uchar_set(Vector_uchar *v, size_t index, unsigned char value);
size_t				vector_uchar_size(Vector_uchar *v);
size_t				vector_uchar_capacity(Vector_uchar *v);
void				vector_uchar_free(Vector_uchar *v);

// ==================== Vector_llong ====================

void				vector_llong_init(Vector_llong *v);
void				vector_llong_push_back(Vector_llong *v, long long value);
long long			vector_llong_get(Vector_llong *v, size_t index);
void				vector_llong_set(Vector_llong *v, size_t index, long long value);
size_t				vector_llong_size(Vector_llong *v);
size_t				vector_llong_capacity(Vector_llong *v);
void				vector_llong_free(Vector_llong *v);

// ==================== Vector_ullong ====================

void				vector_ullong_init(Vector_ullong *v);
void				vector_ullong_push_back(Vector_ullong *v, unsigned long long value);
unsigned long long	vector_ullong_get(Vector_ullong *v, size_t index);
void				vector_ullong_set(Vector_ullong *v, size_t index, unsigned long long value);
size_t				vector_ullong_size(Vector_ullong *v);
size_t				vector_ullong_capacity(Vector_ullong *v);
void				vector_ullong_free(Vector_ullong *v);

// ==================== Vector_sizet ====================

void				vector_sizet_init(Vector_sizet *v);
void				vector_sizet_push_back(Vector_sizet *v, size_t value);
size_t				vector_sizet_get(Vector_sizet *v, size_t index);
void				vector_sizet_set(Vector_sizet *v, size_t index, size_t value);
size_t				vector_sizet_size(Vector_sizet *v);
size_t				vector_sizet_capacity(Vector_sizet *v);
void				vector_sizet_free(Vector_sizet *v);

// ==================== Vector_ptr ====================

void				vector_ptr_init(Vector_ptr *v);
void				vector_ptr_push_back(Vector_ptr *v, void *value);
void				*vector_ptr_get(Vector_ptr *v, size_t index);
void				vector_ptr_set(Vector_ptr *v, size_t index, void *value);
size_t				vector_ptr_size(Vector_ptr *v);
size_t				vector_ptr_capacity(Vector_ptr *v);
void				vector_ptr_free(Vector_ptr *v);

#endif
