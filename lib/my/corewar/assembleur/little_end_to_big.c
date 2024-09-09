/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** little_end_to_big
*/

#include "my.h"
#include "op.h"

int conv_conv(int var)
{
    int temporaire = 0;

    temporaire = (var & 0xFF000000) >> 24;
    temporaire |= ((var & 0x00FF0000) >> 8);
    temporaire |= (var & 0x0000FF00) << 8;
    temporaire |= ((var & 0x000000FF) << 24);
    return (temporaire);
}

char wiew_the_arg2(core_t *info_gater, char temporaire)
{
    if (info_gater->argument[2][0] == '%')
        return (temporaire = 0x80 >> 4);
    else if (info_gater->argument[2][0] == 'r')
        return (temporaire = 0x40 >> 4);
    else
        return (temporaire = 0xC0 >> 4);
}
