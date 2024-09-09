/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_lib
*/

#include "unit_tests.h"

//////////////////////TEST PUTS//////////////////////////////////
Test(test_my_strlen, good_lenght)
{
    cr_assert_eq(my_strlen("Hello World"), 11);
}

Test(test_my_putchar, put_a_char, .init = redirect_all_std)
{
    my_putchar('c');
    cr_assert_stdout_eq_str("c");
}

Test(test_my_putstr, put_a_str, .init = redirect_all_std)
{
    my_putstr("Hello I'm your friend");
    cr_assert_stdout_eq_str("Hello I'm your friend");
}

Test(test_my_putnbr, put_a_nbr, .init = redirect_all_std)
{
    my_put_nbr(1234);
    cr_assert_stdout_eq_str("1234");
}

Test(test_my_putnbr, put_a_neg_nbr, .init = redirect_all_std)
{
    my_put_nbr(-1234);
    cr_assert_stdout_eq_str("-1234");
}

//////////////////////////////TEST GETNBR/////////////////////////
Test(get_nbr, positive_int)
{
    cr_assert_eq(my_getnbr("124"), 124);

}

Test(get_nbr, negative_int)
{
    cr_assert_eq(my_getnbr("-124"), - 124);
    cr_assert_eq(my_getnbr("---------124"), - 124);
}

Test(get_nbr, sign_in_the_middle)
{
    cr_assert_eq(my_getnbr("126-78912"), 126);
    cr_assert_eq(my_getnbr("-123+45678912"), - 123);
}

Test(get_nbr, lots_of_0)
{
    cr_assert_eq(my_getnbr("000000000000000000000012"), 12);
    cr_assert_eq(my_getnbr("-000000000000000000000012"), - 12);
}

Test(get_nbr, not_nbr)
{
    cr_assert_eq(my_getnbr("a"), 0);
    cr_assert_eq(my_getnbr("-123a12"), - 123);
}