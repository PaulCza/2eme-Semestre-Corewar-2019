/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** le put str
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"


int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str [i] != '\0'){
        my_putchar(str [i]);
        i++;
        }
    return 0;
}