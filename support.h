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

/*
 * TODO
 */
int parse_command_line_arguments(int argc, char *argv[], char *filename, int *num_frames);

/*
 * TODO
 */
int is_valid_int(char *str);

/*
 * TODO
 */
int parse_file_into_ref_string(char * filename, int * ref_string_length, int * ref_nums[], char * ref_modes[]);

#endif
