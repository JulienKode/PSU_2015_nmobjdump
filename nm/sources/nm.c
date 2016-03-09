/*
** nm.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 11:25:02 2016 Julien Karst
** Last update Sun Feb 28 16:08:17 2016 Julien Karst
*/

#include		"nm.h"

int			conformity(t_data_64 *data)
{
  int			i;

  i = 0;
  while (i < data->elf->e_shnum)
    {
      if ((void*)(data->shdr + i) > (void*)(data->end))
        {
	  fprintf(stderr, "objdump: %s: File truncated\n", data->file);
	  return (-1);
        }
      i++;
    }
  return (1);
}

int			conformity_32(t_data_32 *data)
{
  int			i;

  i = 0;
  while (i < data->elf->e_shnum)
    {
      if ((void*)(data->shdr + i) > (void*)(data->end))
        {
	  fprintf(stderr, "objdump: %s: File truncated\n", data->file);
	  return (-1);
        }
      i++;
    }
  return (1);
}
