/*
** EPITECH PROJECT, 2019
** my_putstr_detect.c
** File description:
** réussis
*/


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_putstr_detect(char const *str)
{
    int i;

    i = 0;
    if (str[i] < 32) {
        my_putchar('/');
        my_put_nbr(str[i]);
    }
    while (str [i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}