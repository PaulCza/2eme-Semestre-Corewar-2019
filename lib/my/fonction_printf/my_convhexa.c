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

char *my_convhexa(int a)
{
    int i = 16;
    int v = a;
    int x = 0;
    char *res = malloc(sizeof(char)*(a/16));

    while (i < a)
        i = i * 16;
    i = i / 16;
    if (a < 9)
        res[0] = my_transformnbr(a);
    if (a > 9) {
        while (i != 0) {
            v = a / i;
            hexa(res, v, x);
            a = a % i;
            i = i / 16;
            x++;
        }
    }
    return res;
}

char *my_convhexa_maj(int a)
{
    int i = 16;
    int v = a;
    int x = 0;
    char *res = malloc(sizeof(char)*(a/16));

    while (i < a)
        i = i * 16;
    i = i / 16;
    if (a < 9)
        res[0] = my_transformnbr(a);
    if (a > 9){
        while (i != 0){
            v = a / i;
            hexa_maj(res, v, x);
            a = a % i;
            i = i / 16;
            x++;
        }
    }
    return res;
}