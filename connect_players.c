/*
** connect_players.c for co in /home/eythan/Desktop/synthese/poub/PSU_2016_navy
** 
** Made by Eythan
** Login   <eythan.fellous@epitech.eu>
** 
** Started on  Wed Jun 28 18:00:48 2017 Eythan
** Last update Wed Jun 28 18:00:49 2017 Eythan
*/


#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

int	co_p1()
{
  my_printf("my pid is : %d\n", getpid());
  my_printf("waiting for enemy connexion...\n");
  receive();
  if (kill(g_game.pid, SIGUSR1) == -1)
    return (84);
  my_printf("enemy connected\n\n");
  receive();
  return (0);
}

int	co_p2(char *pid)
{
  my_printf("my pid is : %d\n", getpid());
  g_game.pid = my_getnbr(pid);
  if (kill(g_game.pid, SIGUSR1) == -1)
    return (84);
  receive();
  my_printf("successfully connected\n\n");
  if (kill(g_game.pid, SIGUSR1) == -1)
    return (84);
  return (0);
}
