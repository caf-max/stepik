#include <stddef.h>

int stringStat(const char *string, size_t multiplier, int *count)
{
	int length = 0;
	while (*string++) {
		length++;
	}
	length *= multiplier;
	(*count)++;
	return length;
}

