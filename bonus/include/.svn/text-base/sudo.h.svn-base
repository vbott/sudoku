/*
** sudo.h for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/bonus
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 18:27:57 2010 mickael cerisier
** Last update Sun Apr 25 18:28:30 2010 mickael cerisier
*/

#ifndef		_SUDO_H_
# define	_SUDO_H_

# define	BUFF_SIZE 21
# define	ZERO -16
# define	MAXTHREAD 1024

/* aff.c */
int	my_strlen(const char *s);
void	my_puterror(const char *str);
void	my_putstr(const char *str);
void	my_putchar(const char c);

/* backtracking.c */
int	backtracking(int **tab);

/* find_togo.c */
void	find_togo(int **tab, int pos[2]);

/* get_map.c */
int	get_map(int **res);

/* verif_square.c */
int	verif_square(int x, int y, int nb, int **tab);
int	verif_line_col(int x, int y, int nb, int **tab);

/* xmalloc.c */
void	*xmalloc(int size);

#endif
