/*
** EPITECH PROJECT, 2019
** list fonction
** File description:
** the_hunter
*/

#include "my.h"

int is_empty(list list)
{
    if (list == NULL)
        return 1;
    return 0;
}

list new_list(void)
{
    return NULL;
}

int list_lenght(list list)
{
    int size = 0;

    if (is_empty(list) == 1)
        return size;
    while (list != NULL) {
        size++;
        list = list -> next;
    }
    return size;
}

void print_list(list list)
{
    if (is_empty(list) == 1)
        return;
    while (list != NULL) {
        my_printf("[%i]", list -> value);
        list = list -> next;
    }
}