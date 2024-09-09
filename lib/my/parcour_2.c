/*
** EPITECH PROJECT, 2019
** my_transformnbr.c.c
** File description:
** réussis
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void four(char nm, va_list a)
{
    char *nl;

    switch (nm) {
        case '%':
            my_putchar('%');
            break;
        case 'S':
            nl = va_arg(a, char *);
            my_putstr_detect(nl);
            break;
    }
}

void three(char nm, va_list a)
{
    int n;
    char *nl;

    switch (nm) {
        case 'x':
            n = va_arg(a, int);
            nl = malloc(sizeof(char) * n);
            nl = my_convhexa(n);
            my_putstr(nl);
            break;
        case 'o':
            n = va_arg(a, int);
            nl = malloc(sizeof(char) * n);
            nl = my_conv_oct(n);
            my_putstr(nl);
            break;
    }
}