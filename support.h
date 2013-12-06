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
 * Structures
 */
 
// Reference Element, stores one pair (Page:Mode), e.g. (5:W) or (2:R)
struct ref_element_t {
    int page;
    char mode;
};
typedef struct ref_element_t ref_element_t;

// Structure to hold a timestamp for LRU algorithms.
struct clock_t{
    int time;
    int value;
};
typedef struct clock_t clock_t;

/*
 * Parses the command line arguments to determine the file name to
 * read from and the number of frames to simulate (if applicable).
 *
 *   filename   : Name of the file to read data from.
 *   num_frames : The (optional) number of frames to simulate.  Otherwise 0 for full range.
 *
 * Returns:
 *   0 on success
 *   -1 on failure
 *
 */
int parse_command_line_arguments(int argc, char *argv[], char *filename, int *num_frames);

/*
 * Takes an input string to check if it is a syntaticaly correct integer.
 *
 * Paramters:
 *   str : String to check
 *
 * Returns:
 *   0 if it is a valid integer.
 *   -1 if it is not a valid integer.
 *
 */
int is_valid_int(char *str);

/*
 * Parses the command line arguments to determine the file name to
 * read from and the number of frames to simulate (if applicable).
 *
 *   filename   : Name of the file to read data from.
 *   ref_length : Size of the ref_string array.
 *   ref_string : A pointer to a location to store the reference string array.
 *
 * Returns:
 *   0 on success
 *   -1 on failure
 *
 */
int parse_file_into_ref_string(char *filename, int *ref_length, ref_element_t *ref_string[]);

/*
 * Takes an array of ints and checks to see if a given int is in that array.
 *
 * Paramters:
 *   array  : An array of integers to search through
 *   size   : The size of array
 *   search : The int to search for
 *
 * Returns:
 *   1 if the int is in the array.
 *   0 if the int is not in the array.
 *
 */
int in_array(int *array, int size, int search);

#endif
