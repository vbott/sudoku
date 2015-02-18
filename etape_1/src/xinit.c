/*
** xinit.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:25:51 2010 vivien botton
** Last update Sun Apr 25 17:25:53 2010 vivien botton
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"

SDL_Surface	*xsdl_setvideomode(int w, int h, int bpp, Uint32 flags)
{
  SDL_Surface	*screen;

  screen = SDL_SetVideoMode(w, h, bpp, flags);
  if (!screen)
    {
      my_perror("Setvideomode failure.\n");
      exit(EXIT_FAILURE);
    }
  return (screen);
}

int		xsdl_init(Uint32 flags)
{
  int		mem;

  mem = SDL_Init(flags);
  if (mem == -1)
    {
      my_perror("SDL_Init failure.\n");
      exit(EXIT_FAILURE);
    }
  return (mem);
}

int		xttf_init(void)
{
  int		mem;

  mem = TTF_Init();
  if (mem == -1)
    {
      my_perror("TTF_Init failure.\n");
      exit(EXIT_FAILURE);
    }
  return (mem);
}

SDL_TimerID	xsdl_addtimer(Uint32 interval, SDL_NewTimerCallback cb,
			      void* param)
{
  SDL_TimerID	mem;

  mem = SDL_AddTimer(interval, cb, param);
  if (!mem)
    my_perror("AddTimer failure.\n");
  return (mem);
}
