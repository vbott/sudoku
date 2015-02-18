/*
** xsdl_mutex.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:25:30 2010 vivien botton
** Last update Sun Apr 25 17:25:31 2010 vivien botton
*/

#include <SDL/SDL.h>
#include "sudo.h"

int		xsdl_mutexp(SDL_mutex *mutex)
{
  int		mem;

  mem = SDL_mutexP(mutex);
  if (mem == -1)
    my_perror("MutexP failure.\n");
  return (mem);
}

int		xsdl_mutexv(SDL_mutex *mutex)
{
  int		mem;

  mem = SDL_mutexV(mutex);
  if (mem == -1)
    my_perror("MutexV failure.\n");
  return (mem);
}
