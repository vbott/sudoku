/*
** main.c for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:07:01 2010 mickael cerisier
** Last update Sun Apr 25 12:07:02 2010 mickael cerisier
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"
#include "my_sdl.h"

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

static void	handle_params(int ac, char **av, t_info *info)
{
  int		i;

  i = 1;
  info->sdl = 0;
  info->manual = 0;
  while (i < ac)
    {
      if (!my_strcmp(av[i], "-sdl"))
	info->sdl = 1;
      else if (!my_strcmp(av[i], "-m"))
	{
	  info->sdl = 1;
	  info->manual = 1;
	}
      i++;
    }
}

void		quit(t_info *info, int tab[9][9])
{
  info->color.r = 255;
  info->color.g = 0;
  info->color.b = 255;
  aff_move(info);
  xsdl_flip(info->screen);
  if (!info->manual)
    SDL_RemoveTimer(info->timer_id);
  if (info->sdl != -1)
    handle_events(info, tab);
  SDL_DestroyMutex(info->lock);
  TTF_CloseFont(info->police);
  TTF_CloseFont(info->timer_font);
  TTF_Quit();
  SDL_FreeSurface(info->bg);
  SDL_Quit();
}

int		main(int ac, char **av)
{
  int		tab[9][9];
  t_info	info;

  handle_params(ac, av, &info);
  get_map(tab);
  if (info.sdl)
    {
      init_sdl(&info, tab, av[0]);
      info.move = 0;
    }
  if (!info.manual)
    {
      info.color.r = 0;
      info.color.g = 0;
      info.color.b = 0;
      backtracking(tab, &info);
      aff(tab);
    }
  if (info.sdl)
    quit(&info, tab);
  return (EXIT_SUCCESS);
}
