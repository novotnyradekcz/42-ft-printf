# ft_printf
My second project at 42 Prague, created in spring 2023. A printing function similar to the C function `printf` from the `stdio.h` library. Contains only mandatory part of the assignment, which means the function can handle the following conversions:

- `%c` prints a single character
- `%s` prints a string (as defined by the common C convention)
- `%p` prints the void * pointer argument in hexadecimal format
- `%d` prints a decimal (base 10) number
- `%i` prints an integer in base 10
- `%u` prints an unsigned decimal (base 10) number
- `%x` prints a number in hexadecimal (base 16) lowercase format
- `%X` prints a number in hexadecimal (base 16) uppercase format
- `%%` prints a percent sign

The function does not handle any flags (the flags `-`, `0`, `.`, `#`, ` ` and `+` were part of the bonus part which I chose not to implement).

The function passed Moulinette.
