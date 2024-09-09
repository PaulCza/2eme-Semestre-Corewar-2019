/*
** EPITECH PROJECT, 2019
** hexa.c
** File description:
** réussis
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void hexa(char *res, int v, int x)
{
    int j;
    char res_let = 'a';

    if (v <= 9)
        res[x] = my_transformnbr(v);
    else if (v > 9)
        for (j = 0; j <= 15; j++) {
            if (j == v){
                res[x] = res_let;
                break;
            }
            res_let = res_let + 1;
        }
}

void hexa_maj(char *res, int v, int  x)
{
    int j;
    char res_let = 'a';

    if (v <= 9)
        res[x] = my_transformnbr(v);
    else if (v > 9) {
        for (j = 0; j <= 15; j++) {
            if (j == v){
                res[x] = res_let;
                break;
            }
            res_let = res_let + 1;
        }
    }
}
