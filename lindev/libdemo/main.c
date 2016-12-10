#include <stdio.h>
#include "solution.h"


int main()
{
	int count = 41;
	int res = stringStat("Hello", 4, &count);

	printf("%d - %d\n", res, count);

	return 0;
}

