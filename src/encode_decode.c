/*
** code.c for NAVY in /home/groot/Documents/Navy/WIP
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Tue Feb 14 22:46:35 2017 Groot
** Last update Sun Feb 19 18:32:13 2017 Groot
*/

#include <sys/types.h>
#include <signal.h>
#include "navy.h"

int	encode(int letter, int number)
{
  int   i;
  char  bin;

  bin = (letter << 3) | number;
  i = 0;
  while (i < 6)
    {
      if (bin & 1 << i)
	{
	  if (send('1'))
	    return (84);
	}
      else
	{
	  if (send('0'))
	    return (84);
	}
      ++i;
    }
  return (0);
}

static int	decode(char bin, int i)
{
  int   nbr;

  nbr = 0;
  if (bin & 1 << i)
    nbr += 1;
  if (bin & 1 << i + 1)
    nbr += 2;
  if (bin & 1 << i + 2)
    nbr += 4;
  return (nbr);
}

int	decoder(int *letter, int *number)
{
  int   i;
  char  bin;

  bin = 0;
  i = 0;
  while (i < 6)
    {
      if (receive() == '2')
	bin = bin | 1 << i;
      if (kill(g_game.pid, SIGUSR1) == -1)
	return (84);
      ++i;
    }
  *letter = decode(bin, 0);
  *number = decode(bin, 3);
  return (0);
}
