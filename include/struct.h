/*
** EPITECH PROJECT, 2019
** list fonction
** File description:
** the_hunter
*/

#include <signal.h>

# define GAME g_game

typedef struct getnbr
{
    int j;
    int i;
    int b;
    int res;
    int pui;
} getnbr_t;

typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *list;

typedef struct init_fonction
{
    char **tab;
    int victory;
    int line;
    int nbr_line;
    int taille_pyra;
    int max_matches;
}init_t;

struct game_info
{
    pid_t me;
    pid_t enemy;
    char receive_x;
    char receive_y;
    char send_x;
    char send_y;
    int e;
    int ascii;
    int w8;
} g_game;

typedef struct minishell
{
    char *buffer;
    size_t bufsize;
    int e;
    int j;
    int nbr_virg;
    char *path;
    char **word_cut;
    char **new_word_cut;
    int b;
}ms_t;

typedef struct header_yes
{
    int copperfield;
    char name[256];
    int size;
    char comment[256];
} head_t;

typedef struct info_yes
{
    int fd;
    int lenght;
    char *name;
    char *info_write;
    char **info_cut;
    char *coment;
} thewall_t;

typedef struct core_f
{
    char *name;
    char **argument;
} core_t;

int player_1(init_t *init);
int player_2(init_t *init);
int is_empty(list li);
int list_lenght(list li);
void print_list(list li);
list del_front_list(list li);
list del_back_list(list li);
list clear_list(list li);
list push_front_list(list li, int x);
list push_back_list(list li, int x);
list new_list(void);
list sa_sb(list res);
list sc (list res, list res2);
void pa_pb (list *res, list *res2);
void ra_rb (list *res);
void rra_rrb (list *res);
int order (list rep);
void sorts(list *l_a, list *l_b);
void sorts_sec(list *l_b, list *l_a);
void ia (init_t *init);
int remove_pyre(init_t *init);
void fin_fils(int sig, siginfo_t *info);
void stop_fils(int sig, siginfo_t *info);
void miss_handler(int sig, siginfo_t *info);
void hit_handler(int sig, siginfo_t *info);
void doing_algo(char **map, int len_1, int len_2);
void crea_map(char **map, char **av);
void begin_algo(char **map);
void lunch_fonct(char **en, char **word_cut, char *thisEnv);
void other_f_2(char **en, char **word_cut, char *thisEnv, char *road);
void other_f(char **en, char **word_cut, char *thisEnv);
char *add_cat(char *word1, char *word2);
int exit_f(char **en, char **word_cut, char *thisEnv);
void other_f_direction(char **en, char **word_cut, char **word_origin);
void init_main(ms_t *begin);
int le_minishell(ms_t *begin, int ac, char **av, char **en);
void add_new_env_two(char **en, char **word_cut, char *thisEnv, \
int nbr_element);
int init_the_wall(thewall_t *thewall, char **av);
int create_the_file(char *name, thewall_t *thewall);
int	live_f(core_t *info_gater, int fd);
int	conv_conv(int var);
int put_the_int_but_autistic(int fd, char *le_int);
void put_the_int(int fd, char *le_int);
char put_the_byte(core_t *info_gater, int fd);
int put_the_int_but_autistic(int fd, char *le_int);
int put_the_roar(int fd, char *le_int);
int ld_f(core_t *info_gater, int fd);