/*
** tools.c for tools in /home/Elden/Desktop/tech1/PSU/PSU_2016_navy
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Mon Jan 30 15:13:20 2017 Eythan Fellous
** Last update Sun Feb 19 00:47:59 2017 Groot
*/

#include "navy.h"
#include <stdlib.h>
#include <unistd.h>

int	my_strcmp(char *s1, char *s2)
{
  int	a;

  a = 0;
  while ((s1[a] == s2[a]) && (s1[a] != '\0') && (s2 != '\0'))
    {
      a = a + 1;
    }
  return (s1[a] - s2[a]);
}
