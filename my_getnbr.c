/*
** my_getnbr.c for getnbr in /home/eythan/Desktop/synthese/poub/PSU_2016_navy
** 
** Made by Eythan
** Login   <eythan.fellous@epitech.eu>
** 
** Started on  Wed Jun 28 18:01:22 2017 Eythan
** Last update Wed Jun 28 18:01:28 2017 Eythan
*/


#include "navy.h"

static int	my_power_rec(int nb, int p)
{
  long long int	pow;
  int		pow_integer;
  int		integer2;

  pow = 1;
  pow_integer = 0;
  integer2 = 2147483647;
  if (p == 0)
    return (1);
  if (p < 0)
    return (0);
  pow = my_power_rec(nb, (p - 1)) * nb;
  if ((pow <= integer2) && (pow >= (-integer2 - 1)))
    {
      pow_integer = pow;
      return (pow_integer);
    }
  else
    return (0);
}

static int	check_interv(char *str, int *i)
{
  if (str[*i] >= 48 && str[*i] < 58)
    return (1);
  else
    return (0);
}

static int	check(long long int *nb)
{
  int	integer_nb;

  integer_nb = *nb;
  if (*nb > 2147483647 || *nb < -2147483648)
    return (0);
  else
    return (integer_nb);
}

int		my_getnbr(char *str)
{
  long long int	nb;
  int		count_nbrs;
  int		i;

  i = 0;
  nb = 0;
  count_nbrs = 0;
  while (str[i] != '\0' && (check_interv(str, &i) == 0))
    i++;
  while (str[i] != '\0' && (check_interv(str, &i) == 1))
    {
      i++;
      count_nbrs++;
    }
  while ((i - (count_nbrs)) != i)
    {
      nb = nb + ((str[i - count_nbrs] - 48) *
		 my_power_rec(10, count_nbrs - 1));
      count_nbrs--;
    }
  return (check(&nb));
}
