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
    int ret;
    // Num frames to use in analysis.  Default to 7.
    int num_frames = 7;
    
    ret = parse_command_line_arguments(argc, argv, filename, &num_frames);
    if(ret == -1){
        fprintf(stderr, "Error: Command line arguments were not valid!\n");
        fprintf(stderr, "Usage: ./scheduler <filename> [-f <frames>]\n");
        exit(-1);
    }
    
    print_header(num_frames, filename);
    
    return 0;
}

void print_ref_string(int ref_length, int * ref_nums[], char * ref_modes[]){
	int i = 0;
	
	printf("Reference String:\n ");
	
	while(i < ref_length){
		printf("%d:%c", ref_nums[i], ref_modes[i]);
		if(i+1 < ref_length){
			printf(",  ");
		}
	}
	
	printf("\n--------------------------\n");
}

void print_header(int num_frames, char *filename){
    if(num_frames == 7){
        printf("Num. Frames  : All\n");
    }
    else{
        printf("Num. Frames  : %d\n", num_frames);
    }
    printf("Ref. File    : %s\n", filename);
    printf("--------------------------\n");
}


