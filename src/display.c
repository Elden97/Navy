/*
** display.c for Navy in /home/groot/Documents/Navy/New_navy
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Mon Feb 13 11:32:05 2017 Groot
** Last update Sun Feb 19 18:32:40 2017 Groot
*/
#include "navy.h"

void	print_map(char (*map)[8])
{
  int   i;
  int   j;

  j = 0;
  my_printf("%s", DISPLAY_BOARD);
  while (j < 8)
    {
      i = 0;
      my_printf("%d|", j + 1);
      while (i < 8)
	{
	  if (i != 7)
	    my_printf("%c ", map[j][i]);
	  else
	    my_printf("%c", map[j][i]);
	  ++i;
	}
      my_printf("\n");
      ++j;
    }
  my_printf("\n");
}

void	print_both_maps(char my_map[8][8], char enemy[8][8])
{
  my_printf("my positions:\n");
  print_map(my_map);
  my_printf("\nenemy's positions:\n");
  print_map(enemy);
}

