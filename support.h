/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441 : Project 5
 *
 * 2013-12-01
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifndef _support_h
#define _support_h

int parse_command_line_arguments(int argc, char *argv[], char *filename, int *num_frames);

int is_valid_int(char *str);

#endif
