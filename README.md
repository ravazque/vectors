
# Vectors - Dynamic Vector Library in C

Dynamic vector implementations in C that emulate the behavior of C++ `std::vector`.

This repository contains **two different versions** of the same library, each with its own design approach and implementation.

## Available Versions

### [Macro Approach](macro-vectors/docs/README.md)
Implementation using **preprocessor macros** to generate code.

**Approach:** Code generation via macros
**Files:** Compact code, all in one source file
**Ideal for:** Projects seeking minimalism and DRY (Don't Repeat Yourself)

### [Modular Approach](modular-vectors/docs/README.md)
**Modular** implementation with separate files per type.

**Approach:** Explicit code in separate files
**Files:** One file per vector type
**Ideal for:** Projects seeking clarity and ease of maintenance

## Version Comparison

| Feature | Macro Approach | Modular Approach |
|---------|-------------|--------------|
| **Implementation Style** | Preprocessor macros | Separate files per type |
| **Available types** | 6 basic types | 14 types (including extended types) |
| **Readability** | Requires understanding macros | Explicit and direct code |
| **Maintainability** | Modifying macros affects everything | Each type independent |
| **Debugging** | Harder (generated code) | Easier (direct code) |
| **Extensibility** | Add 1 macro line | Create new .c file |
| **Compile time** | Slightly faster | Slightly slower |
| **Utility functions** | Not included | `init_multiple`, `free_multiple` |
| **Test suite** | Basic example | Complete and exhaustive suite (14 tests) |
| **`clear()` function** | Included | Not included |
| **Binary size** | Identical | Identical |

## Advantages and Disadvantages

### Macro Approach

#### Advantages
- Very compact source code (DRY principle)
- Easy to add new types (one line)
- Fewer files to maintain
- All implementations automatically consistent
- Good for understanding C metaprogramming
- Includes `clear()` function to empty vectors

#### Disadvantages
- Requires understanding preprocessor macros
- More complex debugging (debugger shows expanded code)
- Compiler error messages can be confusing
- Less fine control over each type
- Doesn't include utility functions like `init_multiple`

### Modular Approach

#### Advantages
- Explicit and easy-to-read code
- Simple debugging (direct code)
- Each type is independent and modifiable
- Easy to understand for beginners
- Includes utility functions (`init_multiple`, `free_multiple`)
- Clearer compiler error messages
- Better for learning
- Extended type support (14 total type)
- Includes specialized types: short, unsigned variants, long long, size_t, and generic pointers

#### Disadvantages
- More source code (repetition between types)
- More files to maintain
- Adding a type requires creating a complete file
- Doesn't include `clear()` function
- Global changes require modifying multiple files

## Common API

Both versions share the same basic API:

```c
// Initialization
void vector_TYPE_init(Vector_TYPE *v);

// Add elements
void vector_TYPE_push_back(Vector_TYPE *v, TYPE value);

// Access elements
TYPE vector_TYPE_get(Vector_TYPE *v, size_t index);

// Modify elements
void vector_TYPE_set(Vector_TYPE *v, size_t index, TYPE value);

// Information
size_t vector_TYPE_size(Vector_TYPE *v);
size_t vector_TYPE_capacity(Vector_TYPE *v);

// Free memory
void vector_TYPE_free(Vector_TYPE *v);
```

### API Differences

**Macro Approach only:**
```c
void vector_TYPE_clear(Vector_TYPE *v);  // Empty the vector keeping capacity
```

**Modular Approach only:**
```c
void vector_init_multiple(int count, ...);  // Initialize multiple vectors
void vector_free_multiple(int count, ...);  // Free multiple vectors
```

## Available Types

### Both Versions
- `Vector_int` - Integer vector (`int`)
- `Vector_float` - Float vector (`float`)
- `Vector_double` - Double precision vector (`double`)
- `Vector_char` - Character vector (`char`)
- `Vector_bool` - Boolean vector (`int` as bool)
- `Vector_long` - Long integer vector (`long`)

### Modular Approach Only (Additional 8 Types)
- `Vector_short` - Short integer vector (`short`)
- `Vector_uint` - Unsigned integer vector (`unsigned int`)
- `Vector_ulong` - Unsigned long vector (`unsigned long`)
- `Vector_uchar` - Unsigned character vector (`unsigned char`)
- `Vector_llong` - Long long integer vector (`long long`)
- `Vector_ullong` - Unsigned long long vector (`unsigned long long`)
- `Vector_sizet` - Size type vector (`size_t`)
- `Vector_ptr` - Generic pointer vector (`void*`)

## Usage Example (Both Versions)

```c
#include "vectors.h"
#include <stdio.h>

int main(void)
{
    Vector_int numbers;

    vector_int_init(&numbers);

    vector_int_push_back(&numbers, 10);
    vector_int_push_back(&numbers, 20);
    vector_int_push_back(&numbers, 30);

    printf("Element 0: %d\n", vector_int_get(&numbers, 0));
    printf("Size: %zu\n", vector_int_size(&numbers));

    vector_int_set(&numbers, 1, 999);

    vector_int_free(&numbers);

    return 0;
}
```

## Installation and Usage

Both versions compile the same way:

```bash
# Enter the desired version directory
cd macro-vectors  # or cd modular-vectors

# Build the library
make

# Run tests/test
make test

# Clean
make clean
make fclean
```

### Using in Projects

```bash
# Compile with Macro Approach
cc -Wall -Wextra -Werror your_program.c -Lmacro-vectors -lvectors -o your_program

# Compile with Modular Approach
cc -Wall -Wextra -Werror -Imodular-vectors/include your_program.c -Lmodular-vectors -lvectors -o your_program
```

## Common Features

Both versions share:

- **Initial capacity:** 4 elements
- **Growth strategy:** Doubling (x2)
- **Memory management:** Manual (you must call `_free`)
- **Validation:** Only in `set()`, not in `get()`
- **Strict compilation:** `-Wall -Wextra -Werror`

## Identical Behavior

Runtime behavior is **identical** between both versions:

- Same memory consumption
- Same execution speed
- Same capacity and growth
- Same return values
- Same error handling

The only real difference is in **how the source code is organized**.

## When to Use Each Version

### Use Macro Approach if:
- You prefer compact and DRY code
- You understand and feel comfortable with macros
- You want to minimize the number of files
- You need the `clear()` function
- You value automatic consistency between types
- You're learning about C metaprogramming

### Use Modular Approach if:
- You prefer explicit and clear code
- You're learning C or dynamic vectors
- You need to debug frequently
- You work in a team (easier to review)
- You need utility functions (`init_multiple`, `free_multiple`)
- You value modularity and separation of concerns
- You need extended types (unsigned variants, long long, size_t, pointers)
- You need a production-ready, well-tested library
