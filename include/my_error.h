/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** everything for error-desu
*/

#ifndef _ERROR_H_
#define _ERROR_H_

#include "my.h"
#include "op.h"

typedef struct input {
    char *line;
    size_t len;
    struct input *next;
    struct input *preview;
} input_t;

typedef struct label {
    char *line;
    struct label *next;
    struct label *preview;
} label_t;

input_t *input_taker(FILE *adres);
int error_master(input_t *info);
input_t *input_rewinder(input_t *info);
char *name_converter(char *str, char *extend);
int my_strcmp(char const *s1, char const *s2);
char *str_fus(char *str, char *extend);
int name_finder(char *str);
int com_finder(char *str);
label_t *label_maker(void);
label_t *label_filler(label_t *l_abel, char *str);
label_t *label_rewinder(label_t *l_abel);
label_t *label_forwarder(label_t *l_abel);
int label_finder(char *str, label_t **l_abel);

#endif
