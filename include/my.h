/*
** EPITECH PROJECT, 2019
** list fonction
** File description:
** the_hunter
*/

#ifndef _MY_H_
#define _MY_H_

#include <sys/types.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/dir.h>
#include <struct.h>
#include<sys/wait.h>

int same_char(char *str1, char *str2);
char my_transformnbr(int res);
int my_strlen(char *str);
int is_a_nbr(char j);
int my_getnbr(char const *str);
void *my_revstr(char *e);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_putstr (char const *str);
char *my_strcpy(char *dest, char const *src);
void hexa_maj(char *res, int v, int  x);
void hexa(char *res, int v, int  x);
char *my_to_binary(int v);
char *my_convhexa(int a);
char *my_convhexa_maj(int a);
void parcour(char nm, va_list a);
int my_putstr_detect (char const *str);
void number_case(char nm, va_list a);
void parcour_with_number(char nm, va_list a, char *nv);
char *my_conv_oct(int v);
int my_printf(char *s, ...);
void three(char nm, va_list a);
void four(char nm, va_list a);
void print_pyra(char **av, int v);
char **creat_pyramide (int ac);
void print_pyra(char **av, int v);
int put_nbr_math(void);
int victory_t(char **av, int ac);
int error_gestion(int ac, char **av);
char **str_to_word(char *str);
int count_space(char *str);
char *update_word(char *thisEnv);
//new
int write_the_copper(thewall_t *thewall);
void in_search_of_the_name(char *command, char *name_to_put);
void write_the_name(char *name, int fd);
void in_search_of_the_comment(thewall_t *thewall);
int write_the_comment(thewall_t *thewall);
int error(char *name);

#endif