/*
** treat.c for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Dec 18 15:47:46 2014 Antoine Zanardi
** Last update Sun Dec 21 10:54:39 2014 Antoine Zanardi
*/

#include	"my.h"
#include	"bsq.h"

int		check_the_y(char *str, int compt_str, int x)
{
  while (compt_str >= x)
    {
      if (str[compt_str] == 'o')
	return (1);
      else
	compt_str--;
    }
  return (0);
}

int		find_square(char **tab, int x, int y, t_pos **pos)
{
  int		len;
  int		save_y;
  int		lim;

  len = 0;
  while (tab[len + y] != '\0')
    {
      lim = x + len;
      save_y = y;
      if (tab[y][lim] != 'o' && tab[y][lim] != '\0')
	{
	  while (save_y <= len + y)
	    {
	      if ((check_the_y(tab[save_y], lim, x)) == 1)
		return (1);
	      save_y++;
	    }
	  add_top_list(pos, x, y, len);
	}
      else
	return (1);
      len++;
    }
  return (0);
}

void		treat(char **tab, t_pos **pos)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (tab[y] != '\0')
    {
      if (tab[y][x] == '\0')
	{
	  y++;
	  x = 0;
	}
      else if (tab[y][x] != 'o')
	{
	  find_square(tab, x, y, pos);
	  x++;
	}
      else
	x++;
    }
}
