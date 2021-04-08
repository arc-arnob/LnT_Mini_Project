#include "prototypes.h"

error_t delete_box(box *start, int id){

    box *ptr;
    ptr = start;
    if(start == NULL){
        return NO_HEAD_EXIST;
    }
    else{
        box *preptr;
        while(ptr->uniq_id != id){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return SUCCESS;
    }

} 