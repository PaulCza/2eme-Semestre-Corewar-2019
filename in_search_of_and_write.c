/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** may be temporary
*/

#include "my.h"
#include "op.h"

int write_the_copper(thewall_t *thewall)
{
    int copperfield = COREWAR_EXEC_MAGIC;
    int temporaire = 0;

    temporaire = (copperfield & 0xFF000000) >> 24;
    temporaire |= ((copperfield & 0x00FF0000) >> 8);
    temporaire |= (copperfield & 0x0000FF00) << 8;
    temporaire |= ((copperfield & 0x000000FF) << 24);
    copperfield = temporaire;
    if (write(thewall->fd, &copperfield, sizeof(copperfield)) == -1)
        return (1);
    return 0;
}

void in_search_of_the_name(char *command, char *name_to_put)
{
    int i = 0;
    int j = 0;

    for (i = 0; command[i] != '"' && command[i] != '\0'; i++);
    i++;
    name_to_put[j] = command[i];
    for (; command[i] != '"' && command[i] != '\0'; i++) {
        name_to_put[j] = command[i];
        j++;
    }
    name_to_put[j] = '\0';
}

void write_the_name(char *name, int fd)
{
    int size = 129;
    int j = 0;

    size = size - my_strlen(name);
    write(fd, name, my_strlen(name));
    while (j < size + 4){
        write(fd, "\0", 1);
        j++;
    }
}

void in_search_of_the_comment(thewall_t *thewall)
{
    int nbr_p = 0;
    int jej = 0;
    int kek = 0;

    for (jej = 0; thewall->info_write[jej] != '\0' && nbr_p < 3; jej++)
        if (thewall->info_write[jej] == '"')
            nbr_p++;
    jej--;
    if (thewall->info_write[jej] == '"') {
        jej++;
        for (; thewall->info_write[jej] != '"' && \
        thewall->info_write[jej] != '\0'; jej++) {
            thewall->coment[kek] = thewall->info_write[jej];
            kek++;
        }
    }
    thewall->coment[kek - 1] = '\0';
}

int write_the_comment(thewall_t *thewall)
{
    int i = -1;
    int taille;
    int jej = 0;

    in_search_of_the_comment(thewall);
    for (;thewall->coment[jej] != '\0'; jej++);
    write(thewall->fd, thewall->coment, sizeof(char) * jej);
    taille = 2052 - my_strlen(thewall->coment);
    while (i < taille){
        write(thewall->fd, "\0", 1);
        i++;
    }
    return 0;
}