#include "ft_printf_test.h"
#include <stdio.h>
#include <stdarg.h>

int ft_vsnprintf(char *buf, size_t size, const char *format, va_list args)
{
    // pour le moment, rediriger vers vsnprintf de la libc
    return vsnprintf(buf, size, format, args);
}