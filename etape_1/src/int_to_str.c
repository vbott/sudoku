/*
** int_to_str.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:24:44 2010 mickael cerisier
** Last update Sun Apr 25 18:24:45 2010 mickael cerisier
*/

int		calc_len_int(int nb)
{
  int		res;
  int		i;

  res = 0;
  i = 1;
  while (nb > 0)
    {
      res++;
      nb /= 10;
      i++;
    }
  return (res);
}

void		int_to_str(int nb, char *str)
{
  int		len;

  if (nb == 0)
    {
      str[0] = '0';
      str[1] = '\0';
      return ;
    }
  len = calc_len_int(nb);
  str[len] = '\0';
  len--;
  while (len >= 0)
    {
      str[len] = nb % 10 + '0';
      nb = nb / 10;
      len--;
    }
}
