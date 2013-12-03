/*
 * Ryan Gittins and Phillip Sime
 *
 * CS441 : Project 5
 *
 * 2013-12-01
 *
 */

#include "support.h"

int parse_command_line_arguments(int argc, char *argv[], char *filename, int *num_frames){
    int i;
    int filename_found = 1; // Found = 0 | Not Found = 1
    
    for (i = 1; i < argc; i++) {
        /* Check for number of frames */
        if (strncmp("-f", argv[i], strlen("-f")) == 0)  {
            /* Ensure there is another argument */
            if(i + 1 < argc){
                /* Ensure that argument is a valid integer */
                if(is_valid_int(argv[i + 1]) != 0){
                    return -1;
                }
                /* Set num_frames to that value */
                *num_frames = strtol(argv[i + 1], NULL, 10);
                /* Skip next argument since we have used it */
                i++;
            }
        }
        else if(filename_found != 0){
            strcpy(filename, argv[i]);
            filename_found = 0;
        }
        
    }
    
    /* Ensure the filename was set */
    if (filename_found == 1) {
        return -1;
    }
    
    return 0;
}

int is_valid_int(char *str){
    int length = strlen(str);
    int i = 0;
    
    for (i = 0; i < length; i++) {
        if(!isdigit((unsigned char)str[i])){
            return -1; // Not an integer
        }
    }
    
    return 0; // Is an integer
}