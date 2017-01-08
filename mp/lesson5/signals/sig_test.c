#include <stdio.h>
#include <signal.h>
//#include <sys/types.h>
#include <unistd.h>


int main(int argc, char **argv) {
	FILE *pFile = fopen("pid", "w");
	fprintf(pFile, "%d\n", getpid());
	fclose(pFile);

	signal(SIGTERM, SIG_IGN);
	signal(SIGINT, SIG_IGN);

	pause();

	return 0;
}

