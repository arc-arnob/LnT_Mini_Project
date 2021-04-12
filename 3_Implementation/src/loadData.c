#include "prototypes.h"

patient* loadData(patient *start, FILE **fptr){

    // patient *ptr;
    // ptr = start;
    patient rec;
    while(fread(&rec, sizeof(rec),1,*fptr) == 1){
        patient *new_box;
        new_box = (patient *)malloc(sizeof(patient));

        new_box->uniq_id = rec.uniq_id;
        strcpy(new_box->firstname, rec.firstname);
        strcpy(new_box->lastname, rec.lastname);
        strcpy(new_box->aadhar_num, rec.aadhar_num);
        new_box-> height = rec.height;
        new_box->weight = rec.weight;
        new_box->age = rec.age;
        strcpy(new_box ->date_of_vaccine, rec.date_of_vaccine);
        new_box->insurance = rec.insurance;
        new_box->shot = rec.shot;
        new_box->next = NULL;

        if(start == NULL){
            start = new_box;
        }
        else{
            
            insert_end(start,rec.uniq_id,rec.firstname,rec.lastname,rec.aadhar_num,rec.height,rec.weight,rec.age,rec.date_of_vaccine,rec.insurance,rec.shot);
            free(new_box);
        }
        

    }
    return start;
}
