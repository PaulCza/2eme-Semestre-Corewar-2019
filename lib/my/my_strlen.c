/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** réussis
*/


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}