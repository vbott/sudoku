##
## Makefile for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv
## 
## Made by mickael cerisier
## Login   <cerisi_m@epitech.net>
## 
## Started on  Sun Apr 25 18:29:40 2010 mickael cerisier
## Last update Sun Apr 25 18:29:41 2010 mickael cerisier
##

all	:
	$(MAKE) all -C etape_2/

clean	:
	$(MAKE) clean -C etape_2/

fclean	:
	$(MAKE) fclean -C etape_2/

re	: fclean all