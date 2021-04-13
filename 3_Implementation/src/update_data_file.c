#include "prototypes.h"

error_t update_data_file(FILE **fptr, int id){

    rewind(*fptr);
    patient rec;
    while(fread(&rec, sizeof(rec), 1, *fptr)==1){
        if(rec.uniq_id == id){
            rec.uniq_id = id;
            printf("Enter new First Name\n");
            scanf("%100s", rec.firstname);
            printf("Enter the last name\n");
            scanf("%100s",rec.lastname);
            printf("Enter height of the patient\n");
            scanf("%f",&rec.height);
            printf("Enter weight of patient\n");
            scanf("%f",&rec.weight);
            printf("enter aadhar card number\n");
            scanf("%20s",rec.aadhar_num);
            printf("Enter age of the patient\n");
            scanf("%d",&rec.age);
            printf("Is the patient insured?\n");
            scanf("%d",&rec.insurance);
            printf("Enter the name of the vaccine recieved\n");
            scanf("%d",&rec.shot);
            printf("Enter the date of vaccination\n");
            scanf("%12s", rec.date_of_vaccine);

            if(fseek(*fptr, -sizeof(rec),SEEK_CUR) !=0 ) return -1;
            fwrite(&rec,sizeof(rec),1,*fptr); //working
            

            break;

        }
    
    }
    return SUCCESS;
}