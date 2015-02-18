/*
** find_togo.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:06:37 2010 mickael cerisier
** Last update Sun Apr 25 12:06:38 2010 mickael cerisier
*/

#include "sudo.h"

static void	calc_line(int tab[9][9], int pos[3])
{
  int		i;
  int		j;
  int		sum;

  i = 0;
  while (i < 9)
    {
      j = 0;
      sum = 9;
      while (j < 9)
	{
	  if (tab[i][j] != ZERO)
	    sum--;
	  j++;
	}
      if (sum && sum < pos[2])
	{
	  pos[2] = sum;
	  pos[1] = 1;
	  pos[0] = i;
	}
      i++;
    }
}

static void	calc_col(int tab[9][9], int pos[3])
{
  int		i;
  int		j;
  int		sum;

  i = 0;
  while (i < 9)
    {
      j = 0;
      sum = 9;
      while (j < 9)
	{
	  if (tab[j][i] != ZERO)
	    sum--;
	  j++;
	}
      if (sum && sum < pos[2])
	{
	  pos[2] = sum;
	  pos[1] = 2;
	  pos[0] = i;
	}
      i++;
    }
}

void		find_togo(int tab[9][9], int pos[2])
{
  int		i;
  int		cpy[3];

  cpy[0] = -1;
  cpy[1] = 0;
  cpy[2] = 10;
  calc_col(tab, cpy);
  calc_line(tab, cpy);
  i = 0;
  if (cpy[1] == 1)
    {
      while (tab[cpy[0]][i] != ZERO)
	i++;
      pos[0] = i;
      pos[1] = cpy[0];
    }
  else if (cpy[1] == 2)
    {
      while (tab[i][cpy[0]] != ZERO)
	i++;
      pos[0] = cpy[0];
      pos[1] = i;
    }
  else
    pos[0] = -1;
}
