##
## Makefile for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
## 
## Made by mickael cerisier
## Login   <cerisi_m@epitech.net>
## 
## Started on  Sun Apr 25 12:08:07 2010 mickael cerisier
## Last update Sun Apr 25 17:20:31 2010 vivien botton
##

NAME	= sudoki-bi
SRCS	= src/main.c		\
	  src/handle_events.c	\
	  src/func_manual.c	\
	  src/aff_nbr.c		\
	  src/find_togo.c	\
	  src/get_map.c		\
	  src/verif_case.c	\
	  src/backtracking.c	\
	  src/timer.c		\
	  src/init_sdl.c	\
	  src/my_strcmp.c	\
	  src/int_to_str.c	\
	  src/aff.c		\
	  src/my_strcat.c	\
	  src/xsdl.c		\
	  src/xsdl_mutex.c	\
	  src/xinit.c

OBJS	= $(SRCS:.c=.o)

CC	= clang 

CFLAGS	= -pipe -O2 -Wall -Wextra -pedantic -ansi `sdl-config --cflags` -I include/

LDFLAGS = `sdl-config --libs` -lSDL -lSDL_image -lSDL_ttf

RM	= rm -f

$(NAME)	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

all	: $(NAME)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.c.o    :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
