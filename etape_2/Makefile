##
## Makefile for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_2
## 
## Made by mickael cerisier
## Login   <cerisi_m@epitech.net>
## 
## Started on  Sun Apr 25 12:09:20 2010 mickael cerisier
## Last update Sun Apr 25 17:20:51 2010 vivien botton
##

NAME	= ../bin/sudoki-bi

SRCS	= src/main.c		\
	  src/find_togo.c	\
	  src/get_map.c		\
	  src/verif_case.c	\
	  src/backtracking.c	\
	  src/aff.c

OBJS	= $(SRCS:.c=.o)

CC	= clang 

CFLAGS	= -pipe -O2 -Wall -Wextra -pedantic -ansi -I include/

RM	= rm -f

CP	= cp

$(NAME)	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all	: $(NAME)
	$(CP) $(NAME) ../

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.c.o    :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
