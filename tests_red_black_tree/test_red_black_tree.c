#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "red_black_tree.h"

/**
 * NOTE: in the following ASCII trees, B and R represents Black and Red
 * The number represents the node itself (in order to follow nodes movement)
 */

/**
 *
 */
START_TEST(test_create)
{
    RedBlackTreeNode first_tree = create(10);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    /* simulate the red parent and black uncle violation
       when the inserted node is the left child and
       when the grandparent is the root node of the tree */

    RedBlackTreeNode second_tree = create(10);
    insert(&second_tree, 5);
    insert(&second_tree, 15);
    insert(&second_tree, 3);
    insert(&second_tree, 1);

    ck_assert_int_eq(second_tree.color, BLACK);
    ck_assert_int_eq(second_tree.right->color, BLACK);
    ck_assert_int_eq(second_tree.left->color, BLACK);
    ck_assert_int_eq(second_tree.left->left->color, RED);
    ck_assert_int_eq(second_tree.left->right->color, RED);

    ck_assert_int_eq(second_tree.key, 10);
    ck_assert_int_eq(second_tree.right->key, 15);
    ck_assert_int_eq(second_tree.left->key, 3);
    ck_assert_int_eq(second_tree.left->left->key, 1);
    ck_assert_int_eq(second_tree.left->right->key, 5);

    /* insertion that trigger violations 1 and 2 */

    RedBlackTreeNode third_tree = create(10);
    insert(&third_tree, 5);
    insert(&third_tree, 15);
    insert(&third_tree, 3);
    insert(&third_tree, 1);
    insert(&third_tree, 0);

    ck_assert_int_eq(third_tree.color, BLACK);
    ck_assert_int_eq(third_tree.right->color, BLACK);
    ck_assert_int_eq(third_tree.left->color, RED);
    ck_assert_int_eq(third_tree.left->left->color, BLACK);
    ck_assert_int_eq(third_tree.left->right->color, BLACK);
    ck_assert_int_eq(third_tree.left->left->left->color, RED);

    ck_assert_int_eq(third_tree.key, 10);
    ck_assert_int_eq(third_tree.right->key, 15);
    ck_assert_int_eq(third_tree.left->key, 3);
    ck_assert_int_eq(third_tree.left->left->key, 1);
    ck_assert_int_eq(third_tree.left->right->key, 5);
    ck_assert_int_eq(third_tree.left->left->left->key, 0);
}
END_TEST

/**
 *
 */
START_TEST(test_removeAt)
{
    /* delete a leaf node */

    RedBlackTreeNode first_tree = create(10);
    insert(&first_tree, 5);
    insert(&first_tree, 15);
    insert(&first_tree, 3);

    ck_assert_int_eq(first_tree.color, BLACK);
    ck_assert_int_eq(first_tree.right->color, BLACK);
    ck_assert_int_eq(first_tree.left->color, BLACK);
    ck_assert_int_eq(first_tree.left->left->color, RED);

    ck_assert_int_eq(first_tree.key, 10);
    ck_assert_int_eq(first_tree.right->key, 15);
    ck_assert_int_eq(first_tree.left->key, 5);
    ck_assert_int_eq(first_tree.left->left->key, 3);

    removeAt(&first_tree, 3);

    ck_assert_int_eq(first_tree.key, 10);
    ck_assert_int_eq(first_tree.right->key, 15);
    ck_assert_int_eq(first_tree.left->key, 5);
    ck_assert_ptr_eq(first_tree.left->left, NULL);

    /* delete a node with one left red child, the deleted node is black */

    RedBlackTreeNode second_tree = create(10);
    insert(&second_tree, 5);
    insert(&second_tree, 15);
    insert(&second_tree, 3);

    ck_assert_int_eq(second_tree.color, BLACK);
    ck_assert_int_eq(second_tree.right->color, BLACK);
    ck_assert_int_eq(second_tree.left->color, BLACK);
    ck_assert_int_eq(second_tree.left->left->color, RED);

    ck_assert_int_eq(second_tree.key, 10);
    ck_assert_int_eq(second_tree.right->key, 15);
    ck_assert_int_eq(second_tree.left->key, 5);
    ck_assert_int_eq(second_tree.left->left->key, 3);

    removeAt(&second_tree, 5);

    ck_assert_int_eq(second_tree.color, BLACK);
    ck_assert_int_eq(second_tree.right->color, BLACK);
    ck_assert_int_eq(second_tree.left->color, BLACK);

    ck_assert_int_eq(second_tree.key, 10);
    ck_assert_int_eq(second_tree.right->key, 15);
    ck_assert_int_eq(second_tree.left->key, 3);
    ck_assert_ptr_eq(second_tree.left->left, NULL);

    /* delete a node with one right red child, the deleted node is black */

    RedBlackTreeNode third_tree = create(10);
    insert(&third_tree, 5);
    insert(&third_tree, 15);
    insert(&third_tree, 6);

    ck_assert_int_eq(third_tree.color, BLACK);
    ck_assert_int_eq(third_tree.right->color, BLACK);
    ck_assert_int_eq(third_tree.left->color, BLACK);
    ck_assert_int_eq(third_tree.left->right->color, RED);

    ck_assert_int_eq(third_tree.key, 10);
    ck_assert_int_eq(third_tree.right->key, 15);
    ck_assert_int_eq(third_tree.left->key, 5);
    ck_assert_int_eq(third_tree.left->right->key, 6);

    removeAt(&third_tree, 5);

    ck_assert_int_eq(third_tree.color, BLACK);
    ck_assert_int_eq(third_tree.right->color, BLACK);
    ck_assert_int_eq(third_tree.left->color, BLACK);

    ck_assert_int_eq(third_tree.key, 10);
    ck_assert_int_eq(third_tree.right->key, 15);
    ck_assert_int_eq(third_tree.left->key, 6);
    ck_assert_ptr_eq(third_tree.left->right, NULL);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("red_black_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insert);
    tcase_add_test(tcase, test_removeAt);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
