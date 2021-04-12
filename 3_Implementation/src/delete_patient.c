#include "prototypes.h"

patient *delete_patient(patient *start, int id){

    patient *ptr;
    ptr = start;
    if(start == NULL){
        return NULL;
    }
    else{
        if(ptr->uniq_id == id){
            start = delete_beg(start);
            return start;
        }else{
            patient *preptr;
            while(ptr->uniq_id != id){
                preptr = ptr;
                ptr = ptr->next;
            }
            preptr->next = ptr->next;
            free(ptr);
            return start;
        }
    }

} 