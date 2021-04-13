#include "prototypes.h"

void delete_all(patient *start){

    patient *ptr;
    ptr = start;
    while(ptr->next != NULL){
        start = delete_beg(ptr);
        ptr = ptr->next;
    }
    free(start);


}

patient *delete_beg(patient *start){
    patient *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}