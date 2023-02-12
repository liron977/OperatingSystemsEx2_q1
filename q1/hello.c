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
	fprintf(stdout,"Hello!!\n");
	fflush(NULL);
	fprintf(stderr,"program: %s, pid = %d exiting.\n",argv[0],getpid());
	fflush(NULL);
}