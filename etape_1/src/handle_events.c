/*
** handle_events.c for sudoki-bi in /u/all/botton_v/cu/projects/rushmv/etape_1/src
** 
** Made by vivien botton
** Login   <botton_v@epitech.net>
** 
** Started on  Sun Apr 25 17:26:32 2010 vivien botton
** Last update Sun Apr 25 17:28:31 2010 vivien botton
*/

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "sudo.h"
#include "my_sdl.h"

static void	put_in_tab(t_event *evt, t_info *info, int tab[9][9], int *mem)
{
  *mem = 0;
  if (evt->lock == 1 && evt->nb)
    {
      if (verif_line_col(evt->pos.x, evt->pos.y, evt->nb - '0', tab)
	  || evt->nb - '0' == tab[evt->pos.y][evt->pos.x])
	{
	  tab[evt->pos.y][evt->pos.x] = evt->nb - '0';
	  if (is_finished(tab))
	    {
	      SDL_RemoveTimer(info->timer_id);
	      evt->lock = 2;
	    }
	}
      else
	{
	  info->color.b = 0;
	  tab[evt->pos.y][evt->pos.x] = ZERO;
	  aff_nbr(evt->pos.x, evt->pos.y, evt->nb, info);
	  info->color.b = 255;
	  *mem = 1;
	}
      info->move++;
      evt->nb = 0;
    }
}

static void	change_aff(t_event *evt, t_info *info,
			   int tab[9][9], int co[3])
{
  if (evt->tab[evt->pos.y][evt->pos.x] == ZERO)
    {
      if (co[0] != -1 && !co[2] && tab[co[1]][co[0]] == ZERO)
	clean_nbr(co[0], co[1], info);
      else if (co[0] != -1 && !co[2] && evt->tab[co[1]][co[0]] == ZERO)
	{
	  info->color.r = 0;
	  info->color.b = 0;
	  aff_nbr(co[0], co[1], tab[co[1]][co[0]] + '0', info);
	  info->color.r = 255;
	  info->color.b = 255;
	}
      if (tab[evt->pos.y][evt->pos.x] == ZERO)
	aff_nbr(evt->pos.x, evt->pos.y, '?', info);
      else if (evt->tab[evt->pos.y][evt->pos.x] == ZERO)
	aff_nbr(evt->pos.x, evt->pos.y,
		tab[evt->pos.y][evt->pos.x] + '0', info);
    }
  else
    {
      evt->pos.x = co[0];
      evt->pos.y = co[1];
    }
}

static void	handle_mouse(t_event *evt, t_info *info,
			     int tab[9][9], SDL_Event *event)
{
  int		co[3];

  put_in_tab(evt, info, tab, &(co[2]));
  if (evt->lock != 2)
    evt->lock = 1;
  else
    {
      aff_move(info);
      xsdl_flip(info->screen);
    }
  co[0] = evt->pos.x;
  co[1] = evt->pos.y;
  evt->pos.x = event->button.x / SIZE_BLOCK;
  evt->pos.y = event->button.y / SIZE_BLOCK;
  change_aff(evt, info, tab, co);
}

static void	handle_key(t_event *evt, t_info *info,
			   int tab[9][9], SDL_Event *event)
{
  if (event->key.keysym.sym >= '1' && event->key.keysym.sym <= '9')
    {
      evt->nb = event->key.keysym.sym;
      aff_nbr(evt->pos.x, evt->pos.y, evt->nb, info);
    }
  else if (event->key.keysym.sym >= 257 && event->key.keysym.sym <= 265)
    {
      evt->nb = event->key.keysym.sym - 208;
      aff_nbr(evt->pos.x, evt->pos.y, evt->nb, info);
    }
  else if (event->key.keysym.sym == ' ' || event->key.keysym.sym == 127)
    {
      evt->nb = 0;
      tab[evt->pos.y][evt->pos.x] = ZERO;
      aff_nbr(evt->pos.x, evt->pos.y, '?', info);
    }
}

void		handle_events(t_info *info, int tab[9][9])
{
  int		cont;
  SDL_Event     event;
  t_event	evt;

  cont = 1;
  evt.nb = 0;
  evt.lock = 0;
  tab_cpy(tab, evt.tab);
  evt.pos.x = -1;
  evt.pos.y = -1;
  while (cont)
    if (SDL_WaitEvent(&event))
      {
        if (event.type == SDL_QUIT ||
	    (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE))
          cont = 0;
	else if (info->manual && event.type == SDL_KEYDOWN && evt.lock != 2)
	  handle_key(&evt, info, tab, &event);
	else if (info->manual && event.type == SDL_MOUSEBUTTONUP
		  && event.button.button == SDL_BUTTON_LEFT && evt.lock != 2)
	   handle_mouse(&evt, info, tab, &event);
      }
}
