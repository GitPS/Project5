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
	int ref_string_length = 0;
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
	
	parse_file_into_ref_string(filename, &ref_string_length, &ref_string);
	print_ref_string(ref_string_length, &ref_string);
    
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
        printf("Num. Frames  : All\n");
    }
    else{
        printf("Num. Frames  : %d\n", num_frames);
    }
    printf("Ref. File    : %s\n", filename);
    printf("-------------------------------\n");
}


