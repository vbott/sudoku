/*
** aff_nbr.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:26:49 2010 vivien botton
** Last update Sun Apr 25 17:26:50 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"
#include "my_sdl.h"

void		 clean_nbr(int x, int y, t_info *info)
{
  SDL_Rect	pos;

  pos.x = 10 + x * SIZE_BLOCK;
  pos.y = y * SIZE_BLOCK;
  pos.h = 80;
  pos.w = 80;
  xsdl_mutexp(info->lock);
  xsdl_blitsurface(info->bg, &pos, info->screen, &pos);
  xsdl_flip(info->screen);
  xsdl_mutexv(info->lock);
}

void		aff_nbr(int x, int y, char nb, t_info *info)
{
  char		c[2];
  SDL_Rect	pos;
  SDL_Surface	*text;

  pos.x = 10 + x * SIZE_BLOCK;
  pos.y = 5 + y * SIZE_BLOCK;
  pos.h = 80;
  pos.w = 80;
  xsdl_mutexp(info->lock);
  xsdl_blitsurface(info->bg, &pos, info->screen, &pos);
  if (nb != ZERO)
    {
      c[0] = nb;
      c[1] = '\0';
      pos.x = 22 + x * SIZE_BLOCK;
      pos.y = 5 + y * SIZE_BLOCK;
      if ((text = xttf_rendertext_blended(info->police, c, info->color)))
	{
	  xsdl_blitsurface(text, NULL, info->screen, &pos);
	  SDL_FreeSurface(text);
	}
    }
  xsdl_flip(info->screen);
  xsdl_mutexv(info->lock);
}

static void	write_number_2(char *c, SDL_Rect *pos, t_info *info)
{
  SDL_Surface	*text;

  if ((text = xttf_rendertext_blended(info->police, c, info->color)))
    {
      xsdl_blitsurface(text, NULL, info->screen, pos);
      SDL_FreeSurface(text);
    }
}

void		write_number(int tab[9][9], t_info *info)
{
  int		i;
  int		e;
  char		c[2];
  SDL_Rect	pos;

  i = 0;
  c[1] = '\0';
  while (i < 9)
    {
      e = 0;
      while (e < 9)
	{
	  if (tab[i][e] != ZERO)
	    {
	      c[0] = tab[i][e] + '0';
	      pos.x = 22 + e * SIZE_BLOCK;
	      pos.y = 5 + i * SIZE_BLOCK;
	      write_number_2(c, &pos, info);
	    }
	  e++;
	}
      i++;
    }
  xsdl_flip(info->screen);
}
