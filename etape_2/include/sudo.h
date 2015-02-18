/*
** sudo.h for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_2
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:08:27 2010 mickael cerisier
** Last update Sun Apr 25 12:08:27 2010 mickael cerisier
*/

#ifndef		_SUDO_H_
# define	_SUDO_H_

# define	BUFF_SIZE 21
# define	ZERO -16

/* aff.c */
int	my_strlen(const char *s);
void	my_puterror(const char *str);
void	my_putstr(const char *str);
void	my_putchar(const char c);

/* backtracking.c */
int	backtracking(int tab[9][9]);

/* find_togo.c */
void	find_togo(int tab[9][9], int pos[2]);

/* get_map.c */
void	get_map(int res[9][9]);

/* verif_square.c */
int	verif_square(int x, int y, int nb, int tab[9][9]);
int	verif_line_col(int x, int y, int nb, int tab[9][9]);

#endif
