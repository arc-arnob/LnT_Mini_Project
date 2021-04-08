#include "prototypes.h"
#include "unity.h"

box *start = NULL;
average_vol_data avg_data = {0};
color_data col_data = {0};
box res ={0};
max_height_data data ={0};
float diff = 0;

/* Required by the unity test framework */
void setUp()
{
}
/* Required by the unity test framework */
void tearDown()
{
}

void test_create(void){

    start = create_ll(start,1,1,1,1,1,GREEN);
    TEST_ASSERT_EQUAL(1,start->uniq_id);
    TEST_ASSERT_EQUAL(1,start->color);


}

void test_insert(void){
    
    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,2,1,1,1,1,RED));
    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,3,1,1,1,1,BLUE));
    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,4,1,1,1,1,BLUE));
    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,5,1,1,1,1,BLUE));
    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,6,1,1,1,1,BLUE));
    TEST_ASSERT_EQUAL(SUCCESS, insert_end(start,2,10,20,100,100,BLUE));
}

void test_count(void){

    TEST_ASSERT_EQUAL(SUCCESS, count_by_color(start,&col_data,BLUE));
    TEST_ASSERT_EQUAL(5,col_data.num);
}

void test_delete(void){
    TEST_ASSERT_EQUAL(SUCCESS, delete_box(start,5));
}
void test_display(void){
    TEST_ASSERT_EQUAL(SUCCESS, display_ll(start));

}
void test_find(void){
    
    TEST_ASSERT_EQUAL(SUCCESS, find_by_id(start,3,&res));
    TEST_ASSERT_EQUAL(3, res.uniq_id);
    TEST_ASSERT_EQUAL(0,find_by_id(start,312,&res));

}
void test_maxHeight(void){

    TEST_ASSERT_EQUAL(SUCCESS, find_max_height(start,&data));
    TEST_ASSERT_EQUAL(100,data.height);



}
void test_diff(void){
    TEST_ASSERT_EQUAL(SUCCESS,min_max_v_diff(start, &diff));
    TEST_ASSERT_EQUAL(19999,diff);

}
void test_avgVol(void){
    TEST_ASSERT_EQUAL(SUCCESS,avg_volume(start,&avg_data));
    TEST_ASSERT_EQUAL(2858,avg_data.average);

}
void test_updateWeight(void){
    TEST_ASSERT_EQUAL(SUCCESS,update_weight(start, 2, 1000));

}

int main(void)
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    /* Run Test functions */
    RUN_TEST(test_create);
    RUN_TEST(test_insert);
    RUN_TEST(test_count);
    RUN_TEST(test_find);
    RUN_TEST(test_maxHeight);
    RUN_TEST(test_avgVol);
    RUN_TEST(test_diff);
    //RUN_TEST(test_display);
    RUN_TEST(test_updateWeight);
    RUN_TEST(test_delete);


    /* Close the Unity Test Framework */
    return UNITY_END();
}



//gcc -I inc -I unity unity/unity.c src/create_ll.c src/display_ll.c src/insert_end.c src/delete_box.c src/avg_volume.c src/count_by_color.c src/find_by_id.c src/min_max_v_diff.c src/find_max_height.c src/update_weight.c test/test.c -o testrun.exe   