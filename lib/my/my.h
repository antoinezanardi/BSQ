/*
** my.h for my in /home/zanard_a/rendu/Brouillons_Piscine/J9/ex2
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Oct  9 18:41:53 2014 Antoine Zanardi
** Last update Sun Dec 21 11:31:42 2014 Antoine Zanardi
*/

#ifndef		MY_H_
# define	MY_H_

typedef struct	s_pos
{
  int		compt_x;
  int		compt;
  int		compt_y;
  struct s_pos	*next;
}		t_pos;

void		final_draw(char **, t_pos *);
void		my_putchar(char);
void		my_put_nbr(int);
void		my_putstr(char*);
void		my_show_list(t_pos *);
void		treat(char **, t_pos **);
void		replace_right(t_pos *, t_pos *);
int		add_top_list(t_pos **, int, int, int);
int		add_bot_list(t_pos **, int);
int		my_strlen(char*);
int		my_getnbr(char*);
int		find_square(char **, int, int, t_pos **);
int		check_the_y(char *, int, int);
t_pos		find_best_square(t_pos *);


#endif /* !MY_H_ */
