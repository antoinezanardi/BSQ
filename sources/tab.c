/*
** tab.c for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Thu Dec 18 14:15:37 2014 Antoine Zanardi
** Last update Fri Dec 19 13:00:46 2014 Antoine Zanardi
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"my.h"
#include	"bsq.h"

int		size_lines(char *str)
{
  int		compt_str;
  int		size;

  compt_str = 0;
  size = 0;
  while (str[compt_str] != '\n')
    compt_str++;
  compt_str++;
  while (str[compt_str] != '\n' && str[compt_str] != '\0')
    {
      compt_str++;
      size++;
    }
  return (size);
}

void		my_show_tab(char **tab)
{
  int		compt_lines;
  int		compt_let;

  compt_lines = 0;
  while (tab[compt_lines] != '\0')
    {
      compt_let = 0;
      while (tab[compt_lines][compt_let] != '\0')
	{
	  my_putchar(tab[compt_lines][compt_let]);
	  compt_let++;
	}
      my_putchar('\n');
      compt_lines++;
    }
}

void		pass_first_line(char *str, int *ct, int *lines, int *size_h)
{
  *ct = 0;
  *lines = -1;
  *size_h = my_getnbr(str);
  while (str[*ct] != '\n')
    *ct = *ct + 1;
  *ct = *ct + 1;
}

char		**all_in_tab(char *str)
{
  int		compt_str;
  int		lines;
  int		size_h;
  int		let;
  char		**tab;

  pass_first_line(str, &compt_str, &lines, &size_h);
  if ((tab = malloc(sizeof(char *) * (size_h + 1))) == NULL)
    return (NULL);
  while (++lines < size_h)
    {
      let = 0;
      if ((tab[lines] = malloc(sizeof(char) * size_lines(str) + 1)) == NULL)
	return (NULL);
      while (str[compt_str] != '\n' && str[compt_str] != '\0')
	{
	  tab[lines][let] = str[compt_str];
	  let++;
	  compt_str++;
	}
      tab[lines][let] = '\0';
      compt_str++;
    }
  tab[lines] = 0;
  return (tab);
}
