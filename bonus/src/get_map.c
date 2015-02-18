/*
** get_map.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:26:54 2010 mickael cerisier
** Last update Sun Apr 25 18:26:54 2010 mickael cerisier
*/

#include <stdlib.h>
#include <unistd.h>
#include "sudo.h"

int	get_map(int **res)
{
  int	i;
  char	buffer[BUFF_SIZE];
  int	e;
  int	r;

  if ((r = read(0, buffer, BUFF_SIZE)) != BUFF_SIZE)
    return (0);
  i = 0;
  while (i < 9)
    {
      r = read(0, buffer, BUFF_SIZE);
      if (r != BUFF_SIZE)
	return (0);
      e = 0;
      while (e < 9)
	{
	  res[i][e] = buffer[e * 2 + 2] - '0';
	  e++;
	}
      i++;
    }
  if ((r = read(0, buffer, BUFF_SIZE)) != BUFF_SIZE)
    return (0);
  return (1);
}
