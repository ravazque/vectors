
#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct
{
	int					*data;
	size_t				size;
	size_t				capacity;
}						Vector_int;

typedef struct
{
	float				*data;
	size_t				size;
	size_t				capacity;
}						Vector_float;

typedef struct
{
	double				*data;
	size_t				size;
	size_t				capacity;
}						Vector_double;

typedef struct
{
	char				*data;
	size_t				size;
	size_t				capacity;
}						Vector_char;

typedef struct
{
	int					*data;
	size_t				size;
	size_t				capacity;
}						Vector_bool;

typedef struct
{
	long				*data;
	size_t				size;
	size_t				capacity;
}						Vector_long;

typedef struct
{
	short				*data;
	size_t				size;
	size_t				capacity;
}						Vector_short;

typedef struct
{
	unsigned int		*data;
	size_t				size;
	size_t				capacity;
}						Vector_uint;

typedef struct
{
	unsigned long		*data;
	size_t				size;
	size_t				capacity;
}						Vector_ulong;

typedef struct
{
	unsigned char		*data;
	size_t				size;
	size_t				capacity;
}						Vector_uchar;

typedef struct
{
	long long			*data;
	size_t				size;
	size_t				capacity;
}						Vector_llong;

typedef struct
{
	unsigned long long	*data;
	size_t				size;
	size_t				capacity;
}						Vector_ullong;

typedef struct
{
	size_t				*data;
	size_t				size;
	size_t				capacity;
}						Vector_sizet;

typedef struct
{
	void				**data;
	size_t				size;
	size_t				capacity;
}						Vector_ptr;

typedef enum
{
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_CHAR,
	TYPE_BOOL,
	TYPE_LONG,
	TYPE_SHORT,
	TYPE_UINT,
	TYPE_ULONG,
	TYPE_UCHAR,
	TYPE_LLONG,
	TYPE_ULLONG,
	TYPE_SIZET,
	TYPE_PTR
}						VectorType;

#endif
