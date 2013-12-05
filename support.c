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
                int temp = strtol(argv[i + 1], NULL, 10);
                /* Check for a valid frame number */
                if( temp < 1 || temp > 7){
                    return -1;
                }
                *num_frames = temp;
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

int parse_file_into_ref_string(char *filename, int *ref_string_length, ref_element_t *ref_string[]){
    FILE *fd = NULL;
    char buffer[1024];
    char *fgets_rtn = NULL;
    
    /* Open File */
    fd = fopen(filename, "r");
    if(NULL == fd){
        fprintf(stderr, "Error: Cannot open the file %s for reading!\n", filename);
        return -1;
    }
    
    /* Read File */
    int i = -1;
    while(0 == feof(fd)){
        char * str_ptr  = NULL;
        fgets_rtn = fgets(buffer, 1024, fd);
        
        if( NULL == fgets_rtn) {
            break;
        }
        
        /* Strip off the new line */
        if( '\n' == buffer[ strlen(buffer) - 1] ) {
            buffer[ strlen(buffer) - 1] = '\0';
        }
        
        /* If this is the first line in the file it contains the reference string length */
        if(i == -1){
            str_ptr = strtok(buffer, " ");
            /* Check for valid integer before we call strtol()*/
            if(is_valid_int(str_ptr) != 0){
                return -1;
            }
            *ref_string_length = strtol(str_ptr, NULL, 10);
            /* Add correct amount of space in the reference string array */
			(*ref_string) = (ref_element_t *)realloc((*ref_string), (sizeof(ref_element_t) * (*ref_string_length)));
            if( NULL == (*ref_string)) {
                fprintf(stderr, "Error: Failed to allocate memory! Critical failure on %d!", __LINE__);
                exit(-1);
            }
        }    
        /* All other lines are part of the reference string */
        else{
            int j = 0;
            for( str_ptr = strtok(buffer, " ");
                NULL != str_ptr && *str_ptr != '\n';
                str_ptr = strtok(NULL, " ") ) {
                switch(j){
                    case 0:
                        /* Check for valid integer before we call strtol()*/
                        if(is_valid_int(str_ptr) != 0){
                            return -1;
                        }
                        (*ref_string)[i].page = strtol(str_ptr, NULL, 10);
                        break;
                    case 1:
                        /* Check for valid ref mode before we assign it*/
						if(*str_ptr == 'r' || *str_ptr == 'R'){
							(*ref_string)[i].mode = 'R';
						}
						else if(*str_ptr == 'w' || *str_ptr == 'W'){
							(*ref_string)[i].mode = 'W';
						}
						else{
							return -1;
						}
                        break;
                    default:
                        break;
                }
                j++;
            }
        }
        i++;
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