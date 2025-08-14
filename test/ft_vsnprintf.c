#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

// Implémentation simplifiée de ft_vsnprintf
int ft_vsnprintf(char *str, size_t size, const char *format, va_list ap) {
    // Utilise un buffer temporaire pour capturer la sortie
    char temp_buffer[1000];
    int ret;

    // Appelle ft_printf ou une fonction équivalente pour écrire dans le buffer temporaire
    ret = ft_printf(temp_buffer, format, ap);

    // Copie le résultat dans le buffer de destination (str) avec une taille limitée
    if (size > 0) {
        strncpy(str, temp_buffer, size - 1);
        str[size - 1] = '\0'; // Assure la terminaison nulle
    }

    return ret;
}