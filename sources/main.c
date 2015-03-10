/*
** main.c for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:28:11 2014 Antoine Zanardi
** Last update Sun Dec 21 14:19:02 2014 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"my.h"
#include	"bsq.h"

int		main(int argc, char **argv)
{
  char		*file;
  char		**tab;
  t_pos		*pos;
  t_pos		final;

  pos = NULL;
  if (argc == 1 || argc > 2)
    my_putstr_error(1, 1);
  file = parsing(argv[1]);
  tab = all_in_tab(file);
  treat(tab, &pos);
  final = find_best_square(pos);
  final_draw(tab, &final);
  free(tab);
  free(pos);
  return (0);
}
