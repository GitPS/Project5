/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441 : Project 5
 *
 * 2013-12-01
 *
 */

#include "support.h"

#ifndef _scheduler_h
#define _scheduler_h

/*
 * Maximum length supported for a filename
 */
int MAXFILENAME = 256;

/*
 * Takes the number of frames and the filename and
 * displays that information to the user
 *
 * Paramters:
 *   frames   : The number of frames which the algorithms will be run with
 *   filename : A string containing the name of the file to be processed
 *
 * Returns:
 *   Void
 *
 */
void print_header(int frames, char *filename);

/*
 * Prints out the reference string, including the page numbers and modes
 *
 * Paramters:
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   Void
 *
 */
void print_ref_string(int ref_length, ref_element_t *ref_string[]);

/*
 * Prints out the results of all algorthms run on the specified range of frame sizes
 *
 * Paramters:
 *   num_frames : The number of frames which the algorithms will be run with
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   Void
 *
 */
void print_algorithms(int num_frames, int ref_length, ref_element_t *ref_string[]);

/*
 * Determines the number of pagefaults which occur for the Optimal page
 * replacement algorithm with the given number of frames and reference string
 *
 * Paramters:
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   The number of pagefaults which occur for the given reference string and number of frames
 *
 */
int simulate_optimal(int ref_length, ref_element_t *ref_string[]);

/*
 * Determines the number of pagefaults which occur for the First-In, First-Out page
 * replacement algorithm with the given number of frames and reference string
 *
 * Paramters:
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   The number of pagefaults which occur for the given reference string and number of frames
 *
 */
int simulate_fifo(int ref_length, ref_element_t *ref_string[]);

/*
 * Determines the number of pagefaults which occur for the Least Recently Used page
 * replacement algorithm with the given number of frames and reference string
 *
 * Paramters:
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   The number of pagefaults which occur for the given reference string and number of frames
 *
 */
int simulate_lru(int ref_length, ref_element_t *ref_string[]);

/*
 * Determines the number of pagefaults which occur for the Least Recently Used, Second Chance
 * page replacement algorithm with the given number of frames and reference string
 *
 * Paramters:
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   The number of pagefaults which occur for the given reference string and number of frames
 *
 */
int simulate_lru_sc(int ref_length, ref_element_t *ref_string[]);

/*
 * Determines the number of pagefaults which occur for the Least Recently Used, Enhanced Second Chance
 * page replacement algorithm with the given number of frames and reference string
 *
 * Paramters:
 *   ref_length : The length of the ref_string array
 *   ref_string : A pointer to an array of reference string elements to be evaluated
 *
 * Returns:
 *   The number of pagefaults which occur for the given reference string and number of frames
 *
 */
int simulate_lru_esc(int ref_length, ref_element_t *ref_string[]);

#endif
