/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441 : Project 5
 *
 * 2013-12-01
 *
 */

#include "scheduler.h"

int main(int argc, char * argv[]) {
    char filename[MAXFILENAME];
	ref_element_t *ref_string = NULL;
	int ref_length = 0;
    int ret;
    // Num frames to use in analysis.  Default to 0 which implies all in this case.
    int num_frames = 0;
    
    ret = parse_command_line_arguments(argc, argv, filename, &num_frames);
    if(ret == -1){
        fprintf(stderr, "Error: Command line arguments were not valid!\n");
        fprintf(stderr, "Usage: ./scheduler <filename> [-f <frames>]\n");
        fprintf(stderr, "  <frames> must be a number from 1 to 7\n");
        exit(-1);
    }
    
    print_header(num_frames, filename);
	
	parse_file_into_ref_string(filename, &ref_length, &ref_string);
	print_ref_string(ref_length, &ref_string);
	
	print_algorithms(num_frames, ref_length, &ref_string);
    
    return 0;
}

void print_ref_string(int ref_length, ref_element_t *ref_string[]){
	int i = 0;
	
	printf("Reference String:\n ");

	while(i < ref_length){
		printf("%d:%c", (*ref_string)[i].page, (*ref_string)[i].mode);
		if(i+1 < ref_length){
			printf(",  ");
		}
		i++;
	}
	
	printf("\n-------------------------------\n");
}

void print_header(int num_frames, char *filename){
    if(num_frames == 0){
        printf("Num. Frames : All\n");
    }
    else{
        printf("Num. Frames : %d\n", num_frames);
    }
    printf("Ref. File   : %s\n", filename);
    printf("-------------------------------\n");
}

void print_algorithms(int num_frames, int ref_length, ref_element_t *ref_string[]){
	printf("Frames  Opt.    FIFO    LRU     SC      ESC\n");

	if(num_frames == 0){
		// Run for the full range of frames
		int frame;
		
		for(frame = 1; frame <= 7; frame++){
			printf(" %d        ", frame);
			printf("%*d     ", 2,  simulate_optimal(frame, ref_length, ref_string));
			printf("%*d     ", 2, simulate_fifo(frame, ref_length, ref_string));
			printf("%*d     ", 2, simulate_lru(frame, ref_length, ref_string));
			printf("%*d     ", 2, simulate_lru_sc(frame, ref_length, ref_string));
			printf("%*d\n", 2, simulate_lru_esc(frame, ref_length, ref_string));
		}
	}
	else{
		// Run for the given number of frames
		
		printf(" %d        ", num_frames);
		printf("%*d     ", 2, simulate_optimal(num_frames, ref_length, ref_string));
		printf("%*d     ", 2, simulate_fifo(num_frames, ref_length, ref_string));
		printf("%*d     ", 2, simulate_lru(num_frames, ref_length, ref_string));
		printf("%*d     ", 2, simulate_lru_sc(num_frames, ref_length, ref_string));
		printf("%*d\n", 2, simulate_lru_esc(num_frames, ref_length, ref_string));
	}
	
}

int simulate_optimal(int num_frames, int ref_length, ref_element_t *ref_string[]){
	return 1;
}

int simulate_fifo(int num_frames, int ref_length, ref_element_t *ref_string[]){
	int frames[7] = {-1,-1,-1,-1,-1,-1,-1};
	// Index we'll insert into next
	int insert = 0;
	int faults = 0;
	int i;
	
	for(i = 0; i < ref_length; i++){
		if(!in_array(frames, num_frames, (*ref_string)[i].page)){
			// Not in the array
			frames[insert] = (*ref_string)[i].page;
			insert = (insert + 1) % num_frames;
			faults++;
		}
	}

	return faults;
}

int simulate_lru(int num_frames, int ref_length, ref_element_t *ref_string[]){
    int frames[7] = {-1,-1,-1,-1,-1,-1,-1};
    int faults = 0;
    int insert = 0;
    int lru_min_time = -1;
    int lru_value = -1;
    int time = 0;
    int i, j;
    int timestamps_size = 10;
    
    /* Create an array for the timestamps */
    clock_t *timestamps = (clock_t*)malloc(sizeof(clock_t) * timestamps_size);
    if(timestamps == NULL){
        fprintf(stderr, "Error: Failed to allocate memory!  Critical failure on %d!", __LINE__);
        exit(-1);
    }
    
    /* Set default values for timestamps array */
    for(i = 0; i < timestamps_size; i++){
        timestamps[i].time = -1;
    }
    
    /* All initial page references will be a page fault */
    for(i = 0; i < ref_length && insert < num_frames; i++){
        if(!in_array(frames, num_frames, (*ref_string)[i].page)){
			// Not in the array
			frames[insert] = (*ref_string)[i].page;
            /* Update timestamp */
            timestamps[(*ref_string)[i].page].time = time;;
            time++;
			insert++;
			faults++;
		}
        /* If it is already in the array update the time */
        else{
            timestamps[(*ref_string)[i].page].time = time;
            time++;
        }
    }
    
    for(i = i; i < ref_length; i++){
        if(!in_array(frames, num_frames, (*ref_string)[i].page)){
            /* Determine LRU */
            lru_min_time = -1;
            for(j = 0; j < timestamps_size; j++){
                if(in_array(frames, num_frames, j)){
                    if(lru_min_time > timestamps[j].time || lru_min_time == -1){
                        lru_min_time = timestamps[j].time;
                        lru_value = j;
                    }
                }
            }
            /* Replace LRU in frames array */
            for(j = 0; j < num_frames; j++){
                if(frames[j] == lru_value){
                    frames[j] = (*ref_string)[i].page;
                    timestamps[(*ref_string)[i].page].time = time;
                    time++;
                    faults++;
                }
            }
        }
        /* If it is already in the array update the time */
        else{
            timestamps[(*ref_string)[i].page].time = time;
            time++;
        }
    }
    
	return faults;
}

int simulate_lru_sc(int num_frames, int ref_length, ref_element_t *ref_string[]){
	return 1;
}

int simulate_lru_esc(int num_frames, int ref_length, ref_element_t *ref_string[]){
	return 1;
}