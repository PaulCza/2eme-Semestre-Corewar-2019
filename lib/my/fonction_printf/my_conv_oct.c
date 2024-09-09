/*
** EPITECH PROJECT, 2019
** my_convhexa.c
** File description:
** réussis
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_conv_oct(int v)
{
    char *res = malloc(sizeof(char) * v);
    int j = 0;
    int k = 0;

    while (v != 0 && v != 1) {
        k = v % 8;
        res[j] = my_transformnbr(k);
        j++;
        v = v / 8;
    }
    res[j] = my_transformnbr(v);
    my_revstr(res);
    return res;
}