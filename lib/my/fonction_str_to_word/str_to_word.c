/*
** EPITECH PROJECT, 2019
** str_to_word.c
** File description:
** réussis
*/


#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include <unistd.h>
#include <fcntl.h>

int count_space(char *str)
{
    int res = 0;
    int i = 0;
    int e = 1;

    for (i = 0; str[i] == ' ' || str[i] == '\t'; i++);
    for (;str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' && e == 1) {
            res++;
            e = 0;
        }
        if (str[i] != ' ' && str[i] != '\t')
            e = 1;
    }
    return res;
}

void decompo(char **res, char *str)
{
    int i = 0;
    int j = 0;
    int y = 0;
    int e = 1;

    res[j] = malloc(sizeof(char) * 320);
    for (i = 0; str[i] == ' ' || str[i] == '\0' || str[i] == '\t'; i++);
    for (;str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' && e == 1) {
            j++;
            e = 0;
            y = 0;
            res[j] = malloc(sizeof(char) * 320);
        }
        if (str[i] != ' ' && str[i] != '\t') {
            e = 1;
            res[j][y] = str[i];
            y++;
        }
    }
}

char **str_to_word(char *str)
{
    int nbr_space = count_space(str);
    char **res = malloc(nbr_space * sizeof(char) * 100);

    decompo(res, str);
    return res;
}