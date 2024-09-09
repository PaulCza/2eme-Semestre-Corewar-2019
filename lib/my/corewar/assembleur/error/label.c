/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** label related functions-desu
*/

#include "my_error.h"

label_t *label_forwarder(label_t *l_abel)
{
    while (l_abel->next != NULL)
        l_abel = l_abel->next;
    return l_abel;
}

label_t *label_rewinder(label_t *l_abel)
{
    while (l_abel->preview != NULL)
        l_abel = l_abel->preview;
    return l_abel;
}

label_t *label_mallocer(void)
{
    label_t *l_abel = malloc(sizeof(label_t));

    l_abel->line = NULL;
    l_abel->next = NULL;
    l_abel->preview = NULL;
    return l_abel;
}

label_t *label_filler(label_t *l_abel, char *str)
{
    void *tmp;
    char *str_tmp = malloc((my_strlen(str) + 1) * sizeof(char));
    int i = 0;

    if (str_tmp == NULL)
        return NULL;
    str_tmp[my_strlen(str)] = '\0';
    for (; str[i] != '\0'; i++)
        str_tmp[i] = str[i];
    l_abel->line = str_tmp;
    tmp = l_abel;
    l_abel->next = label_mallocer();
    if (l_abel->next == NULL)
        return NULL;
    l_abel = l_abel->next;
    l_abel->preview = tmp;
    return l_abel;
}

label_t *label_maker(void)
{
    label_t *l_abel = label_mallocer();
    char test[16][6] = {"live\0", "ld\0", "st\0", "add\0", "sub\0", "and\0"
                        , "or\0", "xor\0", "zjmp\0", "ldi\0", "sti\0", "fork\0"
                        , "lld\0", "lldi\0", "lfork\0", "aff\0"};
    int i = 0;

    for (; i < 16; i++)
        l_abel = label_filler(l_abel, test[i]);
    l_abel = label_rewinder(l_abel);
    return l_abel;
}