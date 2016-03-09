/*
** check_option.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 19:05:40 2016 Julien Karst
** Last update Feb 21 19:23:31 2016 Julien Karst
*/

#include 		"objdump.h"

int 		are_in(char **argv, char *str)
{
  int 		y;

  y = 0;
  while (argv[y])
    {
      if (argv[y])
	{
	  if (strcmp(argv[y], str) == 0)
	    return (1);
	}
      y++;
    }
  return (0);
}
