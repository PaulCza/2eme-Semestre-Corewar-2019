/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_printf
*/

#include "unit_tests.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(test_my_printf, print_char, .init = redirect_all_std)
{
    my_printf("%c", 'c');
    cr_assert_stdout_eq_str("c");
}

Test(test_my_printf, print_char_str, .init = redirect_all_std)
{
    my_printf("ab%c", 'c');
    cr_assert_stdout_eq_str("abc");
}

Test(test_my_printf, print_a_str, .init = redirect_all_std)
{
    my_printf("%s", "blabla");
    cr_assert_stdout_eq_str("blabla");
}

Test(test_my_printf, print_a_Str, .init = redirect_all_std)
{
    my_printf("%S", "blabla");
    cr_assert_stdout_eq_str("blabla");
}

Test(test_my_printf, print_str_str, .init = redirect_all_std)
{
    my_printf("bla = %s", "blabla");
    cr_assert_stdout_eq_str("bla = blabla");
}

Test(test_my_printf, print_a_nbr, .init = redirect_all_std)
{
    my_printf("%i", 12);
    cr_assert_stdout_eq_str("12");
}

Test(test_my_printf, print_str_nbr, .init = redirect_all_std)
{
    my_printf("4 * 3 = %i", 12);
    cr_assert_stdout_eq_str("4 * 3 = 12");
}

Test(test_my_printf, print_percent, .init = redirect_all_std)
{
    my_printf("%%v", 'c');
    cr_assert_stdout_eq_str("%v");
}

Test(test_my_printf, convert_bin, .init = redirect_all_std)
{
    my_printf("%b", 12);
    cr_assert_stdout_eq_str("1100");
}

Test(test_my_printf, convert_oct, .init = redirect_all_std)
{
    my_printf("%o", 12);
    cr_assert_stdout_eq_str("14");
}

Test(test_my_printf, convert_heX, .init = redirect_all_std)
{
    my_printf("%X", 321);
    cr_assert_stdout_eq_str("141");
}

Test(test_my_printf, convert_hex, .init = redirect_all_std)
{
    my_printf("%x", 321);
    cr_assert_stdout_eq_str("141");
}