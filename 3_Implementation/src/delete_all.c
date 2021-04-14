#include "prototypes.h"

void delete_all(patient *start){

    patient *current;
    current = start;
    patient *ptr;
    while(current != NULL){
        ptr = current->next;
        free(current);
        current = ptr;
    }
    start = NULL;


}

patient *delete_beg(patient *start){
    patient *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}