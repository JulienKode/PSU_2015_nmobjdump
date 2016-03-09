/*
** error.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sat Feb 22 12:47:56 2016 Julien Karst
** Last update Sun Feb 28 13:55:51 2016 Julien Karst
*/

#include	"nm.h"

void		error_open_file(char *str, char *param)
{
  if (param != NULL)
    fprintf(stderr, str, param);
  else
    fprintf(stderr, str);
  exit(-1);
}

void		print_error()
{
  fprintf(stderr, "No Symtab in the file, sorry\n");
  exit(1);
}
