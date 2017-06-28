/*
** trash.c for trasdh in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Mon Nov 14 14:35:07 2016 Eythan Fellous
** Last update Sat Nov 19 19:25:43 2016 Eythan Fellous
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int	my_printbin(char *format, va_list ap)
{
  int   p;

  p = 0;
  while (format[p] != '\0')
    {
      if (format[p] == '%' && format[p + 1] == 'b')
	{
	  p = p + 2;
	  my_putnbr_base(va_arg(ap, unsigned int), "01");
	  return (p);
	}
      p = p + 1;
    }
}

