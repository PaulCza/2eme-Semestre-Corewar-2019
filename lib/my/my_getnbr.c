/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** réussis
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void part_2(getnbr_t *get, char const *str)
{
    get -> b = is_a_nbr(str[get -> j]);
    get -> i = get -> j;
    while (is_a_nbr(str [get -> i + 1]) != -1){
        get -> pui = get -> pui * 10;
        get -> i += 1;
    }
    get -> b = get -> b * get -> pui;
    get -> res = get -> res + get -> b;
    get -> j += 1;
    get -> pui = 1;
}

getnbr_t init_get(getnbr_t get)
{
    get.j = 0;
    get.i = 0;
    get.res = 0;
    get.pui = 1;
    return get;
}

int is_a_nbr(char j)
{   char res = '0';
    int i = 0;

    for (i = 0; i <= 9; i++){
        if (res == j)
            return i;
        res++;
    }
    return -1;
}

int my_getnbr(char const *str)
{
    getnbr_t get = init_get(get);

    while (is_a_nbr(str[get.i]) == -1)
        get.i = get.i + 1;
    get.j = get.i;
    while (is_a_nbr(str[get.j]) != -1)
        part_2(&get, str);
    if (str[0] == '-')
        get.res = get.res * -1;
    return get.res;
}