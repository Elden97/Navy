/*
** my.h for my in /home/Elden/Desktop/tech1/PSU_2016_my_printf
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Wed Nov  9 16:23:39 2016 Eythan Fellous
** Last update Mon Jan 30 14:48:55 2017 Eythan Fellous
*/

#ifndef MY_H_
# define MY_H_

int	my_printf(char *format, ...);
int	my_putchar(char c);
int	my_printstr(char *format, va_list ap);
int	my_printdig(char *format, va_list ap);
int	my_printchar(char *format, va_list ap);
int	my_putnbr_base(unsigned int nb, char *base);
int	my_printoc(char *format, va_list ap);
int	my_printex(char *format, va_list ap);
int	my_strlen(char *str);
int	my_printexm(char *format, va_list ap);
int	my_printbin(char *format, va_list ap);
int	my_putstr(char *str);
int	my_printf2(char *format, va_list ap, int i);
int	myprint_S(char *format, va_list ap, char *str);

#endif /* !MY_H_ */

