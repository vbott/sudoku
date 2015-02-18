##
## Makefile for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
## 
## Made by mickael cerisier
## Login   <cerisi_m@epitech.net>
## 
## Started on  Sun Apr 25 18:28:06 2010 mickael cerisier
## Last update Sun Apr 25 18:28:09 2010 mickael cerisier
##

NAME	= sudoki-bi
SRCS	= src/main.c		\
	  src/find_togo.c	\
	  src/get_map.c		\
	  src/verif_case.c	\
	  src/backtracking.c	\
	  src/aff.c		\
	  src/xmalloc.c

OBJS	= $(SRCS:.c=.o)

CC	= clang 

CFLAGS	= -pipe -O2 -Wall -Wextra -pedantic -ansi -I include/

LDFLAGS = -lpthread

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
