// ft_printf_test.h
#ifndef FT_PRINTF_TEST_H
#define FT_PRINTF_TEST_H

#include <stdarg.h>
#include <stddef.h> // pour size_t
int ft_vsnprintf(char *buf, size_t size, const char *format, va_list args);

#endif