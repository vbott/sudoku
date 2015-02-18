/*
** backtracking.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_2
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:08:45 2010 mickael cerisier
** Last update Sun Apr 25 12:08:45 2010 mickael cerisier
*/

#include "sudo.h"

int		backtracking(int tab[9][9])
{
  int		pos[2];
  int		nb;

  find_togo(tab, pos);
  if (pos[0] == -1)
    return (1);
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
