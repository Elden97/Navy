/*
** navy.h for Navy in /home/groot/Documents/Navy/New_navy
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Sun Feb 12 10:38:53 2017 Groot
** Last update Sun Feb 19 19:28:49 2017 Groot
*/

#ifndef NAVY_H
# define NAVY_H

# include <sys/types.h>
# include <unistd.h>

# define HELPER		"Please use ./navy -h\n"
# define HELPER_N	21
# define MAPS		"Please check your map\n"
# define MAPS_N		21
# define ERROR_INPUT	"wrong position\n"
# define ERROR_INPUT_N	15
# define ATTACK		"attack: "
# define ATTACK_N	8

# define MAX_FILE 31
# define ARMY 14
# define NB_BOATS(c) ((c >= '2') && (c <= '5') ? (1) : (0))
# define LETTER(c) ((c >= 'A') && (c <= 'H') ? (1) : (0))
# define NUMBER(c) ((c >= '1') && (c <= '8') ? (1) : (0))
# define ABS(a,b) (((a) - (b)) < 0 ? ((b) - (a)) : ((a) -(b)))
# define LETTER1 buffer[i + 2] - 'A'
# define LETTER2 buffer[i + 5] - 'A'
# define NUMBER1 buffer[i + 3] - '0' - 1
# define NUMBER2 buffer[i + 6] - '0' - 1
# define BOAT_NUM buffer[i]
# define DISPLAY_BOARD " |A B C D E F G H\n-+---------------\n"
# define ALPHA "ABCDEFGH"
# define NUM "0123456789"

typedef struct	s_game
{
  char		stock;
  pid_t		pid;
}		t_game;
extern t_game g_game;

int     my_printf(char *format, ...);
int	game_start_j1(char *map);
int	game_start_j2(char *pid, char *map);
int	my_strcmp(char *s1, char *s2);
int	my_strlen(char *str);
int	create_my_map(char *map, char (*my_map)[8]);
void    empty_map(char (*enemy)[8]);
void    place_boats(char *buffer, char (*my_map)[8]);
void	print_map(char (*map)[8]);
char    *get_next_line(const int fd);
int	my_getnbr(char *str);
void    print_both_maps(char my_map[8][8], char enemy[8][8]);
int     encode(int letter, int number);
int     decoder(int *letter, int *number);
int	co_p1();
int	co_p2(char *pid);
int     check_input(char *input);
char    *get_input();
int     send(char sending);
void	attack_2(char enemy[8][8], char status, char *input);
char    receive();
int     attack(char enemy[8][8]);
int     defend(char my_map[8][8]);

#endif /*!NAVY_H*/
