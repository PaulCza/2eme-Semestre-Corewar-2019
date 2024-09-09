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

void *my_revstr(char *e)
{
    char *c = e;
    char g;

    while (*c != '\0')
        c++;
    while (e < --c) {
        g = *e;
        *e++ = *c;
        *c = g;
    }
    return e;
}