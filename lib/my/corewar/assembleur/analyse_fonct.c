/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

void crea_info_gater(core_t *info_gater, char **doub_tab, int i)
{
    info_gater->name = malloc(sizeof(char) * 256);
    info_gater->argument = malloc(sizeof(char *) * 3);
    if (same_char(doub_tab[i], "live")) {
        my_strcpy(info_gater->name, "live");
        info_gater->argument[0] = malloc(sizeof(char) * 50);
        my_strcpy(info_gater->argument[0], doub_tab[i + 1]);
    }
    if (same_char(doub_tab[i], "ld")) {
        my_strcpy(info_gater->name, "ld");
        info_gater->argument[0] = malloc(sizeof(char) * 50);
        info_gater->argument[1] = malloc(sizeof(char) * 50);
        my_strcpy(info_gater->argument[0], doub_tab[i + 1]);
        my_strcpy(info_gater->argument[1], doub_tab[i + 2]);
    }
}

void analyse_fonction(char **doub_tab, int fd)
{
    core_t info_gater;

    for (int i = 0; doub_tab[i] != 0; i++){
        if (same_char("live", doub_tab[i]) == 1) {
            crea_info_gater(&info_gater, doub_tab, i);
            live_f(&info_gater, fd);
        }
        if (same_char("ld", doub_tab[i]) == 1) {
            crea_info_gater(&info_gater, doub_tab, i);
            ld_f(&info_gater, fd);
        }
    }
}
