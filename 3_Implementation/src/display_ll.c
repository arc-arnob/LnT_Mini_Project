#include "prototypes.h"

error_t display_ll(patient *start)
{
    patient *ptr;
    ptr = start;
    
    if(start == NULL){
        return NO_HEAD_EXIST;
    }
    else{
        while(ptr != NULL){
            printf("Details about box id: %d\n", ptr->uniq_id);
            printf("firstname: %s\n", ptr->firstname);

            printf("****************************\n");
            ptr = ptr->next;
        }
        return SUCCESS;
    }


}