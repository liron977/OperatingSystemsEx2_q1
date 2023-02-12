# Makefile for ex2_q1 winter 2023A

CFLAGS   = -Wall -std=c99
LDFLAGS  = -lm
CC       = gcc
ECHO     = @echo "going to build target $@ (dependent on $^)"

# the following is used to assign different values according to OS
# uname is a linux command (try it).
# commented out for now.
# OS := $(shell uname)
# ifneq (,$(findstring LINUX,$(OS)))
#   VAR =
# else
#   VAR =
# endif


PROG = ex2_q1
PROGS =  $(PROG) hello hello_who

all: $(PROGS) test

hello: hello.c
	$(ECHO)
	$(CC) $^ $(CFLAGS) -o $@

hello_who: hello_who.c
	$(ECHO)
	$(CC) $^ $(CFLAGS) -o $@

$(PROG): $(PROG).c
	$(ECHO)
	$(CC) $^ $(CFLAGS) $(LDFLAGS) -o $@

clean:
	rm -vf *.o ${PROGS} t?.txt

test: $(PROG)
	@echo going to run test...
	./$(PROG) "1>" t1.txt hello
	cat t1.txt
	./$(PROG) "2>" t2.txt hello_who Avia
	cat t2.txt
	./$(PROG) hello_who Avia Bat-El Galia
	./$(PROG) "2>&1" t4.txt hello_who Avia Bat-El Galia
	cat t4.txt
	./$(PROG) "2>&1" t5.txt hello
	cat t5.txt
	./$(PROG) "2>&1" t6.txt no_prog
	cat t6.txt
	# please DO NOT erase the above two lines. 
	# However you may add your tests here 
	# don't forget the lines should start with <tab> and not spaces.

  
  
