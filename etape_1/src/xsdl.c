/*
** xsdl.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:25:41 2010 vivien botton
** Last update Sun Apr 25 17:25:44 2010 vivien botton
*/

#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"

SDL_Surface	*ximg_load(char *path)
{
  SDL_Surface	*img;

  img = IMG_Load(path);
  if (!img)
    {
      my_perror("Image load failure.\n");
      exit(EXIT_FAILURE);
    }
  return (img);
}

TTF_Font	*xttf_openfont(char *path, int size)
{
  TTF_Font	*font;

  font = TTF_OpenFont(path, size);
  if (!font)
    {
      my_perror("Font load failure.\n");
      exit(EXIT_FAILURE);
    }
  return (font);
}

int		xsdl_blitsurface(SDL_Surface *src, SDL_Rect *srcrect,
				 SDL_Surface *dst, SDL_Rect *dstrect)
{
  int		mem;

  mem = SDL_BlitSurface(src, srcrect, dst, dstrect);
  if (mem == -1)
    my_perror("Blitsurface failure.\n");
  return (mem);
}

SDL_Surface	*xttf_rendertext_blended(TTF_Font *font, const char *text,
					 SDL_Color fg)
{
  SDL_Surface	*ttf;

  ttf = TTF_RenderText_Blended(font, text, fg);
  if (!ttf)
    my_perror("ttf_rendertext_blended failure.\n");
  return (ttf);
}

int		xsdl_flip(SDL_Surface *screen)
{
  int		mem;

  mem = SDL_Flip(screen);
  if (mem == -1)
    my_perror("SDL_Flip failure.\n");
  return (mem);
}
