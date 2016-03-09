/*
** sort.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 11:34:33 2016 Julien Karst
** Last update Sun Feb 28 13:59:50 2016 Julien Karst
*/

#include	"nm.h"

int		get_the_best(char *str1, char *str2)
{
  if (str1 == NULL)
    return (2);
  if (*str1 <= 32)
    return (2);
  if (*str2 <= 32)
    return (1);
  while (*str1 || *str2)
    {
      if (*str1 < *str2)
	return (1);
      if (*str1 > *str2)
	return (2);
      str1++;
      str2++;
    }
}
