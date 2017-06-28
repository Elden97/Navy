/*
** print_char.c for printc in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Wed Nov  9 13:57:33 2016 Eythan Fellous
** Last update Mon Nov 14 12:24:17 2016 Eythan Fellous
*/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	my_printchar(char *format, va_list ap)
{
  int	x;
  int	e;

  x = 0;
  while (format[x] != '\0')
    {
      if (format[x] == '%' && format[x + 1] == 'c')
	{
	  x = x + 2;
	  e = va_arg(ap, int);
	  my_putchar(e);
	  return (x);
	}
      x = x + 1;
    }
}
