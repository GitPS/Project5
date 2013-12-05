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
 * TODO
 */
void print_header(int frames, char *filename);

/*
 * TODO
 */
void print_ref_string(int ref_length, ref_element_t *ref_string[]);


void print_algorithms(int num_frames, int ref_length, ref_element_t *ref_string[]);


int simulate_optimal(int ref_length, ref_element_t *ref_string[]);


int simulate_fifo(int ref_length, ref_element_t *ref_string[]);


int simulate_lru(int ref_length, ref_element_t *ref_string[]);


int simulate_lru_sc(int ref_length, ref_element_t *ref_string[]);


int simulate_lru_esc(int ref_length, ref_element_t *ref_string[]);

#endif
