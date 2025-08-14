
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int print_format(char specifier, va_list ap)
{
    int count = 0;

    return 0;
}

// int main(void)
// {
//     va_list ap;
//     int count;

//     va_start(ap, format);
//     count  = 0;

//     while (*format != '\0')
//     {
//          if(*format == '%')
//            count += print_format(*(++format), ap);
//          else
//             count += write(1,format,1);
//          ++format;
//     }
//     va_end(ap);
//     return count;
// }

// int main()
// {
//     int count;

//     count = my_printf("Hello %s\n", "John");
//     my_printf("The chars written are %d\n", count);

//     return 0;
// }
