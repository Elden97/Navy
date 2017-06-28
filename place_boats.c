/*
** place_boats.c for Navy in /home/groot/Documents/Navy/New_navy
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Mon Feb 13 11:09:59 2017 Groot
** Last update Sun Feb 19 18:29:06 2017 Groot
*/

#include "navy.h"

static void	place_vert_boats(char *buffer, char (*my_map)[8], int i)
{
  int		k;

  k = NUMBER1;
  while (k <= NUMBER2)
    {
      my_map[k][LETTER1] = BOAT_NUM;
      ++k;
    }
}

void	place_boats(char *buffer, char (*my_map)[8])
{
  int   i;
  int   k;

  i = 0;
  while (i < 32)
    {
      if (LETTER1 == LETTER2)
	place_vert_boats(buffer, my_map, i);
      else
	{
	  k = LETTER1;
	  while (k <= LETTER2)
	    {
	      my_map[NUMBER1][k] = BOAT_NUM;
	      ++k;
	    }
	}
      i += 8;
    }
}
