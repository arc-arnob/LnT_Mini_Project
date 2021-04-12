#include "prototypes.h"

error_t delete_patient(patient *start, int id){

    patient *ptr;
    ptr = start;
    if(start == NULL){
        return NO_HEAD_EXIST;
    }
    else{
        patient *preptr;
        while(ptr->uniq_id != id){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return SUCCESS;
    }

} 