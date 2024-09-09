/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** need to be fill-desu
*/

#include "my.h"
#include "op.h"

char wiew_the_arg2(core_t *info_gater, char temporaire);

char wiew_the_arg(core_t *info_gater, int i)
{
    char temporaire = 0x00;

    if (i == 0 && info_gater->argument[0] != NULL) {
        if (info_gater->argument[0][0] == '%')
            return (temporaire = 0x80 >> 0);
        else if (info_gater->argument[0][0] == 'r')
            return (temporaire = 0x40 >> 0);
        else
            return (temporaire = 0xC0 >> 0);
    }
    if (i == 1 && info_gater->argument[1] != NULL) {
        if (info_gater->argument[1][0] == '%')
            return (temporaire = 0x80 >> 2);
        else if (info_gater->argument[1][0] == 'r')
            return (temporaire = 0x40 >> 2);
        else
            return (temporaire = 0xC0 >> 2);
    }
    if (i == 2 && info_gater->argument[2] != NULL)
        return (wiew_the_arg2(info_gater, temporaire));
}

char put_the_byte(core_t *info_gater, int fd)
{
    char byte = 0x00;
    int i = 0;

    for (; info_gater->argument[i] != 0; i++)
        byte |= wiew_the_arg(info_gater, i);
    if (write(fd, &byte, sizeof(byte)) == -1)
        return (-1);
    return byte;
}

void put_the_int(int fd, char *le_int)
{
    int oui = my_getnbr(le_int);

    oui = conv_conv(oui);
    write(fd, &oui, sizeof(oui));
}

int put_the_int_but_autistic(int fd, char *le_int)
{
    short le_true_int;
    char *arg_de_rechange = malloc(sizeof(char) * sizeof(le_int));
    int v = 0;
    int i = 0;

    if (le_int[0] == '%') {
        for (i = 1; le_int[i] != '\0'; i++) {
            arg_de_rechange[v] = le_int[i];
            v++;
        }
        arg_de_rechange[v] = '\0';
        le_true_int = my_getnbr(arg_de_rechange);
    } else {
        le_true_int = my_getnbr(le_int);
        if (le_true_int > IDX_MOD)
            return -1;
    }
    le_true_int = conv_conv(le_true_int);
    write(fd, &le_true_int, sizeof(le_true_int));
    return (0);
}

int put_the_roar(int fd, char *le_int)
{
    int jej = 0;
    char *arg_de_rechange = malloc(sizeof(char) * sizeof(le_int));
    int i = 0;
    int v = 0;

    if (le_int[0] == 'r')
        for (i = 1; le_int[i] != '\0'; i++){
            arg_de_rechange[v] = le_int[i];
            v++;
        }
    jej = my_getnbr(arg_de_rechange);
    write(fd, &jej, sizeof(jej) - 3);
    return 0;
}