#include "prototypes.h"


int main(){

    int inserted_flag = 0;
    FILE *f = NULL;
    FILE *r = NULL;
    FILE *rt = NULL;
    patient *start = NULL;
    error_t indexfile = indexFile("INDEX.DAT","rb+",&f);
    
    error_t recordFile = openFile("RECORD.DAT","rb+", &r);
    int data_loaded_flag = 0;
    printf("PRESS 1 if you want to load File data or press 0 to continue: \n");
    int ch;
    scanf("%d",&ch);
    if(ch==1){
        printf("LOADING DATA...\n");
        start = loadData(start, &r);
        inserted_flag = 1;
        printf("DATA LOADED...\n");
    }

    
    //int rsize = fseek(r,0, SEEK_END);
    // int size = ftell(r);
    // printf("SIZE OF RECORD.DAT is %d\n",size); // data is getting stored.
    

    
    // vaccine_data col_data = {0};
    patient res ={0};
    int found;
    

    // Declaring Function Pointers
    patient *(*fptr_type1)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = create_ll;
    error_t (*fptr_type2)(patient *,int, char *, char *, char *, float, float,int,char *, insured, vaccine) = insert_end;
    error_t (*fptr_type3)(patient *) = display_ll;
    error_t (*fptr_type4)(patient *, int, patient *, int *) = find_by_id;
    error_t (*fptr_type5)(patient *, int, int, int) = update_record;
    error_t (*fptr_type6)(patient *, FILE **, int *) = saveFile;
    int choice;
    while(1)
    {
        printf("Press 1 create a Linked List\n");
        printf("Press 2 to Insert a box at the end\n");
        printf("Press 3 find a patient by Id\n");
        printf("Press 4 to Update Patient's Record\n");
        printf("Press 5 to save data to file\n");
        printf("Press 6 to print data from file\n");
        printf("Press 7 to delete data from record");
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
            char firstname[101]; 
            char lastname[101];
            char aadhar_num[21];
            float height;
            float weight;
            int age;
            char date[13];
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
                scanf("%100s", firstname);
                printf("Enter the last name\n");
                scanf("%100s",lastname);
                printf("Enter height of the patient\n");
                scanf("%f",&height);
                printf("Enter weight of patient\n");
                scanf("%f",&weight);
                printf("enter aadhar card number\n");
                scanf("%20s",aadhar_num);
                printf("Enter age of the patient\n");
                scanf("%d",&age);
                printf("Is the patient insured?\n");
                scanf("%d",&insurance);
                printf("Enter the name of the vaccine recieved\n");
                scanf("%d",&shot);
                printf("Enter the date of vaccination\n");
                scanf("%12s", date);
                start = (*fptr_type1)(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
                

                // step 2 add index to file if not
                fseek(f,0,SEEK_END);
                fwrite(&id,4,1,f);
                inserted_flag = 1;

                
                
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
                scanf("%100s", firstname);
                printf("Enter the last name\n");
                scanf("%100s",lastname);
                printf("Enter height of the patient\n");
                scanf("%f",&height);
                printf("Enter weight of patient\n");
                scanf("%f",&weight);
                printf("enter aadhar card number\n");
                scanf("%20s",aadhar_num);
                printf("Enter age of the patient\n");
                scanf("%d",&age);
                printf("Is the patient insured?\n");
                scanf("%d",&insurance);
                printf("Enter the name of the vaccine recieved\n");
                scanf("%d",&shot);
                printf("Enter the date of vaccination\n");
                scanf("%12s", date);
                error_t code = (*fptr_type2)(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
                // step 2 add index to file if not
                fseek(f,0,SEEK_END);
                fwrite(&id,4,1,f);
                inserted_flag = 1;
              
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

                }else{
                    printf("Patient Record Not Found\n");
                }
                
            }

            if(choice == 4){
                int choice_3;
                printf("Press 1 to update File Record\n");
                printf("Press 2 to update Disk Record\n");
                scanf("%d",&choice_3);
                if(2 == choice){
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
                }else{
                    printf("Please Enter the patient id:\n");
                    scanf("%d", &id);
                    rewind(f);
                    error_t code = validate_id(&f,id);
                    if(code == ID_EXISTS){
                        update_data_file(&r,id);
                        printf("RECORD UPDATED\n");
                    }else{
                        printf("NO RECORD FOUND");
                    }

                }
                
            }

            if(choice == 5){
                printf("Savind Data to file...\n");
                error_t code = (*fptr_type6)(start, &r, &ch);
                printf("Data Saved!\n");

            }
            if(choice == 6){
                error_t code = readFile(&r);
            }

            if(choice == 7){
                printf("Please enter the id of the patient\n");
                scanf("%d", &id); // perform validation
                error_t code = (*fptr_type4)(start, id, &res, &found);
                if(found == 1){
                    start = delete_patient(start,id);
                    error_t del_code_2 = delete_rec_file(&r,&rt,id);

                    // Performing clean up
                    fclose(rt);
                    fclose(r);
                    remove("RECORD.DAT");
                    rename("TEMP.DAT", "RECORD.DAT");

                    openFile("RECORD.DAT","rb+",&r);

                    //Updating INDEX file
                    error_t del_idx_code = delete_index_file(&f,&rt,id);
                    //fclose(rt);
                    fclose(f);
                    remove("INDEX.DAT");
                    rename("TEMP.DAT", "INDEX.DAT");

                    openFile("INDEX.DAT","rb+",&f);

                }else{
                    error_t del_code = delete_rec_file(&r,&rt,id);
                    
                    // Updating RECORD file
                    //fclose(rt);
                    fclose(r);
                    remove("RECORD.DAT");
                    rename("TEMP.DAT", "RECORD.DAT");

                    openFile("RECORD.DAT","rb+",&r);

                    //Updating INDEX file
                    error_t del_idx_code = delete_index_file(&f,&rt,id);
                    fclose(rt);
                    fclose(f);
                    remove("INDEX.DAT");
                    rename("TEMP.DAT", "INDEX.DAT");

                    openFile("INDEX.DAT","rb+",&f);
                }
                printf("Record Updated\n");
            }

            if(choice == 10){
                printf("%d", start->uniq_id);
                (*fptr_type3)(start);
        
            }
            
        }

        
  
  
    
    }
    if(inserted_flag==1) (*fptr_type6)(start, &r, &ch);

    fclose(f);
    fclose(r);
    printf("Here deleting!\n");
    delete_all(start);
    
    


    return 0;

    
}