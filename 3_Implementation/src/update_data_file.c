#include "prototypes.h"

error_t update_data_file(FILE **fptr, int id){

    rewind(*fptr);
    patient rec;
    while(fread(&rec, sizeof(rec), 1, *fptr)==1){
        if(rec.uniq_id == id){
            rec.uniq_id = id;
            printf("Enter new First Name\n");
            scanf("%s", rec.firstname);
            printf("Enter the last name\n");
            scanf("%s",rec.lastname);
            printf("Enter height of the patient\n");
            scanf("%f",&rec.height);
            printf("Enter weight of patient\n");
            scanf("%f",&rec.weight);
            printf("enter aadhar card number\n");
            scanf("%s",rec.aadhar_num);
            printf("Enter age of the patient\n");
            scanf("%d",&rec.age);
            printf("Is the patient insured?\n");
            scanf("%d",&rec.insurance);
            printf("Enter the name of the vaccine recieved\n");
            scanf("%d",&rec.shot);
            printf("Enter the date of vaccination\n");
            scanf("%s", rec.date_of_vaccine);

            fseek(*fptr, -sizeof(rec),SEEK_CUR);
            fwrite(&rec,sizeof(rec),1,*fptr); //working

            break;

        }
    
    }
    return SUCCESS;
}