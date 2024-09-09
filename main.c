/*
** EPITECH PROJECT, 2019
** Minishell.c
** File description:
** réussis
*/

#include "my.h"
#include "op.h"

void create_the_double_cut_tab(thewall_t *thewall)
{
    int len1 = 0;
    int len2 = 0;
    int len3 = 0;
    int space = 0;
    int vir = 0;

    thewall->info_cut[len2] = malloc(sizeof(char) * \
    my_strlen(thewall->info_write));
    for (;thewall->info_write[len1] != '\0'; len1++) {
        if (vir > 3) {
            if (thewall->info_write[len1] == ' ' && space == 0 || \
            thewall->info_write[len1] == '\t' && space == 0) {
                len2++;
                len3 = 0;
                thewall->info_cut[len2] = malloc(sizeof(char) * \
                my_strlen(thewall->info_write));
                space = 1;
            }
            if (thewall->info_write[len1] != ' ' && \
            thewall->info_write[len1] != '\t') {
                if (thewall->info_write[len1] == '\n' || \
                thewall->info_write[len1] == ',')
                    thewall->info_cut[len2][len3] = '\0';
                else
                    thewall->info_cut[len2][len3] = thewall->info_write[len1];
                len3++;
                space = 0;
            }
        } else
            if (thewall->info_write[len1] == '"')
                vir++;
    }
    thewall->info_cut[len2 + 1] = 0;
}

int main(int ac, char **av)
{
    thewall_t thewall;
    int temporaire = 0;

    if (ac != 2){
        my_printf("Wrong argument\n");
        return 84;
    }
    if (error(av[1]) == 84)
        return 84;
    init_the_wall(&thewall, av);
    thewall.fd = create_the_file(av[1], &thewall);
    in_search_of_the_name(thewall.info_write, thewall.name);
    write_the_copper(&thewall);
    write_the_name(thewall.name, thewall.fd);
    create_the_double_cut_tab(&thewall);
    temporaire = conv_conv(1);
    write(thewall.fd, &temporaire, sizeof(temporaire) - 3);
    write_the_comment(&thewall);
    return 0;
}