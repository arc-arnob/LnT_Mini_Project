#include "prototypes.h"
#include "unity.h"

patient *start = NULL;


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