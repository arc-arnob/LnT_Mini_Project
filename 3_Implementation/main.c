#include "prototypes.h"


int main(){
    
    patient *start = NULL;
    vaccine_data col_data = {0};
    patient res ={0};
    int found;

    // Declaring Function Pointers
    patient *(*fptr_type1)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = create_ll;
    error_t (*fptr_type2)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = insert_end;
    error_t (*fptr_type3)(patient *) = display_ll;
    error_t (*fptr_type4)(patient *, int, patient *, int *) = find_by_id;
    int choice;
    while(1)
    {
        printf("Press 1 create a Linked List\n");
        printf("Press 2 to Insert a box at the end\n");
        printf("Press 3 find a patient by Id\n");
        printf("Press 10 to display everthing\n");
        printf("Press -1 to exit.\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);

        if(choice == -1){
            break;
        }

        if (choice >= 1 && choice <= 10)
        {   
            int id;
            char firstname[100]; 
            char lastname[100];
            char aadhar_num[100];
            float height;
            float weight;
            int age;
            char date[20];
            insured insurance;
            vaccine shot;
           
        
            printf("%d is the choice\n", choice);
            if(choice == 1){
                printf("Enter Id of patient\n");
                scanf("%d",&id);
                printf("Enter First Name\n");
                scanf("%s", firstname);
                printf("Enter the last name\n");
                scanf("%s",lastname);
                printf("Enter height of the patient\n");
                scanf("%f",&height);
                printf("Enter weight of patient\n");
                scanf("%f",&weight);
                printf("enter aadhar card number\n");
                scanf("%s",aadhar_num);
                printf("Enter age of the patient\n");
                scanf("%d",&age);
                printf("Is the patient insured?\n");
                scanf("%d",&insurance);
                printf("Enter the name of the vaccine recieved\n");
                scanf("%d",&shot);
                start = (*fptr_type1)(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
            }
            if(choice == 2){
                printf("Enter Id of patient\n");
                scanf("%d",&id);
                printf("Enter First Name\n");
                scanf("%s", firstname);
                printf("Enter the last name\n");
                scanf("%s",lastname);
                printf("Enter height of the patient\n");
                scanf("%f",&height);
                printf("Enter weight of patient\n");
                scanf("%f",&weight);
                printf("enter aadhar card number\n");
                scanf("%s",aadhar_num);
                printf("Enter age of the patient\n");
                scanf("%d",&age);
                printf("Is the patient insured?\n");
                scanf("%d",&insurance);
                printf("Enter the name of the vaccine recieved\n");
                scanf("%d",&shot);
                error_t code = (*fptr_type2)(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
            
            }

            if(choice == 3){
                printf("Please enter the id of the patient\n");
                scanf("%d", &id); // perform validation
                error_t code = (*fptr_type4)(start, id, &res, &found);
                if(found == 1){
                    printf("Patient Record Found\n");
                    printf("first Name: %s\n", res.firstname);
                    printf("last Name: %s\n", res.lastname);
                    printf("Aadhar Number: %s\n", res.aadhar_num);
                    printf("age: %d\n", res.age);
                    printf("Height: %d\n", res.height);
                    printf("Weight: %d\n", res.weight);
                    printf("Insurance Status: %s\n", (res.insurance == 1) ? "Insured" : "Not Insured");
                    printf("Vaccine code: %d\n", res.shot);

                }
            }

            if(choice == 10){
                printf("%d", start->uniq_id);
                (*fptr_type3)(start);
        
            }
        }

        
  
  
  
    }
    
    //delete_all(start);
    


    return 0;

    
}