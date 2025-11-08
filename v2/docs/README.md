
# Vectors V2 - Dynamic Vector Library in C (Modular)

Modular implementation of dynamic vectors in C, similar to C++ `std::vector`, with separate files per type.

## Main Features

- Dynamic vectors for C primitive types
- **Modular** implementation with separate files per type
- Automatic capacity growth (doubling)
- Utility functions for multiple vector management
- Consistent and clean API
- Manual memory management

## Available Types

### Basic Types (6)

| C Type | Vector Type | C++ Equivalent |
|--------|-------------|----------------|
| `int` | `Vector_int` | `std::vector<int>` |
| `float` | `Vector_float` | `std::vector<float>` |
| `double` | `Vector_double` | `std::vector<double>` |
| `char` | `Vector_char` | `std::vector<char>` |
| `int` (as bool) | `Vector_bool` | `std::vector<bool>` |
| `long` | `Vector_long` | `std::vector<long>` |

### Extended Types (8)

| C Type | Vector Type | C++ Equivalent |
|--------|-------------|----------------|
| `short` | `Vector_short` | `std::vector<short>` |
| `unsigned int` | `Vector_uint` | `std::vector<unsigned int>` |
| `unsigned long` | `Vector_ulong` | `std::vector<unsigned long>` |
| `unsigned char` | `Vector_uchar` | `std::vector<unsigned char>` |
| `long long` | `Vector_llong` | `std::vector<long long>` |
| `unsigned long long` | `Vector_ullong` | `std::vector<unsigned long long>` |
| `size_t` | `Vector_sizet` | `std::vector<size_t>` |
| `void*` | `Vector_ptr` | `std::vector<void*>` |

**Total: 14 fully implemented vector types**

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

V2 includes a comprehensive test suite in `test/test.c` that verifies all 14 vector types:

### Basic Types Tests (6)
- Integer vector (`int`)
- Float vector (`float`)
- Double vector (`double`)
- Character vector (`char`)
- Boolean vector (`bool`)
- Long vector (`long`)

### Extended Types Tests (8)
- Short vector (`short`)
- Unsigned integer vector (`unsigned int`)
- Unsigned long vector (`unsigned long`)
- Unsigned char vector (`unsigned char`)
- Long long vector (`long long`)
- Unsigned long long vector (`unsigned long long`)
- Size_t vector (`size_t`)
- Pointer vector (`void*`)

### Utility Functions Tests
- Multiple initialization
- Multiple freeing

**Total: 14 type tests + 2 utility tests = 16 comprehensive tests**

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
    TYPE_SHORT,
    TYPE_UINT,
    TYPE_ULONG,
    TYPE_UCHAR,
    TYPE_LLONG,
    TYPE_ULLONG,
    TYPE_SIZET,
    TYPE_PTR
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

## Differences from V1

| Feature | V1 (Macros) | V2 (Modular) |
|---------|-------------|--------------|
| Implementation | Preprocessor macros | Separate files |
| Organization | One source file | 15 source files |
| Available types | 6 basic types | 14 types (6 basic + 8 extended) |
| Maintainability | Less code, more abstract | More code, more explicit |
| Debugging | Harder | Easier |
| Extensibility | Add one macro line | Create new file (~70 lines) |
| Utility functions | Not included | `init_multiple`, `free_multiple` |
| Test suite | Basic example | Comprehensive suite (16 tests) |
| Extended types | No | Yes (unsigned, long long, size_t, ptr) |

## Important Notes

- **Always** call `vector_TYPE_free()` to avoid memory leaks
- Indices in `get()` are not validated, make sure they are correct
- `set()` validates the index before modifying
- Initial capacity is 4 and doubles automatically
- `_multiple` functions use variable arguments (varargs)
- Code compatible with strict standards (42, MISRA, etc.)
- Compiles with `-Wall -Wextra -Werror` without warnings
- Tests run automatically with `make test`
- All 14 types are **fully implemented and tested**

## Type-Specific Considerations

### Vector_ptr (void*)
- Stores generic pointers (`void*`)
- Can store `NULL` pointers
- User is responsible for managing pointed-to memory
- Does not automatically free pointed-to objects

### Unsigned Types
- `Vector_uint`, `Vector_ulong`, `Vector_uchar`, `Vector_ullong`
- Useful for values that are always non-negative
- Provides full range of positive values for the type

### Long Long Types
- `Vector_llong`, `Vector_ullong`
- Support for very large integers (64-bit)
- Useful for timestamps, large counters, etc.

### Vector_sizet
- Uses `size_t` type (platform-dependent unsigned integer)
- Ideal for array indices, object sizes, memory operations
- Guaranteed to hold the size of any object
