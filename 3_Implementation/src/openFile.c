#include "prototypes.h"

error_t openFile(char *filename, char *mode, FILE **fptr){
    *fptr = fopen(filename,mode);
    if(*fptr==NULL){
        *fptr = fopen(filename,"wb+");
    }    
    return SUCCESS;
}