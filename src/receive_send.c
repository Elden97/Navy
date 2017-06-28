/*
** receive_send.c for NAVY in /home/groot/Documents/NAVY/PSU_2016_navy
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Sun Feb 19 00:44:54 2017 Groot
** Last update Sun Feb 19 00:45:26 2017 Groot
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

char	receive()
{
  char	status;

  while (g_game.stock == '0')
    pause();
  status = g_game.stock;
  g_game.stock = '0';
  return (status);
}

int	send(char sending)
{
  if (sending == '0')
    {
      if (kill(g_game.pid, SIGUSR1) == -1)
	return (84);
    }
  else
    {
      if (kill(g_game.pid, SIGUSR2) == -1)
	return (84);
    }
  receive();
  return (0);
}
