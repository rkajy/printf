#include <stdio.h>
#include <stdarg.h>

int max(int num_args, ...);

int main(void)
{
    max(2, 4, 8);
    max(4, 10, 12, 14, 16);

    return 0;
}

int max(int num_args, ...)
{
    va_list args;


    va_start(args, num_args)

    int max = 0;
    for(int i = 0; i < num_args; i++)
    {
        int x = va_arg(args, int);
        if (i == 0) max = x;
        else if (x > max) max = x;
        printf("x: %d\n", x);
    }

    va_end(args);

    return 0;
}