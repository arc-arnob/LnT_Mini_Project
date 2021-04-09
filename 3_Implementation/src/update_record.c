#include "prototypes.h"

error_t update_record(patient *start, int id, int choice, int test){

    patient *ptr;
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
        if(found == 1 && test == 0){
            /* For Unit Testing, make some default values */
            if(choice == 1){
                char name[100];
                printf("Please enter the new first name\n");
                scanf("%s", name);
                strcpy(ptr->firstname,name);
            }
            if(choice == 2){
                char name[100];
                printf("Please enter the new last name\n");
                scanf("%s", name);
                strcpy(ptr->lastname,name);
            }
            if(choice == 3){
                int age;
                printf("Please enter the new age\n");
                scanf("%d", &age);
                ptr->age = age;
            }
            if(choice == 4){
                int height;
                printf("Please enter the new height\n");
                scanf("%d", &height);
                ptr->height = height;
            }
            if(choice == 5){
                int weight;
                printf("Please enter the new weight\n");
                scanf("%d", &weight);
                ptr->weight = weight;
            }
            if(choice == 6){
                int code;
                printf("Please enter the new vaccine code\n");
                scanf("%d", &code);
                ptr->shot = code;
            }
            if(choice == 7){
                char name[100];
                printf("Please enter the new vaccine date\n");
                scanf("%s", name);
                strcpy(ptr->date_of_vaccine,name);
            }
        }

        return SUCCESS;
    }

} 