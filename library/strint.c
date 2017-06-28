/*
** strint.c for strint in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Tue Nov  8 13:54:12 2016 Eythan Fellous
** Last update Sun Nov 20 00:29:05 2016 Eythan Fellous
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  int a;

  a = 0;
  if (str == NULL)
    return (1);
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
  return (0);
}

int	my_printstr(char *format, va_list ap)
{
  char	*str;
  int	i;

  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] == '%' && format[i + 1] == 's')
	{
	  i = i + 1;
	  str = va_arg(ap, char *);
	  if (my_putstr(str) == 1)
	    my_putstr("(null)");
 	  return (i);
	}
      i = i + 1;
    }
}

int	myprint_S(char *format, va_list ap, char *str)
{
  int	y;

  str = va_arg(ap, char *);
  y = 0;
  while (str[y] != '\0')
    {
      if (str[y] < 10)
	{
	  my_putstr("\\00");
	  my_putnbr_base(str[y], "01234567");
	}
      else if (str[y] < 32 && str[y] >= 10)
	{
	  my_putstr("\\0");
	  my_putnbr_base(str[y], "01234567");
	}
      else if (str[y] == 127)
	{
	  my_putchar('\\');
	  my_putnbr_base(str[y], "01234567");
	}
      else
	my_putchar(str[y]);
      y = y + 1;
    }
}
