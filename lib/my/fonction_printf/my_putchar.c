/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** réussis
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}