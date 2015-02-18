/*
** backtracking.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:06:27 2010 mickael cerisier
** Last update Sun Apr 25 12:06:28 2010 mickael cerisier
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"
#include "my_sdl.h"

void		handle_pollevent(t_info *info)
{
  SDL_Event	event;

  if (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT ||
	  (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
	info->sdl = -1;
    }
}

int		backtracking(int tab[9][9], t_info *info)
{
  int		pos[2];
  int		nb;

  find_togo(tab, pos);
  if (info->sdl)
    handle_pollevent(info);
  if (pos[0] == -1 || info->sdl == -1)
    return (1);
  nb = 0;
  while (++nb < 10)
    if (verif_line_col(pos[0], pos[1], nb, tab))
      {
	info->move++;
	tab[pos[1]][pos[0]] = nb;
	if (info->sdl)
	  aff_nbr(pos[0], pos[1], nb + '0', info);
	if (backtracking(tab, info) == 1)
	  return (1);
	tab[pos[1]][pos[0]] = ZERO;
	if (info->sdl)
	  aff_nbr(pos[0], pos[1], ZERO, info);
      }
  return (-1);
}
