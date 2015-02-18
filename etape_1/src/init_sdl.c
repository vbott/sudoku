/*
** init_sdl.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:26:22 2010 vivien botton
** Last update Sun Apr 25 17:26:23 2010 vivien botton
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"
#include "my_sdl.h"

static void	remove_bin_in_path(char *str)
{
  int		i;

  i = my_strlen(str);
  while (i >= 0 && str[i] != '/')
    i--;
  i++;
  str[i] = '\0';
}

void		some_text(t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*text;
  SDL_Color	color;

  pos.y = 805;
  pos.x = 5;
  pos.h = 50;
  pos.w = 150;
  text = xttf_rendertext_blended(info->timer_font, "Moves :", color);
  xsdl_blitsurface(info->bg, &pos, info->screen, &pos);
  xsdl_blitsurface(text, NULL, info->screen, &pos);
  SDL_FreeSurface(text);
  info->lock = SDL_CreateMutex();
  info->timer_id = xsdl_addtimer(0, timer_func, info);
}

void		init_sdl(t_info *info, int tab[9][9], char *path)
{
  SDL_Rect	pos;
  char		*mem;

  remove_bin_in_path(path);
  pos.x = 0;
  pos.y = 0;
  info->color.r = 87;
  info->color.g = 7;
  info->color.b = 7;
  info->time = 0;
  xsdl_init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
  xttf_init();
  info->screen = xsdl_setvideomode(WINX, WINY, BPP, SDL_HWSURFACE);
  SDL_WM_SetCaption("Sudoku", NULL);
  mem = my_strcat(path, "img/sudo.jpg");
  info->bg = ximg_load(mem);
  free(mem);
  mem = my_strcat(path, "img/handmeds.ttf");
  info->police = xttf_openfont(mem, 80);
  info->timer_font = xttf_openfont(mem, 40);
  free(mem);
  xsdl_blitsurface(info->bg, NULL, info->screen, &pos);
  write_number(tab, info);
  some_text(info);
}
