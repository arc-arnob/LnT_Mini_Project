#include "prototypes.h"

error_t saveFile(patient *start, FILE **fptr, int *ch){
    // Define a structure
     // need to perform malloc
    //loop through the list
    if(*ch==1){
            rewind(*fptr);
    }
    patient *ptr;
    ptr = start;
    while(ptr != NULL){
        patient *record = (patient *)malloc(sizeof(patient));
        record->uniq_id = ptr->uniq_id;
        strcpy(record->firstname, ptr->firstname);
        strcpy(record->lastname, ptr->lastname);
        strcpy(record->aadhar_num, ptr->aadhar_num);
        record-> height = ptr->height;
        record->weight = ptr->weight;
        record->age = ptr->age;
        strcpy(record->date_of_vaccine, ptr->date_of_vaccine);
        record->insurance = ptr->insurance;
        record->shot = ptr->shot;
        
        fwrite(record,sizeof(patient),1,*fptr);
        free(record);
        ptr = ptr->next;
        
    }
    // save record in structure and save it in file -- fwrite()
}