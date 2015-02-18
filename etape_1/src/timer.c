/*
** timer.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:26:02 2010 vivien botton
** Last update Sun Apr 25 18:32:31 2010 mickael cerisier
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"
#include "my_sdl.h"

static void	get_time(int nb, char str[10])
{
  int		h;
  int		m;
  int		s;

  h = nb / 3600;
  m = (nb - h * 3600) / 60;
  s = nb % 60;
  str[0] = h / 10 + '0';
  str[1] = h % 10 + '0';
  str[2] = ':';
  str[3] = m / 10 + '0';
  str[4] = m % 10 + '0';
  str[5] = ':';
  str[6] = s / 10 + '0';
  str[7] = s % 10 + '0';
  str[8] = '\0';
}

void		aff_move(t_info *info)
{
  SDL_Rect	pos;
  SDL_Surface	*text;
  SDL_Color	color;
  char		str[11];

  pos.y = 805;
  pos.x = 130;
  pos.h = 50;
  pos.w = 150;
  color.r = 0;
  color.g = 0;
  color.b = 0;
  int_to_str(info->move, str);
  text = xttf_rendertext_blended(info->timer_font, str, color);
  xsdl_blitsurface(info->bg, &pos, info->screen, &pos);
  xsdl_blitsurface(text, NULL, info->screen, &pos);
  SDL_FreeSurface(text);
}

Uint32		timer_func(__attribute__ ((unused)) Uint32 interv, void *arg)
{
  t_info	*info;
  SDL_Rect	pos;
  SDL_Surface	*text;
  SDL_Color	color;
  char		str[10];

  info = (t_info*)arg;
  get_time(info->time, str);
  info->time++;
  color.r = 0;
  color.g = 0;
  color.b = 0;
  text = xttf_rendertext_blended(info->timer_font, str, color);
  pos.y = 805;
  pos.x = 655;
  pos.h = 50;
  pos.w = 150;
  xsdl_mutexp(info->lock);
  xsdl_blitsurface(info->bg, &pos, info->screen, &pos);
  xsdl_blitsurface(text, NULL, info->screen, &pos);
  SDL_FreeSurface(text);
  aff_move(info);
  xsdl_flip(info->screen);
  xsdl_mutexv(info->lock);
  return (1000);
}
