/*
** maps.c for NAVY in /home/groot/Documents/Navy/New_navy
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Sun Feb 12 18:41:09 2017 Groot
** Last update Sun Feb 19 18:31:55 2017 Groot
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "navy.h"

static void	swap(char *buffer, int i)
{
  char		tmp;

  if (LETTER(buffer[i + 3]) && NUMBER(buffer[i + 2]))
    {
      tmp = buffer[i + 2];
      buffer[i + 2] = buffer[i + 3];
      buffer[i + 3] = tmp;
    }
}

static int	buffer_testing(char *buffer, int i, int *boats)
{
  if (NB_BOATS(buffer[i]))
    {
      *(boats) += buffer[i] - 48;
      swap(buffer, i);
      swap(buffer, i + 3);
      if ((LETTER(buffer[i + 2]) && NUMBER(buffer[i + 3])) &&
	  (LETTER(buffer[i + 5]) && NUMBER(buffer[i + 6])))
	{
	  if (NUMBER1 == NUMBER2 &&
	      ((ABS(LETTER1, LETTER2) + 1) == BOAT_NUM - '0'))
	    return (0);
	  if (LETTER1 == LETTER2 &&
	      ((ABS(NUMBER1, NUMBER2) + 1) == BOAT_NUM - '0'))
	    return (0);
	}
      return (84);
    }
  else
    return (84);
}

static int	verify_boats(char *map, char *buffer)
{
  int		fd;
  int		size;
  int		i;
  int		boats;

  i = 0;
  boats = 0;
  if ((fd = open(map, O_RDONLY)) < 0)
    return (84);
  if ((size = read(fd, buffer, 31)) < 0 || size < MAX_FILE)
    return (84);
  buffer[size] = '\0';
  while (i < 4)
    {
      if (buffer_testing(buffer, i * 8, &boats))
	return (84);
      ++i;
    }
  if (boats != ARMY)
    return (84);
  return (0);
}

void	empty_map(char (*enemy)[8])
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (j < 8)
    {
      i = 0;
      while (i < 8)
	{
	  enemy[j][i] = '.';
	  ++i;
	}
      ++j;
    }
}

int	create_my_map(char *map, char (*my_map)[8])
{
  char	buffer[32];

  if (verify_boats(map, buffer))
    return (84);
  place_boats(buffer, my_map);
  return (0);
}
