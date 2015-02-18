/*
** backtracking.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:26:25 2010 mickael cerisier
** Last update Sun Apr 25 18:26:25 2010 mickael cerisier
*/

#include <pthread.h>
#include "sudo.h"

int		backtracking(int **tab)
{
  int		pos[2];
  int		nb;

  find_togo(tab, pos);
  if (pos[0] == -1)
    pthread_exit(tab);
  nb = 1;
  while (nb < 10)
    {
      if (verif_line_col(pos[0], pos[1], nb, tab))
	{
	  tab[pos[1]][pos[0]] = nb;
	  if (backtracking(tab) == 1)
	    return (1);
	  tab[pos[1]][pos[0]] = ZERO;
	}
      nb++;
    }
  return (-1);
}
