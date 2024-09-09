/*
** EPITECH PROJECT, 2019
** list fonction
** File description:
** the_hunter
*/

#include "my.h"

list push_back_list(list li, int x)
{
    list copy;
    list trash;

    copy = malloc(sizeof(*copy));
    copy -> value = x;
    copy -> next = NULL;
    if (is_empty(li))
        return copy;
    trash = li;
    while (trash -> next != NULL)
        trash = trash -> next;
    trash -> next = copy;
    return li;
}

list push_front_list(list li, int x)
{
    list copy;

    copy = malloc (sizeof(*copy));

    copy -> value = x;
    if (is_empty(li) == 1)
        copy -> next = NULL;
    else
        copy -> next = li;
    return copy;
}

list del_back_list(list li)
{
    list trash = li;
    list before = li;

    if (is_empty(li))
        return new_list();
    if (li -> next == NULL)
        return new_list();
    while (trash -> next != NULL){
        before = trash;
        trash = trash -> next;
    }
    before -> next = NULL;
    trash = NULL;
    return li;
}

list del_front_list(list li)
{
    list copy;

    copy = malloc(sizeof*(copy));

    if (is_empty(li) == 1)
        return li;
    copy = li -> next;
    free (li);
    return copy;
}

list clear_list(list li)
{
    if (is_empty(li))
        return new_list();
    while (li != NULL){
        li = del_front_list(li);
    }
    return li;
}