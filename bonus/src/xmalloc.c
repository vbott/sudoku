/*
** xmalloc.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:27:28 2010 mickael cerisier
** Last update Sun Apr 25 18:28:53 2010 mickael cerisier
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudo.h"

void		*xmalloc(int size)
{
  void		*new;

  new = malloc(size);
  if (new == NULL)
    {
      my_puterror("Malloc fail.\n");
      exit(EXIT_FAILURE);
    }
  return (new);
}
