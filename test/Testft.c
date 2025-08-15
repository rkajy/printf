#include <stddef.h>

#include "unity.h"
#include "printf.h"
#include <string.h>
#include <stdio.h>


void compare_printfs(const char *format, ...);

void test_ft_memset()
{
}
// Test pour le flag +
void test_plus_flag(void) {
    compare_printfs("1 -> |%+d|\n", 42);
    compare_printfs("2 -> |%+d|\n", -42);
}

// Test pour le flag espace
void test_space_flag(void) {
    compare_printfs("3 -> |% d|\n", 42);
    compare_printfs("4 -> |% d|\n", -42);
}

// Test pour le flag 0
void test_zero_flag(void) {
    compare_printfs("5 -> |%05d|\n", 42);
    compare_printfs("6 -> |%05d|\n", -42);
}

// Test pour la précision sur les nombres
void test_precision_numbers(void) {
    compare_printfs("9  -> |%.5d|\n", 42);
    compare_printfs("10 -> |%.5d|\n", -42);
    compare_printfs("11 -> |%.0d|\n", 0);
}

// Test pour la précision sur les chaînes
void test_precision_strings(void) {
    compare_printfs("12 -> |%.3s|\n", "Hello");
    compare_printfs("13 -> |%.0s|\n", "Hello");
}

void setUp()
{

}

void tearDown()
{

}

int main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_plus_flag);
	RUN_TEST(test_space_flag);
	RUN_TEST(test_zero_flag);
	RUN_TEST(test_precision_numbers);
	RUN_TEST(test_precision_strings);

	UNITY_END();

	return 0;
}
