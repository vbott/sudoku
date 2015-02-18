/*
** verif_case.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:27:04 2010 mickael cerisier
** Last update Sun Apr 25 18:27:04 2010 mickael cerisier
*/

#include "sudo.h"

int		verif_square(int x, int y, int nb, int **tab)
{
  int		i;
  int		e;
  int		mem;

  i = 0;
  while (i < 3)
    {
      e = 0;
      mem = y + i;
      while (e < 3)
	{
	  if (tab[mem][e + x] == nb)
	    return (0);
	  e++;
	}
      i++;
    }
  return (1);
}

int		verif_line_col(int x, int y, int nb, int **tab)
{
  int		i;

  i = 0;
  while (i < 9 && tab[i][x] != nb)
    i++;
  if (i != 9)
    return (0);
  i = 0;
  while (i < 9 && tab[y][i] != nb)
    i++;
  if (i != 9)
    return (0);
  return (verif_square(x / 3 * 3, y / 3 * 3, nb, tab));
}
