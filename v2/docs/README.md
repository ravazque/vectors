
# Vectors Library

Static library implementation of dynamic vectors in C using macros, similar to C++ std::vector.

## Supported Types

- `Vector_int` (std::vector<int>)
- `Vector_float` (std::vector<float>)
- `Vector_double` (std::vector<double>)
- `Vector_char` (std::vector<char>)
- `Vector_bool` (std::vector<bool>)
- `Vector_long` (std::vector<long>)

## Building the Library

```bash
make        # Build libvectors.a
make clean  # Remove object files
make fclean # Remove all generated files
make re     # Rebuild everything
```
