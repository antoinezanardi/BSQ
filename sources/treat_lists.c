/*
** treat_lists.c for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Fri Dec 19 14:03:34 2014 Antoine Zanardi
** Last update Sun Dec 21 14:18:48 2014 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"bsq.h"

void		final_draw(char **tab, t_pos *pos)
{
  int		x;
  int		y;

  y = 0;
  while (tab[y] != 0)
    {
      x = 0;
      while (tab[y][x] != '\0')
	{
	  if (x >= pos->compt_x && x <= pos->compt_x + pos->compt &&
	      y >= pos->compt_y && y <= pos->compt_y + pos->compt)
	    my_putchar('x');
	  else
	    my_putchar(tab[y][x]);
	  x++;
	}
      y++;
      my_putchar('\n');
    }
}

void		replace_right(t_pos *tmp, t_pos *final_pos)
{
  if (final_pos->compt < tmp->compt)
    {
      final_pos->compt = tmp->compt;
      final_pos->compt_y = tmp->compt_y;
      final_pos->compt_x = tmp->compt_x;
    }
  else if (final_pos->compt == tmp->compt)
    {
      if (final_pos->compt_y > tmp->compt_y)
	{
	      final_pos->compt_y = tmp->compt_y;
	      final_pos->compt_x = tmp->compt_x;
	}
      else if (final_pos->compt_y == tmp->compt_y)
	{
	  if (final_pos->compt_x > tmp->compt_x)
	    final_pos->compt_x = tmp->compt_x;
	}
    }
}

t_pos		find_best_square(t_pos *pos)
{
  t_pos		final_pos;
  t_pos		*tmp;

  tmp = pos;
  final_pos.compt = tmp->compt;
  final_pos.compt_x = tmp->compt_x;
  final_pos.compt_y = tmp->compt_y;
  while (tmp != NULL)
    {
      replace_right(tmp, &final_pos);
      tmp = tmp->next;
    }
  return (final_pos);
}
