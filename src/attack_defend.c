/*
** attack_defend.c for atta in /home/eythan/Desktop/synthese/poub/PSU_2016_navy
** 
** Made by Eythan
** Login   <eythan.fellous@epitech.eu>
** 
** Started on  Wed Jun 28 18:00:33 2017 Eythan
** Last update Wed Jun 28 18:00:35 2017 Eythan
*/


#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include "navy.h"

int	attack(char enemy[8][8])
{
  char *input;
  char	status;

  if (!(input = get_input()))
    return (84);
  encode(input[0] - 'A', input[1] - '1');
  if (kill(g_game.pid, SIGUSR1) == -1)
    return (84);
  status = receive();
  attack_2(enemy, status, input);
  if (kill(g_game.pid, SIGUSR1) == -1)
    return (84);
  return (0);
}

int	defend(char my_map[8][8])
{
  int	letter;
  int	number;

  write(1, "waiting for enemy's attack...\n", 30);
  if (decoder(&letter, &number))
    return (84);
  receive();
  if (NB_BOATS(my_map[letter][number]))
    {
      my_printf("%c%c: hit\n", number + 'A', letter + '0' + 1);
      my_map[letter][number] = 'x';
      send('1');
    }
  else if (my_map[letter][number] == 'x')
    {
      my_printf("%c%c: missed\n", number + 'A', letter + '0' + 1);
      send('1');
    }
  else
    {
      my_printf("%c%c: missed\n", number + 'A', letter + '0' + 1);
      my_map[letter][number] = 'o';
      send('0');
    }
  return (0);
}

void	attack_2(char enemy[8][8], char status, char *input)
{
  if (status == '2' && enemy[input[1] - '0' - 1][input[0] - 'A'] != 'x')
    {
      my_printf("%s: hit\n", input);
      enemy[input[1] - '0' - 1][input[0] - 'A'] = 'x';
    }
  else if (status == '2' && enemy[input[1] - '0' - 1][input[0] - 'A'] == 'x')
    {
      my_printf("%s: missed\n", input);
      enemy[input[1] - '0' - 1][input[0] - 'A'] = 'x';
    }
  else
    {
      my_printf("%s: missed\n", input);
      enemy[input[1] - '0' - 1][input[0] - 'A'] = 'o';
    }
}
