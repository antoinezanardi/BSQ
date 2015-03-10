/*
** error.c for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:42:39 2014 Antoine Zanardi
** Last update Wed Jan 14 09:09:34 2015 Antoine Zanardi
*/

#include	<stdlib.h>
#include	"bsq.h"
#include	"my.h"

void		my_putstr_error(int error, int arg)
{
  if (error == 1)
    my_putstr("BSQ needs a file, and only one.\n");
  else if (error == 2)
    my_putstr("Where's the file ? You lost it ?\n");
  else if (error == 3)
    my_putstr("There's no map, but only the size of it\n");
  else if (error == 4)
    {
      my_putstr("La première ligne du fichier est fausse au caractère ");
      my_put_nbr(arg + 1);
      my_putchar('\n');
    }
  else if (error == 5)
    {
      my_putstr("Le caractère n°");
      my_put_nbr(arg + 1);
      my_putstr(" n'est ni un . ni un o\n");
    }
  else if (error == 6)
    {
      my_putstr("La ligne n°");
      my_put_nbr(arg + 1);
      my_putstr(" n'est pas de la bonne taille\n");
    }
  my_putstr_error2(error, arg);
}

void		my_putstr_error2(int error, int arg)
{
  if (error == 7)
    {
      my_putstr("La map ne fait pas la hauteur estimée (taille de ");
      my_put_nbr(arg + 1);
      my_putstr(")\n");
    }
  if (error == 8)
    my_putstr("La map n'est faite que de o, dur de faire des carrés !\n");
  exit(1);
}
