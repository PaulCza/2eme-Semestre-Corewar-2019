/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** need to be fill-desu
*/

#include "my.h"
#include "op.h"

int live_f(core_t *info_gater, int fd)
{
    char hexa;
    int arg;
    char *arg_de_rechange = malloc(sizeof(char) * 256);
    int i = 1;
    int v = 0;

    hexa = 0x01;
    if (write(fd, &hexa, sizeof(hexa)) == -1)
        return 1;
    if (info_gater->argument[0][0] == '%') {
        for (i = 1; info_gater->argument[0][i] != '\0'; i++){
            arg_de_rechange[v] = info_gater->argument[0][i];
            v++;
        }
    }
    arg = my_getnbr(arg_de_rechange);
    arg = conv_conv(arg);
    if (write(fd, &arg, sizeof(arg)) == -1)
        return (1);
    return (0);
}

int ld_f(core_t *info_gater, int fd)
{
    char adress = 0X02;
    char byte;

    write(fd, &adress, sizeof(adress));
    byte = put_the_byte(info_gater, fd);

    char check = ((byte & 0xC0) >> 6);
    if (check == 0x02)
        put_the_int(fd, info_gater->argument[0]);
    if (check == 0x03)
        put_the_int_but_autistic(fd, info_gater->argument[0]);
    put_the_roar(fd, info_gater->argument[1]);
    return 0;
}
