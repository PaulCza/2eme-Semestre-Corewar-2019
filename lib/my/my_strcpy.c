/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** le my_strcpy
*/


#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i;
    int taille;

    i = 0;
    taille = 0;
    for (taille = 0; src[taille] != '\0'; taille++) {
        taille++;
    }
    for (; i <= taille; i++) {
        dest[i] = src[i];
    }
    dest[taille] = '\0';
    return dest;
}