/*
** game_start.c for game in /home/eythan/Desktop/synthese/poub/PSU_2016_navy
** 
** Made by Eythan
** Login   <eythan.fellous@epitech.eu>
** 
** Started on  Wed Jun 28 18:01:00 2017 Eythan
** Last update Wed Jun 28 18:01:01 2017 Eythan
*/


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

int	create_maps(char *map, char my_map[8][8],
		    char enemy[8][8])
{
  empty_map(my_map);
  if (create_my_map(map, my_map))
    {
      write(2, MAPS, MAPS_N);
      return (84);
    }
  empty_map(enemy);
  return (0);
}

int	defeat_victory(char map[8][8])
{
  int	i;
  int	j;
  int	boats_hit;

  j = 0;
  boats_hit = 0;
  while (j < 8)
    {
      i = 0;
      while (i < 8)
	{
	  if (map[j][i] == 'x')
	    boats_hit += 1;
	  ++i;
	}
      ++j;
    }
  if (boats_hit == ARMY)
    return (0);
  else
    return (1);
}

int	defeat(char my_map[8][8], char enemy[8][8])
{
  if (!defeat_victory(my_map))
    {
      print_both_maps(my_map, enemy);
      my_printf("Enemy won\n");
      return (1);
    }
  if (!defeat_victory(enemy))
    {
      print_both_maps(my_map, enemy);
      my_printf("I won\n");
      return (0);
    }
  else
    return (2);
}

int	game_start_j1(char *map)
{
  char	my_map[8][8];
  char	enemy[8][8];
  int	status;

  if (create_maps(map, my_map, enemy))
    return (84);
  if (co_p1())
    return (84);
  print_both_maps(my_map, enemy);
  while (42)
    {
      attack(enemy);
      write(1, "\n", 1);
      status = defeat(my_map, enemy);
      if (status != 2)
	return (status);
      defend(my_map);
      write(1, "\n", 1);
      print_both_maps(my_map, enemy);
    }
}

int	game_start_j2(char *pid, char *map)
{
  char	my_map[8][8];
  char	enemy[8][8];
  int	status;

  if (create_maps(map, my_map, enemy))
    return (84);
  if (co_p2(pid))
    return (84);
  print_both_maps(my_map, enemy);
  while (42)
    {
      defend(my_map);
      write(1, "\n", 1);
      status = defeat(my_map, enemy);
      if (status != 2)
	return (status);
      attack(enemy);
      write(1, "\n", 1);
      print_both_maps(my_map, enemy);
    }
}
