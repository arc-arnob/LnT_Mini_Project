#include "prototypes.h"
// This file will store nothing more than patient ids to avoid redundant entry.
error_t indexFile(char *filename, char *mode, FILE **fptr){
    *fptr = fopen(filename,mode);
    if( *fptr == NULL){
        *fptr = fopen(filename,"wb+");
    }
    return SUCCESS; 
}