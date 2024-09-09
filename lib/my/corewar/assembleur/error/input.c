/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** input related functions-desu
*/

#include "my_error.h"

int commentary(char *buf)
{
    int i = 0;

    for (; buf[i] != '\0' && buf[i] != '\n'; i++)
        if (buf[i] == COMMENT_CHAR)
            return 0;
    return 1;
}

input_t *input_rewinder(input_t *info)
{
    while (info->preview != NULL)
        info = info->preview;
    return info;
}

input_t *input_mallocer(void)
{
    input_t *info = malloc(sizeof(input_t));

    info->line = NULL;
    info->len = 0;
    info->next = NULL;
    info->preview = NULL;
    return info;
}

input_t *input_filler(input_t *info, char *buf, ssize_t read)
{
    void *tmp;

    info->line = buf;
    info->len = read;
    tmp = info;
    info->next = input_mallocer();
    if (info->next == NULL)
        return NULL;
    info = info->next;
    info->preview = tmp;
    return info;
}

input_t *input_taker(FILE *adres)
{
    input_t *info = input_mallocer();
    char *buf = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int pos = 0;

    if (info == NULL)
        return NULL;
    while (1) {
        read = getline(&buf, &len, adres);
        if (read == -1)
            return input_rewinder(info);
        else if (my_strlen(buf) > 1 && commentary(buf) != 0) {
            pos += 1;
            info = input_filler(info, buf, read);
            buf = NULL;
        }
    }
}