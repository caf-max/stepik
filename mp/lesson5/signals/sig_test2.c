#include <stdio.h>
#include <signal.h>
//#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char **argv) {
	pid_t pid = fork();

	if (pid == 0) {

	} else {
		FILE *pFile = fopen("pid_parent", "w");
		fprintf(pFile, "%d\n", getpid());
		fclose(pFile);

		pFile = fopen("pid_child", "w");
		fprintf(pFile, "%d\n", pid);
		fclose(pFile);

		waitpid(pid, NULL, 0);
	}

	pause();

	return 0;
}

