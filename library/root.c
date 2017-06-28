/*
** my_putchar.c for putchar in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Wed Nov  9 15:04:49 2016 Eythan Fellous
** Last update Tue Jan 31 12:20:32 2017 Eythan Fellous
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	my_strlen(char *str)
{
  int	len;

  len = 0;
  if (str != NULL)
    {
      while (str[len] != '\0')
	len = len + 1;
    }
  return (len);
}
