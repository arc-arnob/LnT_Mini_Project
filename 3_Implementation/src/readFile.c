#include "prototypes.h"

error_t readFile(FILE **fptr){
    printf("********************READING FROM FILE*****************\n");
    rewind(*fptr);
    patient res;
    long int size = sizeof(res);
    
    while(fread(&res, size,1, *fptr)==1){
        printf("Patient id: %d\n",res.uniq_id);
        printf("First name: %s\n",res.firstname);
        printf("last Name: %s\n", res.lastname);
        printf("Aadhar Number: %s\n", res.aadhar_num);
        printf("age: %d\n", res.age);
        printf("Height: %f\n", res.height);
        printf("Weight: %f\n", res.weight);
        printf("Insurance Status: %s\n", (res.insurance == 1) ? "Insured" : "Not Insured");
        printf("Vaccine code: %d\n", res.shot);
        printf("Date of vaccination is: %s\n", res.date_of_vaccine);
        printf("*********************\n");        
    }
    printf("*****************************END************************\n");
    return SUCCESS;
}