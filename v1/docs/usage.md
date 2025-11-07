
# How to Use libvectors.a in Your Project

## Quick Start

### Step 1: Copy files to your project
```bash
cp vectors.h /your/project/directory/
cp libvectors.a /your/project/directory/
```

### Step 2: Include the header in your code
```c
#include "vectors.h"
```

### Step 3: Compile with the library
```bash
cc -Wall -Wextra -Werror your_program.c -L. -lvectors -o your_program
```

## Example Integration

### Your project structure:
```
my_project/
├── main.c
├── vectors.h
└── libvectors.a
```

### main.c:
```c
#include <stdio.h>
#include "vectors.h"

int main(void) {
    Vector_int numbers;
    
    vector_int_init(&numbers);
    vector_int_push_back(&numbers, 42);
    
    printf("Number: %d\n", vector_int_get(&numbers, 0));
    
    vector_int_free(&numbers);
    return 0;
}
```

### Compile:
```bash
cc -Wall -Wextra -Werror main.c -L. -lvectors -o main
```

## Using with Makefile

Add these lines to your Makefile:

```makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L. -lvectors

NAME = my_program
SRCS = main.c other.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

## All Available Types

```c
Vector_int integers;
Vector_float floats;
Vector_double doubles;
Vector_char characters;
Vector_bool booleans;
Vector_long longs;
```

## Common Operations

### Initialize
```c
Vector_int v;
vector_int_init(&v);
```

### Add elements
```c
vector_int_push_back(&v, 10);
vector_int_push_back(&v, 20);
```

### Access elements
```c
int value = vector_int_get(&v, 0);
```

### Modify elements
```c
vector_int_set(&v, 0, 999);
```

### Get size
```c
size_t size = vector_int_size(&v);
```

### Clear
```c
vector_int_clear(&v);
```

### Free memory
```c
vector_int_free(&v);
```

## Important Notes

1. Always call `vector_TYPE_init()` before using a vector
2. Always call `vector_TYPE_free()` when done to avoid memory leaks
3. The library handles memory allocation automatically
4. Initial capacity is 4, doubles when full
5. No bounds checking in `get()`, be careful with indices
