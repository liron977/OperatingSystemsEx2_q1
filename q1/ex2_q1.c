#include "ex2_q1.h"

int main(int agrc, char* argv[]) {	
	int pid = -1;
	bool is_perform_redirection=false,is_stdout_redirected=false, is_stderr_redirected= false;
	if (agrc < 2) {
		fprintf(stderr, "Going to exit,arguments missing\n");
		exit(1);
	}

	is_perform_redirection = do_redirection(argv, agrc,&is_stdout_redirected,&is_stderr_redirected);
    pid = fork();
	if (pid < 0){
		perror("Cannot fork()");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0) {
		do_child(argv, agrc, is_perform_redirection);
	}
	else {
		wait(NULL);
	}

	close_files(&is_stdout_redirected, &is_stderr_redirected);
	exit(0);
}

void set_buf() {
	setbuf(stdout, NULL);
	setbuf(stderr, NULL);
	setbuf(stdin, NULL);
}

void close_files(bool *is_stdout_redirected, bool *is_stderr_redirected){
	if (*is_stdout_redirected) {
		close(1);
	}
	if (*is_stderr_redirected) {
		close(2);
	}
}

char* get_program_name(bool is_perform_redirection, char* argv[]) {
	char* program_name;

	if (is_perform_redirection) {
		program_name = argv[3];
	}
	else {
		program_name = argv[1];
	}

	return program_name;
}

bool do_redirection(char* argv[], int agrc,bool *is_stdout_redirected, bool *is_stderr_redirected){
	bool is_perform_redirection;

	set_buf();
	is_perform_redirection = perform_redirection(argv, is_stdout_redirected, is_stderr_redirected);

	return is_perform_redirection;
}

void do_child(char* argv[], int agrc,bool is_perform_redirection) {
	char* program_name;
	char** arguments;
	
	arguments = get_argments(argv, agrc, is_perform_redirection);
	program_name = get_program_name(is_perform_redirection, argv);
	execve(program_name, arguments, NULL);

	perror("Exec faild: ");
	fprintf(stderr, "Exec Faild, going to exit.\n");
}

char** get_argments(char* argv[], int agrc, bool is_perform_redirection) {
	char** arguments = (char**)malloc(sizeof(char*) * agrc);
	int index = 1;

	if (arguments == NULL) {
		perror("Malloc Faild");
		exit(EXIT_FAILURE);
	}
	if (is_perform_redirection) {
		index = 3;
	}
	for (int i = index; i <= agrc; i++) {
		arguments[i - index] = argv[i];
	}

	return arguments;
}

bool perform_redirection(char* argv[],bool *is_stdout_redirected, bool *is_stderr_redirected) {
	if (!strcmp(argv[1], "1>")) {
		redirect_the_stdout(argv[2], is_stdout_redirected);
		return true;
	}
    else if (!strcmp(argv[1], "2>")) {
		redirect_the_stderr(argv[2], is_stderr_redirected);
		return true;
	}
	else if (!strcmp(argv[1], "2>&1")) {
		redirect_stdout_and_stderr(argv[2],is_stdout_redirected,is_stderr_redirected);
		return true;
	}

	return false;
}

void redirect_the_stdout(char* file_name,bool *is_stdout_redirected) {
	close(1);
    open_file(file_name);
	*is_stdout_redirected = true;
}

void redirect_the_stderr(char* file_name,bool *is_stderr_redirected) {
	close(2);
	open_file(file_name);
	*is_stderr_redirected = true;
}

void redirect_stdout_and_stderr(char* file_name,bool *is_stdout_redirected,bool *is_stderr_redirected) {
	int fd_out = 0;

	close(1);
	close(2);
	fd_out = open_file(file_name);
	dup(fd_out);
	*is_stdout_redirected = true;
	*is_stderr_redirected = true;
}

int open_file(char* name){
	int fd;
	fd = open(name, O_CREAT | O_WRONLY | O_TRUNC , S_IRUSR | S_IWUSR);
	if (fd < 0)  // open failed
	{
		fprintf(stderr, "ERROR: open \"%s\" failed (%d). Exiting\n", name, fd);
		exit(2);
	}
	return(fd);
}
