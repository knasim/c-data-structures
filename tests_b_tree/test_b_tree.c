#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "b_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    BTree tree = create(10);
}
END_TEST

/**
 *
 */
Suite* b_tree_suite()
{
    Suite *suite = suite_create("b_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = b_tree_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
