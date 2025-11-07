
# Vectors V1 - Dynamic Vector Library in C (Macros)

Dynamic vector implementation in C using **preprocessor macros**, similar to C++ `std::vector`.

## Main Features

- Dynamic vectors for C primitive types
- Implementation using **preprocessor macros**
- Automatic capacity growth (doubling)
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

Each vector type has the following functions (replace `TYPE` with the corresponding type):

### Initialization and Cleanup
```c
void vector_TYPE_init(Vector_TYPE *v);       // Initialize the vector
void vector_TYPE_free(Vector_TYPE *v);       // Free all memory
void vector_TYPE_clear(Vector_TYPE *v);      // Empty the vector (keeps capacity)
```

### Data Manipulation
```c
void vector_TYPE_push_back(Vector_TYPE *v, TYPE value);  // Add element at the end
TYPE vector_TYPE_get(Vector_TYPE *v, size_t index);      // Get element
void vector_TYPE_set(Vector_TYPE *v, size_t index, TYPE value); // Modify element
```

### Information
```c
size_t vector_TYPE_size(Vector_TYPE *v);     // Returns current size
size_t vector_TYPE_capacity(Vector_TYPE *v); // Returns total capacity
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

    // Access elements
    printf("First element: %d\n", vector_int_get(&numbers, 0));

    // Modify elements
    vector_int_set(&numbers, 1, 999);

    // Vector information
    printf("Size: %zu\n", vector_int_size(&numbers));
    printf("Capacity: %zu\n", vector_int_capacity(&numbers));

    // Clear (empties but keeps memory)
    vector_int_clear(&numbers);

    // Free memory
    vector_int_free(&numbers);

    return 0;
}
```

## Example with Different Types

```c
Vector_float decimals;
Vector_char letters;

vector_float_init(&decimals);
vector_float_push_back(&decimals, 3.14f);
vector_float_push_back(&decimals, 2.71f);

vector_char_init(&letters);
vector_char_push_back(&letters, 'H');
vector_char_push_back(&letters, 'i');

printf("Float: %.2f\n", vector_float_get(&decimals, 0));
printf("Char: %c\n", vector_char_get(&letters, 0));

vector_float_free(&decimals);
vector_char_free(&letters);
```

## Compilation

```bash
make           # Build libvectors.a
make test      # Build and run the example
make clean     # Remove object files
make fclean    # Remove everything (includes library)
make re        # Rebuild from scratch
```

This generates:
- `libvectors.a` - Static library
- `test` - Demo executable

## Using in Your Projects

### Option 1: Direct linking
```bash
cc -Wall -Wextra -Werror your_program.c -L. -lvectors -o your_program
```

### Option 2: Makefile
```makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L/path/to/v1 -lvectors

your_program: your_program.c
	$(CC) $(CFLAGS) $< $(LDFLAGS) -o $@
```

### Option 3: Copy files
1. Copy `include/vectors.h` to your project
2. Copy `libvectors.a` to your project
3. Include the header: `#include "vectors.h"`
4. Link with `-lvectors`

## Technical Implementation

### Macro Approach

This version uses **preprocessor macros** to generate code:

```c
// Define the structure
DEFINE_VECTOR_STRUCT(int, int)

// Declare the functions
DECLARE_VECTOR_FUNCTIONS(int, int)

// Implement all functions
IMPLEMENT_VECTOR(int, int)
```

### Advantages
- Compact and DRY (Don't Repeat Yourself) code
- Easy to add new types
- No runtime overhead
- Everything generated at compile time

### Internal Structure
```c
typedef struct {
    type *data;       // Dynamic array of elements
    size_t size;      // Current number of elements
    size_t capacity;  // Total reserved capacity
} Vector_TYPE;
```

## Detailed Behavior

| Aspect | Behavior |
|--------|----------|
| Initial capacity | 4 elements |
| Growth strategy | Doubling (x2) |
| Memory management | Manual (requires `_free`) |
| Index validation | Only in `set()`, not in `get()` |
| `clear()` vs `free()` | `clear()` empties but keeps capacity |

## Project Files

```
v1/
├── include/
│   └── vectors.h          # Macros and declarations
├── src/
│   ├── vectors.c          # Generated implementations
│   └── test.c             # Usage examples
├── docs/
│   └── README.md          # This documentation
└── Makefile               # Build system
```

## Important Notes

- **Always** call `vector_TYPE_free()` to avoid memory leaks
- Indices in `get()` are not validated, make sure they are correct
- `clear()` only resets the size, doesn't free memory
- Initial capacity is 4 and doubles automatically
- Code compatible with strict standards (42, MISRA, etc.)
- Compiles with `-Wall -Wextra -Werror` without warnings

