/*
** print_base.c for print_base in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Mon Nov 14 12:12:01 2016 Eythan Fellous
** Last update Sat Nov 19 19:22:01 2016 Eythan Fellous
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	 my_putnbr_base(unsigned int nb, char *base)
{
  int   l_base;
  unsigned int	tmp;

  if (nb != 0)
    {
      l_base = my_strlen(base);
      tmp = nb / l_base;
      my_putnbr_base(tmp, base);
      tmp = base[nb % l_base];
      my_putchar(tmp);
    }
}

int	my_printoc(char *format, va_list ap)
{
  int   a;

  a = 0;
  while (format[a] != '\0')
    {
      if (format[a] == '%' && format[a + 1] == 'o')
	{
	  a = a + 2;
	  my_putnbr_base(va_arg(ap, unsigned int), "01234567");
	  return (a);
	}
      a = a + 1;
    }
}


int	my_printex(char *format, va_list ap)
{
  int	y;

  y = 0;
  while (format[y] != '\0')
    {
      if (format[y] == '%' && format[y + 1] == 'X')
	{
	  y = y + 2;
	  my_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	  return (y);
	}
      y = y + 1;
    }
}

int	my_printexm(char *format, va_list ap)
{
  int   y;

  y = 0;
  while (format[y] != '\0')
    {
      if (format[y] == '%' && format[y + 1] == 'x')
	{
	  y = y + 2;
	  my_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	  return (y);
	}
      y = y + 1;
    }
}
