/*
** func_manual.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:26:40 2010 vivien botton
** Last update Sun Apr 25 17:26:41 2010 vivien botton
*/

#include "sudo.h"

int		is_finished(int tab[9][9])
{
  int		i;
  int		j;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  if (tab[i][j] == ZERO)
	    return (0);
 	  j++;
	}
      i++;
    }
  aff(tab);
  return (1);
}

void		tab_cpy(int src[9][9], int dest[9][9])
{
  int		i;
  int		j;

  i = 0;
  while (i < 9)
    {
      j = 0;
      while (j < 9)
	{
	  dest[i][j] = src[i][j];
 	  j++;
	}
      i++;
    }
}
