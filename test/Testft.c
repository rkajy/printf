#include <stddef.h>

#include "unity.h"
#include "printf.h"
#include <string.h>
#include <stdio.h>



void compare_printfs(const char *format, ...);

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

/*
25:     TEST(1, print("%c", '0')); should print "0"
26:     TEST(2, print(" %c ", '0')); should print " 0 "
27:     TEST(3, print(" %c", '0' - 256)); should print " 0"
28:     TEST(4, print("%c ", '0' + 256)); should print "0 "
29:     TEST(5, print(" %c %c %c ", '0', 0, '1')); should print " 0  1 "
30:     TEST(6, print(" %c %c %c ", ' ', ' ', ' ')); should print "7spaces" instead
31:     TEST(7, print(" %c %c %c ", '1', '2', '3')); should print " 1 2 3 "
32:     TEST(8, print(" %c %c %c ", '2', '1', 0)); should print " 2 1  "
33:     TEST(9, print(" %c %c %c ", 0, '1', '2')); should print "  1 2 "

*/ 

void test_print_char(void)
{
    compare_printfs("%c", '0');
    compare_printfs(" %c ", '0');
    compare_printfs(" %c", '0' - 256);
    compare_printfs("%c ", '0' + 256);
    compare_printfs(" %c %c %c ", '0', 0, '1');
    compare_printfs(" %c %c %c ", ' ', ' ', ' '); // Should print "7spaces" instead
    compare_printfs(" %c %c %c ", '1', '2', '3');
    compare_printfs(" %c %c %c ", '2', '1', 0);
    compare_printfs(" %c %c %c ", 0, '1', '2');

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
	// RUN_TEST(test_plus_flag);
	// RUN_TEST(test_space_flag);
	// RUN_TEST(test_zero_flag);
	// RUN_TEST(test_precision_numbers);
	// RUN_TEST(test_precision_strings);
    RUN_TEST(test_print_char);
	UNITY_END();

	return 0;
}
