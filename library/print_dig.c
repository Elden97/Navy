/*
** print_dig.c for print_dig in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Wed Nov  9 10:56:31 2016 Eythan Fellous
** Last update Sun Nov 20 00:28:52 2016 Eythan Fellous
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

#include <stdio.h>

void	my_put_nbr(int nb)
{
  int mod;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  mod = (nb % 10);
	  nb = (nb - mod) / 10;
	  my_put_nbr(nb);
	  my_putchar(48 + mod);
	}
      else
	my_putchar(48 + nb % 10);
    }
}

int	my_printdig(char *format, va_list ap)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (format[a] != '\0')
    {
      if (format[a] == '%' && format[a + 1] == 'd' || format[a + 1] == 'i')
	{
	  a = a + 2;
	  b = va_arg(ap, int);
	  my_put_nbr(b);
	  return (a);
	}
       a = a + 1;
    }
}
