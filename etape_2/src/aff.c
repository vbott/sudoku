/*
** aff.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_2
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:08:38 2010 mickael cerisier
** Last update Sun Apr 25 12:08:38 2010 mickael cerisier
*/

#include <stdlib.h>
#include <unistd.h>

int		my_strlen(const char *s)
{
  int		i;

  if (s == NULL)
    return (0);
  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}

void		my_puterror(const char *str)
{
  if (str != NULL)
    write(2, str, my_strlen(str));
}

void		my_putstr(const char *str)
{
  if (str != NULL)
    {
      if (write(1, str, my_strlen(str)) == -1)
	my_puterror("Could not write.\n");
    }
}

void		my_putchar(const char c)
{
  if (write(1, &c, 1) == -1)
    my_puterror("Could not write.\n");
}
