# C Unit Testing Framework

easy-to-use unit testing framework for C projects.

## Features

- Zero external dependencies
- Minimal setup required
- Colored test output
- Automatic execution time measurement
- Memory leak detection
- Cross-platform compatibility
- Thread-safe implementation

## Quick Start

1. Add the framework to your project:
   ```bash
   copy test_framework.h your/project/directory
   ```

2. Create your test file:
   ```c
   #include "test_framework.h"

   void test_function() {
       ASSERT_EQ(4, 2 + 2);
   }

   int main() {
       TEST_SUITE_BEGIN();
       RUN_TEST(test_function);
       TEST_SUITE_END();
       return 0;
   }
   ```

3. Compile and run:
   ```bash
   gcc -o test_runner your_test_file.c
   ./test_runner
   ```

## Available Assertions

- `ASSERT_EQ(expected, actual)`: Compare two values for equality
- `ASSERT_STR_EQ(expected, actual)`: Compare two strings for equality
- `ASSERT_TRUE(condition)`: Verify if condition is true

## Requirements

- C compiler (GCC, Clang, or MSVC)
- Standard C library

## Project Structure

```
├── test_framework.h    # Main framework header
├── example.c          # Example usage
├── .gitignore        # Git ignore rules
└── README.md         # This file
```

## Build Instructions

### Windows (MinGW)
```bash
gcc -o test_runner example.c -Wall -Wextra -pedantic
```

### Linux/MacOS
```bash
gcc -o test_runner example.c -Wall -Wextra -pedantic
```

## Best Practices

1. Create separate test files for each module
2. Name test functions descriptively
3. Test both valid and edge cases
4. Free allocated memory in string tests
5. Keep tests focused and independent


