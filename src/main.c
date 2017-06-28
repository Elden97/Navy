/*
** main.c for Navy in /home/groot/Documents/Navy/New_navy
** 
** Made by Groot
** Login   <magali.denelle@epitech.eu>
** 
** Started on  Sun Feb 12 10:21:44 2017 Groot
** Last update Sun Feb 19 18:28:52 2017 Groot
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "navy.h"

t_game g_game = {'0', 0};

static void	catch_sig(int signum, siginfo_t *act, void *pt)
{
  if (signum == SIGUSR2)
    g_game.stock = '2';
  else
    g_game.stock = '1';
  g_game.pid = act->si_pid;
}

static int	init_sigaction(struct sigaction act)
{
  act.sa_sigaction = &catch_sig;
  act.sa_flags = SA_SIGINFO;
  if (sigemptyset(&(act.sa_mask)) < 0)
    return (-1);
  if (sigaction(SIGUSR1, &act, NULL) < 0)
    return (-1);
  if (sigaction(SIGUSR2, &act, NULL) < 0)
    return (-1);
  return (0);
}

static int	check_args(int nb_arg, char **av)
{
  if (nb_arg < 2 || nb_arg > 3)
    {
      write(2, HELPER, HELPER_N);
      return (84);
    }
  else if (nb_arg == 2)
    return (game_start_j1(av[1]));
  else
    return (game_start_j2(av[1], av[2]));
}

static void	help()
{
  write(1, "a", 1);
}

int			main(int ac, char **av)
{
  struct sigaction	act;
  int			status;

  if (ac == 2 && my_strcmp(av[1], "-h") == 0)
    {
      help();
      return (0);
    }
  if (init_sigaction(act))
    return (84);
  status = check_args(ac, av);
  return (status);
}
