#####################################################################
# Ryan Gittins and Phillip Sime
#
# CS 441 : Memory Management Simulator
#
#####################################################################
#
# Type "make" or "make all" to compile your code
# Type "make clean" to remove the executable (and any object files)
#
#####################################################################

# Our C Compiler
CC=gcc

#
# Compiler Flags
#
CFLAGS=-Wall -O0 -g

#
# Program(s) to compile
#
PROGS=scheduler

all: $(PROGS)

#
# Scheduler
#
scheduler: support.o scheduler.c scheduler.h
	$(CC) -o scheduler support.o $(CFLAGS) scheduler.c $(LDFLAGS)

#
# Cleanup
#
clean:
	$(RM) $(PROGS) *.o
	$(RM) -rf *.dSYM
