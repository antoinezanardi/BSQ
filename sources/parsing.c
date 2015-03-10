/*
** parsing.c for bsq in /home/zanard_a/rendu/Projets_TEK1/CPE_2014_bsq
**
** Made by Antoine Zanardi
** Login   <zanard_a@epitech.net>
**
** Started on  Wed Dec 17 11:52:57 2014 Antoine Zanardi
** Last update Wed Jan 14 09:31:32 2015 Antoine Zanardi
*/

#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	"bsq.h"
#include	"my.h"

int		all_o(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\n')
    compt_str++;
  compt_str++;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == 'o' || str[compt_str] == '\n')
	compt_str++;
      else
	return (0);
    }
  my_putstr_error(8, 1);
  return (1);
}

void		correct_file(char *str)
{
  int		compt_str;

  compt_str = 0;
  while (str[compt_str] != '\n')
    {
      if (str[compt_str] == '\0')
	my_putstr_error(3, 1);
      if (str[compt_str] >= '0' && str[compt_str] <= '9')
	compt_str++;
      else
	my_putstr_error(4, compt_str);
    }
  compt_str++;
  while (str[compt_str] != '\0')
    {
      if (str[compt_str] == '.' || str[compt_str] == 'o' ||
	  str[compt_str] == '\n')
	compt_str++;
      else
	my_putstr_error(5, compt_str);
    }
}

int		size_line(char *str, int *compt_str, int *check_h)
{
  int		size;

  size = 0;
  *compt_str = *compt_str + 1;
  while (str[*compt_str] != '\n' && str[*compt_str] != '\0')
    {
      size++;
      *compt_str = *compt_str + 1;
    }
  *check_h = *check_h + 1;
  return (size);
}

void		correct_size(char *str)
{
  int		compt_str;
  int		size_l;
  int		size_h;
  int		check_h;
  int		check_l;

  compt_str = 0;
  check_h = 0;
  size_l = 0;
  size_h = my_getnbr(str);
  while (str[compt_str] != '\n')
    compt_str++;
  while (str[++compt_str] != '\n' && str[compt_str] != '\0')
    size_l++;
      while (str[compt_str] != '\0')
	{
	  check_l = size_line(str, &compt_str, &check_h);
	  if ((check_l == 0 || check_l != size_l) && str[compt_str] == '\n' &&
	      str[compt_str + 1] != '\0')
	    my_putstr_error(6, check_h);
	}
  if (check_h != size_h)
    my_putstr_error(7, check_h);
}

char		*parsing(char *file)
{
  int		fd;
  int		ret;
  static char	buffer[BUFFER_SIZE];

  fd = open(file, O_RDONLY);
  if (fd == -1)
    my_putstr_error(2, 0);
  ret = read(fd, buffer, BUFFER_SIZE);
  buffer[ret] = '\0';
  close(fd);
  correct_file(buffer);
  correct_size(buffer);
  all_o(buffer);
  return (buffer);
}
