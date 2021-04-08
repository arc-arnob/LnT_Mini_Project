#include "prototypes.h"


int main(){
    
    patient *start = NULL;
    vaccine_data col_data = {0};
    patient res ={0};

    // Declaring Function Pointers
    patient *(*fptr_type1)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = create_ll;
    error_t (*fptr_type2)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = insert_end;
    error_t (*fptr_type3)(patient *) = display_ll;
    int choice;
    while(1)
    {
        printf("Press 1 create a Linked List\n");
        printf("Press 2 to Insert a box at the end\n");
        printf("Press 3 find Average volume of all boxes\n");
        printf("Press 4 Count boxes by a given color\n");
        printf("Press 5 to Delete a box\n");
        printf("Press 6 to find a box by id\n");
        printf("Press 7 find box with max height\n");
        printf("Press 8 find min max volume diff\n");
        printf("Press 9 update weight of a box\n");
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
        

            if(choice == 10){
                printf("%d", start->uniq_id);
                (*fptr_type3)(start);
        
            }
        }

        
  
  
  
    }
    
    //delete_all(start);
    


    return 0;

    
}