
# Vectors V2 - Dynamic Vector Library in C (Modular)

Modular implementation of dynamic vectors in C, similar to C++ `std::vector`, with separate files per type.

## Main Features

- Dynamic vectors for C primitive types
- **Modular** implementation with separate files per type
- Automatic capacity growth (doubling)
- Utility functions for multiple vector management
- Consistent and clean API
- No `for` loops or ternary operators
- Manual memory management

## Available Types

| C Type | Vector Type | C++ Equivalent |
|--------|-------------|----------------|
| `int` | `Vector_int` | `std::vector<int>` |
| `float` | `Vector_float` | `std::vector<float>` |
| `double` | `Vector_double` | `std::vector<double>` |
| `char` | `Vector_char` | `std::vector<char>` |
| `int` | `Vector_bool` | `std::vector<bool>` |
| `long` | `Vector_long` | `std::vector<long>` |

## Functions API

### Type-Specific Functions

Each vector type has the following functions (replace `TYPE` with the corresponding type):

#### Initialization and Cleanup
```c
void vector_TYPE_init(Vector_TYPE *v);       // Initialize the vector
void vector_TYPE_free(Vector_TYPE *v);       // Free all memory
```

#### Data Manipulation
```c
void vector_TYPE_push_back(Vector_TYPE *v, TYPE value);  // Add element at the end
TYPE vector_TYPE_get(Vector_TYPE *v, size_t index);      // Get element
void vector_TYPE_set(Vector_TYPE *v, size_t index, TYPE value); // Modify element
```

#### Information
```c
size_t vector_TYPE_size(Vector_TYPE *v);     // Returns current size
size_t vector_TYPE_capacity(Vector_TYPE *v); // Returns total capacity
```

### Utility Functions

Functions to manage multiple vectors at once:

```c
void vector_init_multiple(int count, ...);   // Initialize multiple vectors
void vector_free_multiple(int count, ...);   // Free multiple vectors
```

Using utility functions:
```c
Vector_int integers;
Vector_float decimals;
Vector_char letters;

// Initialize multiple vectors at once
vector_init_multiple(3,
    TYPE_INT, &integers,
    TYPE_FLOAT, &decimals,
    TYPE_CHAR, &letters);

// Use the vectors...

// Free multiple vectors at once
vector_free_multiple(3,
    TYPE_INT, &integers,
    TYPE_FLOAT, &decimals,
    TYPE_CHAR, &letters);
```

## Basic Usage Example

```c
#include "vectors.h"
#include <stdio.h>

int main(void)
{
    Vector_int numbers;

    // Initialize
    vector_int_init(&numbers);

    // Add elements
    vector_int_push_back(&numbers, 10);
    vector_int_push_back(&numbers, 20);
    vector_int_push_back(&numbers, 30);
    vector_int_push_back(&numbers, 40);
    vector_int_push_back(&numbers, 50);

    // Access elements
    printf("First element: %d\n", vector_int_get(&numbers, 0));

    // Modify elements
    vector_int_set(&numbers, 2, 999);

    // Vector information
    printf("Size: %zu\n", vector_int_size(&numbers));
    printf("Capacity: %zu\n", vector_int_capacity(&numbers));

    // Iterate over elements
    size_t i = 0;
    while (i < vector_int_size(&numbers))
    {
        printf("numbers[%zu] = %d\n", i, vector_int_get(&numbers, i));
        i++;
    }

    // Free memory
    vector_int_free(&numbers);

    return 0;
}
```

## Example with Multiple Vectors

```c
#include "vectors.h"
#include <stdio.h>

int main(void)
{
    Vector_int integers;
    Vector_float decimals;
    Vector_char letters;

    // Initialize all at once
    vector_init_multiple(3,
        TYPE_INT, &integers,
        TYPE_FLOAT, &decimals,
        TYPE_CHAR, &letters);

    // Use each vector
    vector_int_push_back(&integers, 42);
    vector_int_push_back(&integers, 84);

    vector_float_push_back(&decimals, 3.14f);
    vector_float_push_back(&decimals, 2.71f);

    vector_char_push_back(&letters, 'H');
    vector_char_push_back(&letters, 'i');

    // Display values
    printf("Int: %d\n", vector_int_get(&integers, 0));
    printf("Float: %.2f\n", vector_float_get(&decimals, 0));
    printf("Char: %c\n", vector_char_get(&letters, 0));

    // Free all at once
    vector_free_multiple(3,
        TYPE_INT, &integers,
        TYPE_FLOAT, &decimals,
        TYPE_CHAR, &letters);

    return 0;
}
```

