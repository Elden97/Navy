/*
** input.c for NAVY in /home/groot/Documents/Navy/WIP
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Tue Feb 14 22:49:53 2017 Groot
** Last update Sun Feb 19 18:28:27 2017 Groot
*/

#include "navy.h"

int	check_input(char *input)
{
  char  tmp;

  if (my_strlen(input) > 2)
    return (84);
  if (LETTER(input[1]) && NUMBER(input[0]))
    {
      tmp = input[0];
      input[0] = input[1];
      input[1] = tmp;
    }
  if (!LETTER(input[0]) || !NUMBER(input[1]))
    return (84);
  return (0);
}

char	*get_input()
{
  char  *input;

  while (42)
    {
      write(1, ATTACK, ATTACK_N);
      input = get_next_line(0);
      if (!input)
	return (NULL);
      if (check_input(input))
	write(1, ERROR_INPUT, ERROR_INPUT_N);
      else
	break ;
    }
  return (input);
}
