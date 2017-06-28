/*
** get_next_line.c for get_next in /home/Elden/Desktop/tech1/CPE/CPE_2016_getnextline
** 
** Made by Eythan Fellous
** Login   <Elden@epitech.net>
** 
** Started on  Sun Jan  8 13:11:40 2017 Eythan Fellous
** Last update Mon Feb 13 14:23:24 2017 Groot
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char		my_char(const int fd)
{
  static char   buf[READ_SIZE];
  static char   *tmp;
  static int    len = 0;
  char          c;

  if (len == 0)
    {
      len = read(fd, buf, READ_SIZE);
      tmp = (char *)&buf;
      if (len == 0)
        return (0);
    }
  c = *tmp;
  tmp++;
  len--;
  return (c);
}

char	*my_malloc(char *p, int size)
{
  char	*tmp;
  int	a;

  tmp = p;
  if ((tmp = malloc(sizeof(*tmp) * (my_strlen(p) + size))) == NULL)
    return (NULL);
  a = 0;
  while (p[a])
    {
      tmp[a] = p[a];
      a++;
    }
  free(p);
  return (tmp);
}

char	*my_strnull(char *str)
{
  if (str == NULL)
    return (NULL);
}

char	*get_next_line(const int fd)
{
  char	a;
  char	*str;
  int	l;

  l = 0;
  if ((str = malloc(READ_SIZE + 1)) == NULL)
    return (NULL);
  my_strnull(str);
  a = my_char(fd);
  while (a != '\n' && a != '\0')
    {
      str[l] = a;
      a = my_char(fd);
      l++;
      if (l % (READ_SIZE + 1) == 0)
	str = my_malloc(str, l + READ_SIZE + 1);
    }
  str[l] = 0;
  if (a == 0 && str[0] == 0)
    return (0);
  return (str);
}
