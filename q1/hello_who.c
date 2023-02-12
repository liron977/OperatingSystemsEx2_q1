#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <stdbool.h>
#include <fcntl.h>   
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

int main(int agrc, char* argv[]) {

	for (int i = 1; i < agrc; i++) {
		fprintf(stdout, "Hello %s!!\n", argv[i]);
		fflush(NULL);
	}
	fprintf(stderr, "program: %s, pid = %d greeted %d people.\n", argv[0], getpid(), agrc-1);
	fflush(NULL);
}