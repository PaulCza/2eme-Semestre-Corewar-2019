/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** master file to check the .s-desu
*/

#include "my_error.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return ((s1[i] - s2[i]));
    return (0);
}

char *str_fus(char *str, char *extend)
{
    int i = 0;
    int j = 0;
    char *rsl = NULL;
    int len[2] = {[0 ... 1] = 0};

    len[0] = my_strlen(str);
    len[1] = my_strlen(extend);
    rsl = malloc((len[0] + len[1] + 1) * sizeof(char));
    if (rsl == NULL)
        return NULL;
    rsl[(len[0] + len[1])] = '\0';
    for (; str[i] != '\0'; i++)
        rsl[i] = str[i];
    for (; j < len[1]; j++)
        rsl[(i + j)] = extend[j];
    return rsl;
}

int error_master(input_t *info)
{
    int com = 0;
    int test = 0;
    label_t *l_abel = label_maker();

    if (name_finder(info->line) == 84 || l_abel == NULL)
        return 84;
    if (info->next != NULL)
        info = info->next;
    com = com_finder(info->line);
    if (com == 84)
        return 84;
    else if (com == 0 && info->next != NULL)
        info = info->next;
    while (info->next != NULL) {
        test = label_finder(info->line, &l_abel);
        l_abel = label_rewinder(l_abel);
        if (test == 84)
            return 84;
        info = info->next;}
    l_abel = label_rewinder(l_abel);
    return 0;
}