#include "unity.h"
#include "ft_printf.h" // Ton implémentation de ft_printf
#include <stdio.h>
#include <string.h>

int ft_vsnprintf(char *str, size_t size, const char *format, va_list ap);

void compare_printfs(const char *format, ...)
{
    char buffer_printf[1000];
    char buffer_ft_printf[1000];
    int result_printf, result_ft_printf;

    va_list args1, args2;
    va_start(args1, format);
    va_start(args2, format);

    // Appel de printf standard
    result_printf = vsnprintf(buffer_printf,sizeof(buffer_printf), format, args1);

    // Capture de la sortie de ft_printf
    result_ft_printf = ft_vsnprintf(buffer_ft_printf, sizeof(buffer_ft_printf), format, args2);

    va_end(args1);
    va_end(args2);

    TEST_ASSERT_EQUAL_STRING(buffer_printf, buffer_ft_printf);
    TEST_ASSERT_EQUAL_INT(result_printf, result_ft_printf);
}