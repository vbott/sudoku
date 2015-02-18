/*
** my_strcat.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:26:13 2010 vivien botton
** Last update Sun Apr 25 17:26:14 2010 vivien botton
*/

#include <stdlib.h>
#include "sudo.h"

char		*my_strcat(char *s1, char *s2)
{
  int		i;
  int		e;
  char		*str;

  str = malloc((my_strlen(s1) + my_strlen(s2) + 1) * sizeof(*str));
  if (!str)
    {
      my_perror("Malloc failure.\n");
      exit(EXIT_FAILURE);
    }
  i = 0;
  while (s1[i] != '\0')
    {
      str[i] = s1[i];
      i++;
    }
  e = 0;
  while (s2[e] != '\0')
    str[i++] = s2[e++];
  str[i] = '\0';
  return (str);
}
