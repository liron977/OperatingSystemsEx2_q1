#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include<stdlib.h>  
#include <stdbool.h>

bool perform_redirection(char* user_input[], bool *is_stdout_redirected, bool *is_stderr_redirected);
char** get_argments(char* argv[], int agrc, bool is_perform_redirection);
int open_file(char* name);
char* get_program_name(bool is_perform_redirection, char* argv[]);
void do_child(char* argv[], int agrc,bool is_perform_redirection);
void set_buf();
void redirect_stdout_and_stderr(char* file_name,bool *is_stdout_redirected,bool *is_stderr_redirected);
void redirect_the_stderr(char* file_name,bool *is_stderr_redirected);
void redirect_the_stdout(char* file_name,bool *is_stdout_redirected);
bool do_redirection(char* argv[], int agrc, bool *is_stdout_redirected, bool *is_stderr_redirected);
void close_files(bool *is_stdout_redirected, bool *is_stderr_redirected);