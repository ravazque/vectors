
# Vectors Library

Static library implementation of dynamic vectors in C using macros, similar to C++ std::vector.

- [Usage](https://github.com/ravazque/vectors/blob/main/docs/usage.md) | Expansion of documentation for using the library in other programs.

## Supported Types

- `Vector_int` (std::vector<int>)
- `Vector_float` (std::vector<float>)
- `Vector_double` (std::vector<double>)
- `Vector_char` (std::vector<char>)
- `Vector_bool` (std::vector<bool>)
- `Vector_long` (std::vector<long>)

## Available Functions

Each type has the following functions:

- `vector_TYPE_init(v)` - Initialize the vector
- `vector_TYPE_push_back(v, value)` - Add element at the end
- `vector_TYPE_get(v, index)` - Get element at position
- `vector_TYPE_set(v, index, value)` - Modify element
- `vector_TYPE_size(v)` - Get current size
- `vector_TYPE_capacity(v)` - Get capacity
- `vector_TYPE_clear(v)` - Empty the vector (keeps memory)
- `vector_TYPE_free(v)` - Free memory completely

## Building the Library

```bash
make        # Build libvectors.a
make test   # Build and run example
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```

## Using the Library

### In your project:

1. Copy `vectors.h` and `libvectors.a` to your project
2. Include the header in your source files
3. Link with the library

```c
#include "vectors.h"

int main(void) {
    Vector_int numbers;
    vector_int_init(&numbers);
    
    vector_int_push_back(&numbers, 10);
    vector_int_push_back(&numbers, 20);
    vector_int_push_back(&numbers, 30);
    
    int first = vector_int_get(&numbers, 0);
    
    vector_int_set(&numbers, 1, 999);
    
    size_t size = vector_int_size(&numbers);
    
    vector_int_clear(&numbers);
    
    vector_int_free(&numbers);
    
    return 0;
}
```

### Compilation:

```bash
cc -Wall -Wextra -Werror your_program.c -L. -lvectors -o your_program
```

Or add to your Makefile:

```makefile
LDFLAGS = -L/path/to/library -lvectors
```

---

>[!NOTE]
>- Initial capacity is 4 elements
>- Capacity doubles automatically when full
>- Always call `vector_TYPE_free()` to avoid memory leaks
>- Indices are not validated in `get()`, only in `set()`
