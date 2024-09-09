/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** here to find the name and the comentary-desu
*/

#include "my_error.h"

int name_finder_2(char *str)
{
    int d_quote = 0;
    int i = 0;
    int error = 0;

    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == '"')
            d_quote++;
        if (d_quote != 1 && (str[i] != ' ' && str[i] != '\t'
            && str[i] != '"'))
            error++;
    }
    if (d_quote != 2 || error != 0)
        return 84;
    return 0;
}

int name_finder(char *str)
{
    char *to_test = str_fus(NAME_CMD_STRING, " ");
    int i = 0;

    if (to_test == NULL)
        return 84;
    for (; str[i] != '\0' && str[i] != to_test[0]; i++);
    if (str[i] == to_test[0] && my_strcmp(to_test, (str + i)) == 0) {
        i += my_strlen(to_test);
        return name_finder_2((str + i));
    }
    return 84;
}

int com_finder_2(char *str)
{
    int d_quote = 0;
    int i = 0;
    int error = 0;

    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == '"')
            d_quote++;
        if (d_quote != 1 && (str[i] != ' ' && str[i] != '\t'
            && str[i] != '"'))
            error++;
    }
    if (d_quote != 2 || error != 0)
        return 84;
    return 0;
}

int com_finder(char *str)
{
    char *to_test = str_fus(COMMENT_CMD_STRING, " ");
    int i = 0;

    if (to_test == NULL)
        return 84;
    for (; str[i] != '\0' && str[i] != to_test[0]; i++);
    if (str[i] == to_test[0] && my_strcmp(to_test, (str + i)) == 0) {
        i += my_strlen(to_test);
        return com_finder_2((str + i));
    }
    return 42;
}