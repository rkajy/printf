#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "ft_printf_test.h"   // <= ajoute bien CET include

int compare_printfs(const char *format, ...)
{
    char buf1[128], buf2[128];
    int ret1, ret2;
    va_list args1, args2;

    va_start(args1, format);
    va_copy(args2, args1);

    ret1 = ft_vsnprintf(buf1, sizeof(buf1), format, args1);
    ret2 = vsnprintf(buf2, sizeof(buf2), format, args2);

    va_end(args1);
    va_end(args2);

    printf("ft_printf: %s\n", buf1);
    printf("snprintf:  %s\n", buf2);

    return strcmp(buf1, buf2) == 0;
}
