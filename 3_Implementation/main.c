#include "prototypes.h"


int main(){


    FILE *f = NULL;
    // Read the file, go to the end, divide by 4(for int) and malloc size for that.
    error_t indexfile = indexFile("INDEX.DAT","rb+",&f);
    int lsize = fseek(f,0, SEEK_END);
    int size = ftell(f);
    printf("size is %d: \n",size);
    

    patient *start = NULL;
    vaccine_data col_data = {0};
    patient res ={0};
    int found;

    // Declaring Function Pointers
    patient *(*fptr_type1)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = create_ll;
    error_t (*fptr_type2)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = insert_end;
    error_t (*fptr_type3)(patient *) = display_ll;
    error_t (*fptr_type4)(patient *, int, patient *, int *) = find_by_id;
    error_t (*fptr_type5)(patient *, int, int, int) = update_record;
    int choice;
    while(1)
    {
        printf("Press 1 create a Linked List\n");
        printf("Press 2 to Insert a box at the end\n");
        printf("Press 3 find a patient by Id\n");
        printf("Press 4 to Update Patient's Record\n");
        printf("Press 5 to save data to file\n");
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
                //step 1 validation to check existing ids
                rewind(f);
                error_t code =  validate_id(&f,id);
                if(code == ID_EXISTS){
                    printf("Id already exist, choose something else\n");
                    continue;
                }
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
                printf("Enter the date of vaccination\n");
                scanf("%s", date);
                start = (*fptr_type1)(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
                

                // step 2 add index to file if not
                fseek(f,0,SEEK_END);
                fwrite(&id,4,1,f);
                fflush(stdin);
                
            }
            if(choice == 2){
                printf("Enter Id of patient\n");
                scanf("%d",&id);
                //step 1 validation to check existing ids
                rewind(f);
                error_t file_code =  validate_id(&f,id);
                if(file_code == ID_EXISTS){
                    printf("Id already exists, choose something else\n");
                    continue;
                }
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
                printf("Enter the date of vaccination\n");
                scanf("%s", date);
                error_t code = (*fptr_type2)(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
                // step 2 add index to file if not
                fseek(f,0,SEEK_END);
                fwrite(&id,4,1,f);
                fflush(stdin);
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
                    printf("Height: %f\n", res.height);
                    printf("Weight: %f\n", res.weight);
                    printf("Insurance Status: %s\n", (res.insurance == 1) ? "Insured" : "Not Insured");
                    printf("Vaccine code: %d\n", res.shot);
                    printf("Date of vaccination is: %s\n", res.date_of_vaccine);

                }
            }

            if(choice == 4){
                printf("Please Enter the patient id:\n");
                scanf("%d", &id);
                error_t code = (*fptr_type4)(start, id, &res ,&found);
                if(found == 1){
                    printf("Patient Found with id: %d\n", res.uniq_id);
                    int choice_2;
                    printf("Please select the field you want to update\n");
                    printf("Press 1 to update first name\n");
                    printf("Press 2 to update last name\n");
                    printf("Press 3 to update age\n");
                    printf("Press 4 to update height\n");
                    printf("Press 5 to update weight\n");
                    printf("Press 6 to update vaccine code\n");
                    printf("Press 7 to update date of vaccine\n");
                    scanf("%d", &choice_2);
                    error_t code = (*fptr_type5)(start, id, choice_2, 0); // 0 is for prod run.
                    printf("**********Record Updated**********\n");
                }else{
                    printf("NO RECORD FOUND\n");
                }
                
            }

            if(choice == 10){
                printf("%d", start->uniq_id);
                (*fptr_type3)(start);
        
            }
            
        }

        
  
  
    
    }
    fclose(f);
    
    //delete_all(start);
    


    return 0;

    
}