/*
** EPITECH PROJECT, 2019
** sum_stdarg.c
** File description:
** réussis
*/

#include "my.h"

int sum_stdarg(int i, int nb, ...)
{
    int n;
    int res = 0;
    char *nl;
    va_list a;

    va_start(a, nb);
    if (i == 0) {
    for (;nb > 0; nb--) {
        n = va_arg(a, int);
        res = res + n;
        }
    }
    if (i == 1){
    for (;nb > 0; nb--) {
        nl = va_arg(a, char *);
        res = res + my_strlen(nl);
        }
    }
    va_end(a);
    return res;
}