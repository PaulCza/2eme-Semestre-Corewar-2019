/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_arg_func
*/

#include "unit_tests.h"

Test(test_arg_func, test_put_the_roar, .init = redirect_all_std)
{
    cr_assert_eq(put_the_roar(1, "r12"), 0);
}