````markdown
# C Data Input and Manipulation Examples

This repository contains a C program (`main.c`) that demonstrates fundamental concepts of inputting various data types (integers, doubles, characters, and strings) from the user, as well as performing basic output formatting and type casting.

## Features

- **Diverse Input Handling**: Reads `int`, `double`, `char`, and string (`char[]`) from user input.
- **Formatted Output**: Displays all input values on a single line, separated by spaces.
- **Reverse Output**: Prints the entered values in reverse order.
- **Type Casting Demonstration**: Shows how to cast a `double` to an `int` and displays the result.

## Getting Started

These instructions will help you compile and run the program on your local machine.

### Prerequisites

You need a C compiler installed on your system, such as GCC (GNU Compiler Collection) or Clang.

### Compiling and Running

1. **Save the Code**  
   Save the content of `main.c` to a file named `main.c` on your computer.

2. **Compile the Program**  
   Open a terminal or command prompt, navigate to the directory where you saved `main.c`, and run:

   ```bash
   gcc main.c -o data_examples
````

This command compiles `main.c` and creates an executable file named `data_examples` (or `data_examples.exe` on Windows).

3. **Run the Executable**

   ```bash
   ./data_examples
   ```

   The program will prompt you to enter an integer, a double, a character, and a string.

## Code Overview

The `main.c` file includes the `stdio.h` header for standard input/output functions.

```c
#include <stdio.h> // Standard input-output library

int main(void) {
    int    userInt;       // Variable to store an integer
    double userDouble;    // Variable to store a double
    char   userChar;      // Variable to store a character
    char   userString[10]; // Array to store a string (up to 9 characters + null terminator)

    // Prompts and scanf calls to read user input for each variable type.
    printf("Enter integer:\n");
    scanf("%d", &userInt);

    printf("Enter double:\n");
    scanf("%lf", &userDouble);

    printf("Enter character:\n");
    scanf(" %c", &userChar); // Note the space before %c to consume any leftover newline

    printf("Enter string:\n");
    scanf("%s", userString);

    // Output all four values on a single line separated by a space.
    printf("%d %lf %c %s\n", userInt, userDouble, userChar, userString);

    // Output the four values in reverse order.
    printf("%s %c %lf %d\n", userString, userChar, userDouble, userInt);

    // Cast the double to an integer and output both.
    printf("%lf cast to an integer is %d\n", userDouble, (int)userDouble);

    return 0; // Program exits successfully
}
```
