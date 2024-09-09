/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

int init_the_wall(thewall_t *thewall, char **av)
{
    struct stat size;
    int fd = open(av[1], O_RDONLY);

    stat(av[1], &size);
    thewall->info_write = malloc(sizeof(char) * size.st_size);
    thewall->name = malloc(sizeof(char) * 256);
    thewall->coment = malloc(sizeof(char) * 100);
    thewall->info_cut = malloc(sizeof(char *) * size.st_size);
    read(fd, thewall->info_write, size.st_size);
    thewall->info_write[size.st_size - 1] = '\0';
}