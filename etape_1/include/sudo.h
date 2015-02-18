/*
** sudo.h for sudoki-bi in /u/all/cerisi_m/cu/rendu/svn/rushmv/etape_1
** 
** Made by mickael cerisier
** Login   <cerisi_m@epitech.net>
** 
** Started on  Sun Apr 25 12:06:07 2010 mickael cerisier
** Last update Sun Apr 25 12:06:08 2010 mickael cerisier
*/

#ifndef		_SUDO_H_
# define	_SUDO_H_

# define	BUFF_SIZE 21
# define	ZERO -16

/* aff.c */
int	my_strlen(const char *s);
void	my_perror(const char *str);
void	my_putstr(const char *str);
void	my_putchar(const char c);

/* find_togo.c */
void	find_togo(int tab[9][9], int pos[2]);

/* func_manual.c */
int	is_finished(int tab[9][9]);
void	tab_cpy(int src[9][9], int dest[9][9]);

/* get_map.c */
void	get_map(int res[9][9]);

/* main.c */
void	aff(int tab[9][9]);

/* int_to_str.c */
void	int_to_str(int nb, char *str);

/* verif_square.c */
int	verif_square(int x, int y, int nb, int tab[9][9]);
int	verif_line_col(int x, int y, int nb, int tab[9][9]);

/* my_strcat.c */
char	*my_strcat(char *s1, char *s2);

/* my_strcmp.c */
int	my_strcmp(const char *s1, const char *s2);

#endif
