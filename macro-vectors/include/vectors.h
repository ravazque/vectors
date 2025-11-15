
#ifndef VECTORS_H
# define VECTORS_H

# include <stdlib.h>
# include <string.h>

# define DEFINE_VECTOR_STRUCT(type, type_name) \
    typedef struct { \
        type *data; \
        size_t size; \
        size_t capacity; \
    } Vector_##type_name;

# define DECLARE_VECTOR_FUNCTIONS(type, type_name) \
    void vector_##type_name##_init(Vector_##type_name *vector); \
    void vector_##type_name##_push_back(Vector_##type_name *vector, type value); \
    type vector_##type_name##_get(Vector_##type_name *vector, size_t index); \
    void vector_##type_name##_set(Vector_##type_name *vector, size_t index, type value); \
    size_t vector_##type_name##_size(Vector_##type_name *vector); \
    size_t vector_##type_name##_capacity(Vector_##type_name *vector); \
    void vector_##type_name##_clear(Vector_##type_name *vector); \
    void vector_##type_name##_free(Vector_##type_name *vector); \
    void vector_##type_name##_resize(Vector_##type_name *vector);

# define IMPLEMENT_INIT(type, type_name) \
    void vector_##type_name##_init(Vector_##type_name *vector) { \
        vector->size = 0; \
        vector->capacity = 4; \
        vector->data = malloc(vector->capacity * sizeof(type)); \
    }

# define IMPLEMENT_RESIZE(type, type_name) \
    void vector_##type_name##_resize(Vector_##type_name *vector) { \
        size_t new_capacity; \
        type *new_data; \
        new_capacity = vector->capacity * 2; \
        new_data = realloc(vector->data, new_capacity * sizeof(type)); \
        vector->data = new_data; \
        vector->capacity = new_capacity; \
    }

# define IMPLEMENT_PUSH_BACK(type, type_name) \
    void vector_##type_name##_push_back(Vector_##type_name *vector, type value) { \
        size_t is_full; \
        is_full = vector->size >= vector->capacity; \
        if (is_full) { \
            vector_##type_name##_resize(vector); \
        } \
        vector->data[vector->size] = value; \
        vector->size++; \
    }

# define IMPLEMENT_GET(type, type_name) \
    type vector_##type_name##_get(Vector_##type_name *vector, size_t index) { \
        return vector->data[index]; \
    }

# define IMPLEMENT_SET(type, type_name) \
    void vector_##type_name##_set(Vector_##type_name *vector, size_t index, type value) { \
        int is_valid; \
        is_valid = index < vector->size; \
        if (is_valid) { \
            vector->data[index] = value; \
        } \
    }

# define IMPLEMENT_SIZE(type, type_name) \
    size_t vector_##type_name##_size(Vector_##type_name *vector) { \
        return vector->size; \
    }

# define IMPLEMENT_CAPACITY(type, type_name) \
    size_t vector_##type_name##_capacity(Vector_##type_name *vector) { \
        return vector->capacity; \
    }

# define IMPLEMENT_CLEAR(type, type_name) \
    void vector_##type_name##_clear(Vector_##type_name *vector) { \
        vector->size = 0; \
    }

# define IMPLEMENT_FREE(type, type_name) \
    void vector_##type_name##_free(Vector_##type_name *vector) { \
        free(vector->data); \
        vector->data = NULL; \
        vector->size = 0; \
        vector->capacity = 0; \
    }

# define IMPLEMENT_VECTOR(type, type_name) \
    IMPLEMENT_INIT(type, type_name) \
    IMPLEMENT_RESIZE(type, type_name) \
    IMPLEMENT_PUSH_BACK(type, type_name) \
    IMPLEMENT_GET(type, type_name) \
    IMPLEMENT_SET(type, type_name) \
    IMPLEMENT_SIZE(type, type_name) \
    IMPLEMENT_CAPACITY(type, type_name) \
    IMPLEMENT_CLEAR(type, type_name) \
    IMPLEMENT_FREE(type, type_name)

DEFINE_VECTOR_STRUCT(int, int)
DEFINE_VECTOR_STRUCT(float, float)
DEFINE_VECTOR_STRUCT(double, double)
DEFINE_VECTOR_STRUCT(char, char)
DEFINE_VECTOR_STRUCT(int, bool)
DEFINE_VECTOR_STRUCT(long, long)

DECLARE_VECTOR_FUNCTIONS(int, int)
DECLARE_VECTOR_FUNCTIONS(float, float)
DECLARE_VECTOR_FUNCTIONS(double, double)
DECLARE_VECTOR_FUNCTIONS(char, char)
DECLARE_VECTOR_FUNCTIONS(int, bool)
DECLARE_VECTOR_FUNCTIONS(long, long)

#endif
