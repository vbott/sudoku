/*
** my_strcmp.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:07:11 2010 mickael cerisier
** Last update Sun Apr 25 12:07:11 2010 mickael cerisier
*/

#include <stdlib.h>

int		my_strcmp(const char *s1, const char *s2)
{
  int		cpt;

  if (s1 == NULL || s2 == NULL)
    return ((s1 == s2) ? 0 : -1);
  cpt = 0;
  while (s1[cpt] != '\0' && s2[cpt] != '\0' && s1[cpt] == s2[cpt])
    cpt++;
  return (s1[cpt] - s2[cpt]);
}
