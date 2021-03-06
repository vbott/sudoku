/*
** main.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:27:38 2010 mickael cerisier
** Last update Sun Apr 25 18:27:38 2010 mickael cerisier
*/

#include <stdlib.h>
#include <pthread.h>
#include "sudo.h"

void		aff(int **tab)
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
      free(tab[i]);
      my_putstr("|\n");
      i++;
    }
  free(tab);
  my_putstr("|------------------|\n");
}

int		**new_tab(void)
{
  int		**res;
  int		i;

  res = xmalloc(sizeof(*res) * 9);
  i = 0;
  while (i < 9)
    {
      res[i] = xmalloc(sizeof(*res) * 9);
      i++;
    }
  return (res);
}

void		free_tab(int **tab)
{
  int		i;

  i = 0;
  while (i < 9)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void		start_thread(int *cont, int previous)
{
  void		*ret;
  pthread_t	thread[8];
  int		i;
  int		j;

  i = 0;
  ret = new_tab();
  while (i < 8 && get_map((int**)ret))
    {
      pthread_create(&(thread[i++]), NULL, (void *(*)(void*))backtracking, ret);
      ret = new_tab();
    }
  if (i < 8)
    {
      *cont = 0;
      free_tab((int**)ret);
    }
  j = 0;
  while (j < i)
    {
      pthread_join(thread[j++], &ret);
      if (previous || (j != 1))
	my_putstr("####################\n");
      aff((int**)ret);
    }
}

int		main(void)
{
  int		cont;
  int		previous;

  cont = 1;
  previous = 0;
  while (cont)
    {
      start_thread(&cont, previous);
      previous = 1;
    }
  return (EXIT_SUCCESS);
}
