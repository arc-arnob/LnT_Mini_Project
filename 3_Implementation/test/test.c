#include "prototypes.h"
#include "unity.h"

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

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

int data_loaded_flag = 0;
int ch;

FILE *f = NULL;
FILE *r = NULL;
FILE *rt = NULL;
patient *start = NULL;

int old_count,count;

void check_openFile(void){
    TEST_ASSERT_EQUAL(SUCCESS,indexFile("INDEX.DAT","rb+",&f));
    TEST_ASSERT_EQUAL(SUCCESS,openFile("RECORD.DAT","rb+",&r));

}

void test_create(void){
    id = 1;
    strcpy(firstname, "testuser1");
    strcpy(lastname, "lastuser1");
    strcpy(aadhar_num,"123456789");
    height = 167.0;
    weight = 76.1;
    age = 34;
    strcpy(date,"12-01-21");
    insurance = 1;
    shot = 2;
    

    start = create_ll(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
    
    fseek(f,0,SEEK_END);
    fwrite(&id,4,1,f);

    TEST_ASSERT_EQUAL(1,start->uniq_id);
    TEST_ASSERT_EQUAL_STRING("testuser1",start->firstname);
    TEST_ASSERT_EQUAL_STRING("lastuser1",start->lastname);
    TEST_ASSERT_EQUAL_STRING("123456789",start->aadhar_num);


}

void test_file_initilizaion(void){

}

void test_insert(void){
    // With head
    id = 2;
    strcpy(firstname, "testuser2");
    strcpy(lastname, "lastuser2");
    strcpy(aadhar_num,"123456789");
    height = 167.0;
    weight = 76.1;
    age = 34;
    strcpy(date,"12-01-21");
    insurance = 0;
    shot = 1;

    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot));
    fseek(f,0,SEEK_END);
    fwrite(&id,4,1,f);

    id = 3;
    strcpy(firstname, "testuser3");
    strcpy(lastname, "lastuser2");
    strcpy(aadhar_num,"123456789");
    height = 167.0;
    weight = 76.1;
    age = 34;
    strcpy(date,"12-01-21");
    insurance = 0;
    shot = 1;

    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot));
    fseek(f,0,SEEK_END);
    fwrite(&id,4,1,f);


}

void check_idx_file_insertion(void){
    rewind(f);
    TEST_ASSERT_EQUAL(ID_EXISTS,validate_id(&f,1));
    rewind(f);
    TEST_ASSERT_EQUAL(ID_EXISTS,validate_id(&f,2));
    rewind(f);
    TEST_ASSERT_EQUAL(ID_EXISTS,validate_id(&f,3));
    rewind(f);
    TEST_ASSERT_EQUAL(SUCCESS,validate_id(&f,4));

}

void check_file_save(void){
    int ch = 0;
    TEST_ASSERT_EQUAL(SUCCESS, saveFile(start, &r, &ch));
}

void check_file_display(void){
        
        TEST_ASSERT_EQUAL(SUCCESS, readFile(&r));
}

void check_find_by_id(void){
        patient res ={0};
        id = 3;
        int found = 0;
        TEST_ASSERT_EQUAL(SUCCESS, find_by_id(start,id,&res,&found));
        TEST_ASSERT_EQUAL(1,found);
        id = 5;
        find_by_id(start,id,&res,&found);
        TEST_ASSERT_EQUAL(0,found);
}

void check_update_record(void){
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,1,1));
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,2,1));
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,3,1));
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,4,1));
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,5,1));
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,6,1));
    TEST_ASSERT_EQUAL(SUCCESS,update_record(start,2,7,1));
    
}

void check_delete_node(void){
    old_count = 1;
    patient *ptr;
    ptr = start;
    while(ptr->next != NULL){
        old_count++;
        ptr = ptr->next;
    }
    TEST_ASSERT_EQUAL(3,old_count);
    start = delete_patient(start,3);
    count = 1;
    ptr = start;
    while(ptr->next != NULL){
        count++;
        ptr = ptr->next;
    }
    TEST_ASSERT_EQUAL(2,count);

}

void check_delete_rec_file(void){
    id = 1;
    TEST_ASSERT_EQUAL(SUCCESS, delete_rec_file(&r,&rt,id));
}

void check_delete_idx_file(void){
    id = 1;
    TEST_ASSERT_EQUAL(SUCCESS, delete_index_file(&r,&rt,id));
}



void check_uniq_id(void){
    id = 10;
    strcpy(firstname, "testuser2");
    strcpy(lastname, "lastuser2");
    strcpy(aadhar_num,"123456789");
    height = 167.0;
    weight = 76.1;
    age = 34;
    strcpy(date,"12-01-21");
    insurance = 0;
    shot = 1;
    insert_end(start,id,firstname,lastname,aadhar_num,height,weight,age,date,insurance,shot);
    fseek(f,0,SEEK_END);
    fwrite(&id,4,1,f);

    id = 2;
    rewind(f);
    TEST_ASSERT_EQUAL(SUCCESS,validate_id(&f,4));
    
}


 //L_04
void check_data_loaded_write(void){
    delete_all(start);
    start = loadData(start, &r);
    TEST_ASSERT_NOT_EQUAL(NULL,start);

}



    





int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(check_openFile);
    RUN_TEST(test_create);
    RUN_TEST(test_insert);
    RUN_TEST(check_idx_file_insertion);
    RUN_TEST(check_file_save);
    RUN_TEST(check_file_display);
    RUN_TEST(check_find_by_id);
    RUN_TEST(check_update_record);
    RUN_TEST(check_delete_node);
    RUN_TEST(check_delete_rec_file);
    RUN_TEST(check_delete_idx_file);
    RUN_TEST(check_uniq_id);
    RUN_TEST(check_data_loaded_write);
    


    /* Close the Unity Test Framework */
    return UNITY_END();
}



//gcc -I inc -I unity unity/unity.c src/create_ll.c src/display_ll.c src/insert_end.c src/delete_box.c src/avg_volume.c src/count_by_color.c src/find_by_id.c src/min_max_v_diff.c src/find_max_height.c src/update_weight.c test/test.c -o testrun.exe   