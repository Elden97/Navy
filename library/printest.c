/*
** printest.c for printest in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Wed Nov  9 09:25:25 2016 Eythan Fellous
** Last update Sun Nov 20 14:20:44 2016 Eythan Fellous
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_printf(char *format, ...)
{
  int	i;
  va_list ap;

  va_start(ap, format);
  i = 0;
  while (format[i] != '\0')
    {
      if (format[i] != '%')
	{
	  my_putchar(format[i]);
	  i = i - 1;
	}
      else if (format[i] == '%' && format[i + 1] == 's')
        my_printstr(format, ap);
      else if (format[i] == '%' && format[i + 1]  == 'd' ||
	       format[i + 1] == 'i')
	my_printdig(format, ap);
      else if (format[i] == '%' && format[i + 1] == 'c')
	my_printchar(format, ap);
      else
	my_printf2(format, ap, i);
      i = i + 2;
    }
  va_end(ap);
  return (0);
}

int	my_printf2(char *format, va_list ap, int i)
{
  char *str;
  char	b;

  if (format[i] == '%' && format[i + 1] == 'o')
    my_printoc(format, ap);
  else if (format[i] == '%' && format[i + 1] == 'X')
    my_printex(format, ap);
  else if (format[i] == '%' && format[i + 1] == 'x')
    my_printexm(format, ap);
  else if (format[i] == '%' && format[i + 1] == 'b')
    my_printbin(format, ap);
  else if (format[i] == '%' && format[i + 1] == '%')
    my_putchar('%');
  else if (format[i] == '%' && format[i + 1] == 'S')
    myprint_S(format, ap, str);
}
