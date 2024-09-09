/*
** EPITECH PROJECT, 2019
** dante.c
** File description:
** réussis
*/

#include "my.h"

int same_char(char *str1, char *str2)
{
    int i = 0;

    if (my_strlen(str1) != my_strlen(str2))
        return 0;
    for (; str1[i] != '\0'; i++)
        if (str1[i] != str2[i])
            return 0;
    return 1;
}