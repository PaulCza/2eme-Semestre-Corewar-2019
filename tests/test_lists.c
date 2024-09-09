/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_lists
*/

#include "unit_tests.h"

Test(test_lists, functionnal_test, .init = redirect_all_std)
{
    list test_list = NULL;

    push_back_list(test_list, 2);
    push_back_list(test_list, 3);
    push_back_list(test_list, 4);
    push_front_list(test_list, 1);
    del_back_list(test_list);
    del_front_list(test_list);
    print_list(test_list);
    clear_list(test_list);
    print_list(test_list);
}