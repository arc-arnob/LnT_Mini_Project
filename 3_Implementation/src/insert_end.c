#include "prototypes.h"

error_t insert_end(patient *start, 
                int id, 
                char *firstname, 
                char *lastname,
                char *aadhar_num,
                float height,
                float weight,
                int age,
                char *date,
                insured insurance,
                vaccine shot)
{
    patient *new_box, *ptr;
    new_box = (patient *)malloc(sizeof(patient));

    new_box->uniq_id = id;
    strcpy(new_box->firstname, firstname);
    strcpy(new_box->lastname, lastname);
    strcpy(new_box->aadhar_num, aadhar_num);
    new_box -> height = height;
    new_box ->weight = weight;
    new_box ->age = age;
    strcpy(new_box ->date_of_vaccine, date);
    new_box->insurance = insurance;
    new_box->shot = shot;
    new_box->next = NULL;
    if(start == NULL){
        free(new_box);
        return NO_HEAD_EXIST;
    }
    else{
        ptr = start;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = new_box;
        return SUCCESS;
    }


}