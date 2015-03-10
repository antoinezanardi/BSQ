/*
** bsq.h for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:47:41 2014 Antoine Zanardi
** Last update Wed Jan 14 09:35:17 2015 Antoine Zanardi
*/

#ifndef		BSQ_H_
# define	BSQ_H_

# define	BUFFER_SIZE	4096000000

void		my_putstr_error(int, int);
void		my_putstr_error2(int, int);
void		my_show_tab(char **);
void		pass_first_line(char *, int *, int *, int *);
char		**all_in_tab(char *);
char		*parsing(char *);
int		size_lines(char *);
int		check_the_y(char *, int, int);

#endif		/* !BSQ_H_ */
