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
	UNITY_END();

	return 0;
}
