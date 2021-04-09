#include "prototypes.h"

error_t validate_id(FILE **fptr, int id){
    
    rewind(*fptr);
    int existing_id;
    while(fread(&existing_id, 4,1,*fptr)==1){
        if(existing_id == id){
            return ID_EXISTS;
        }
        else{
            return SUCCESS;
        }
    }
}
