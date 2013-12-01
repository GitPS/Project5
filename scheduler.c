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
        fprintf(stderr, "Error: Command line argumnets were not valid!\n");
        // TODO : Print usage
        exit(-1);
    }
    
    print_header(num_frames, filename);
    
    return 0;
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


