/*
** main.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_2
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:09:04 2010 mickael cerisier
** Last update Sun Apr 25 12:09:04 2010 mickael cerisier
*/

#include <stdlib.h>
#include "sudo.h"

void		aff(int tab[9][9])
{
  int		i;
  int		e;

  i = 0;
  my_putstr("|------------------|\n");
  while (i < 9)
    {
      e = 0;
      my_putchar('|');
      while (e < 9)
	{
	  my_putchar(' ');
	  my_putchar(tab[i][e] + '0');
	  e++;
	}
      my_putstr("|\n");
      i++;
    }
  my_putstr("|------------------|\n");
}

int		main(void)
{
  int		i;
  int		tab[9][9];

  i = 0;
  while (1)
    {
      get_map(tab);
      backtracking(tab);
      if (i != 0)
	my_putstr("####################\n");
      aff(tab);
      i++;
    }
  return (EXIT_SUCCESS);
}
