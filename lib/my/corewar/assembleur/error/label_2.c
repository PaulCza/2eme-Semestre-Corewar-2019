/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** label-desu
*/

#include "my_error.h"

int label_checker(char *str, label_t *l_abel)
{
    char *tmp;

    while (l_abel->next != NULL) {
        tmp = str_fus(l_abel->line, " ");
        if (my_strcmp(str, tmp) == 0)
            return 0;
        l_abel = l_abel->next;
    }
    return 84;
}

char *remov(char *str, int nb)
{
    int i = 0;
    char *tmp = malloc((nb + 1) * sizeof(char));

    tmp[nb] = '\0';
    for (; i < nb; i++)
        tmp[i] = str[i];
    return tmp;
}

int label_finder(char *str, label_t **l_abel)
{
    int i = 0;
    int end = -1;
    char *str_tmp = NULL;

    for (; str[i] != '\0' && str[i] != '\n'
            && (str[i] == ' ' || str[i] == '\t'); i++);
    str_tmp = (str + i);
    for (i = 0; str_tmp[i] != '\0' && str_tmp[i] != '\n'
            && str_tmp[i] != LABEL_CHAR && str_tmp[(i + 1)] != ' '; i++);
    end = i;
    if (str_tmp[end] != LABEL_CHAR && str_tmp[(end + 1)] != ' '
        && str_tmp[(end + 1)] != '\t')
        return 84;
    else if (str_tmp[end] == LABEL_CHAR
            && (str_tmp[(end + 1)] == ' ' || str_tmp[(end + 1)] == '\t')) {
        *l_abel = label_filler(label_forwarder(*l_abel), remov(str, end));
        return 0;}
    else
        return label_checker(str_tmp, *l_abel);
}