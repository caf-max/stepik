#include <stdio.h>


int main(int argc, char **argv)
{
	fork();
	fork();
	fork();
	fork();
	printf("%d\n", getpid());
	
	return 0;
}

