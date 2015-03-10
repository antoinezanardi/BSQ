/*
** my_lists.c for my_lists in /home/zanard_a/rendu/Librairie/Librairie_off
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:19:28 2014 Antoine Zanardi
** Last update Fri Dec 19 10:21:53 2014 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"bsq.h"
#include	"my.h"

int             add_top_list(t_pos **list, int x, int y, int len)
{
  t_pos        *elem;

  if ((elem = malloc(sizeof(t_pos))) == NULL)
    return (0);
  elem->compt_x = x;
  elem->compt_y = y;
  elem->compt = len;
  elem->next = *list;
  *list = elem;
  return (0);
}

void            my_show_list(t_pos *list)
{
  t_pos        *tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_put_nbr(tmp->compt_x);
      my_putchar(' ');
      my_put_nbr(tmp->compt_y);
      my_putchar(' ');
      my_put_nbr(tmp->compt);
      tmp = tmp->next;
      my_putchar('\n');
    }
  my_putchar('\n');
}
