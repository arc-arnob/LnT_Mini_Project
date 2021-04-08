#include "prototypes.h"

void delete_all(box *start){

    box *ptr;
    ptr = start;
    while(ptr->next != NULL){
        start = delete_beg(ptr);
        ptr = ptr->next;
    }
    free(start);

}

box *delete_beg(box *start){
    box *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}