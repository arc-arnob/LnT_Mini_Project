#include "prototypes.h"

error_t find_by_id(box *start, int id, box *res){

    box *ptr;
    ptr = start;
   
    if(start == NULL){
        return NO_HEAD_EXIST;
    }
    else{
        int found = 0;
        while(ptr != NULL){
            if(ptr->uniq_id == id){
                found = 1;
                break;
            }
            ptr = ptr->next;
        }
        if(found == 1){
            res->uniq_id = ptr->uniq_id;
            res->height = ptr->height;
            res->length = ptr->length;
            res->breadth = ptr->breadth;
            res->color = ptr->color;
            res->weight = ptr->weight;
        }

        return SUCCESS;
    }

} 