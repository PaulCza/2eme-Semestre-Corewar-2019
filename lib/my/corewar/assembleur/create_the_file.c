/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

int namelen_finder(char *str, int *pos)
{
    int i = 0;
    int j = 0;
    int len = 0;

    for (; str[i] != '\0' && str[i] != '.'; i++);
    if (str[i] == '.')
        for (j = i; j > 0 && str[j] != '/'; j--);
    if (str[j] == '/') {
        len = (i - j - 1);
        pos[0] = (j + 1);
    } else if (j == 0) {
        len = (i - j);
        pos[0] = j;
    }
    pos[1] = i;
    return len;
}

char *name_converter(char *str, char *extend)
{
    int i = 0;
    int j = 0;
    char *rsl = NULL;
    int len[2] = {[0 ... 1] = 0};
    int pos[2] = {[0 ... 1] = 0};

    len[0] = namelen_finder(str, pos);
    len[1] = my_strlen(extend);
    rsl = malloc((len[0] + len[1] + 1) * sizeof(char));
    if (rsl == NULL)
        return NULL;
    rsl[(len[0] + len[1])] = '\0';
    for (; (i + pos[0]) < pos[1]; i++)
        rsl[i] = str[(i + pos[0])];
    for (; j < len[1]; j++)
        rsl[(i + j)] = extend[j];
    return rsl;
}

int create_the_file(char *name, thewall_t *thewall)
{
    char *new_name = name_converter(name, ".cor");
    int fd = 0;

    if (new_name == NULL)
        return 84;
    if ((fd = open(new_name, O_WRONLY | O_CREAT | O_TRUNC,
    S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
        return (-1);
    return fd;
}