## Compilation

```bash
make           # Build libvectors.a
make test      # Build and run the test suite
make clean     # Remove object files
make fclean    # Remove everything (includes library and tests)
make re        # Rebuild from scratch
```

This generates:
- `libvectors.a` - Static library
- `test_vectors` - Test executable (with `make test`)

## Test Suite

V2 includes a complete test suite in `test/test.c` that verifies:

- Integer vector (int)
- Float vector (float)
- Double vector (double)
- Character vector (char)
- Boolean vector (bool)
- Long vector (long)
- Multiple initialization
- Multiple freeing

Run the tests with:
```bash
make test
```

## Using in Your Projects

### Option 1: Direct linking
```bash
cc -Wall -Wextra -Werror -Iinclude your_program.c -L. -lvectors -o your_program
```

### Option 2: Makefile
```makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror -I/path/to/v2/include
LDFLAGS = -L/path/to/v2 -lvectors

your_program: your_program.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
```

### Option 3: Copy files
1. Copy `include/vectors.h` and `include/structs.h` to your project
2. Copy `libvectors.a` to your project
3. Include the header: `#include "vectors.h"`
4. Link with `-lvectors`

## Technical Implementation

### Modular Approach

This version uses **separate files** for each type:

```
src/
├── vector_int.c       # Implementation for int
├── vector_float.c     # Implementation for float
├── vector_double.c    # Implementation for double
├── vector_char.c      # Implementation for char
├── vector_bool.c      # Implementation for bool
├── vector_long.c      # Implementation for long
└── vector_utils.c     # Utility functions
```

### Advantages
- Organized and maintainable code
- Each type in its own file
- Easy debugging
- Independent compilation per module
- Extensible (easy to add new types)

### Internal Structure
```c
typedef struct {
    type *data;       // Dynamic array of elements
    size_t size;      // Current number of elements
    size_t capacity;  // Total reserved capacity
} Vector_TYPE;
```

### Enumerated Types (for utility functions)
```c
typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
    TYPE_BOOL,
    TYPE_LONG,
    // ... other types
} VectorType;
```

## Detailed Behavior

| Aspect | Behavior |
|--------|----------|
| Initial capacity | 4 elements |
| Growth strategy | Doubling (x2) |
| Memory management | Manual (requires `_free`) |
| Index validation | Only in `set()`, not in `get()` |
| Resizing | Automatic on `push_back` |

## Project Files

```
v2/
├── include/
│   ├── vectors.h          # Function declarations
│   └── structs.h          # Structure definitions
├── src/
│   ├── vector_int.c       # int implementation
│   ├── vector_float.c     # float implementation
│   ├── vector_double.c    # double implementation
│   ├── vector_char.c      # char implementation
│   ├── vector_bool.c      # bool implementation
│   ├── vector_long.c      # long implementation
│   └── vector_utils.c     # Utility functions
├── test/
│   └── test.c             # Complete test suite
├── docs/
│   └── README.md          # This documentation
└── Makefile               # Build system
```

## Differences from V1

| Feature | V1 (Macros) | V2 (Modular) |
|---------|-------------|--------------|
| Implementation | Preprocessor macros | Separate files |
| Organization | One source file | Multiple files |
| Maintainability | Less code, more abstract | More code, more explicit |
| Debugging | Harder | Easier |
| Extensibility | Add one macro line | Create new file |
| Utility functions | Not included | `init_multiple`, `free_multiple` |
| Test suite | Basic example | Complete suite |

## Important Notes

- **Always** call `vector_TYPE_free()` to avoid memory leaks
- Indices in `get()` are not validated, make sure they are correct
- `set()` validates the index before modifying
- Initial capacity is 4 and doubles automatically
- `_multiple` functions use variable arguments (varargs)
- Code compatible with strict standards (42, MISRA, etc.)
- Compiles with `-Wall -Wextra -Werror` without warnings
- Tests run automatically with `make test`

## Additional Types in structs.h

Besides the basic types, `structs.h` includes definitions for:
- `Vector_short`, `Vector_uint`, `Vector_ulong`, `Vector_uchar`
- `Vector_llong`, `Vector_ullong`, `Vector_sizet`
- `Vector_ptr` (for generic pointers)

These types are defined but not implemented. You can implement them following the same pattern as the basic types.
