/*
** objdump.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 12:33:34 2016 Julien Karst
** Last update Sun Feb 28 16:06:55 2016 Julien Karst
*/

#include 		"objdump.h"

int             conformity(t_data_64 *data)
{
    int     i;

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

int 	       good_type(t_data_64 *data, int i)
{
  int getA;
  int getW;

  getW = data->shdr[i].sh_flags & SHF_WRITE;
  getA = data->shdr[i].sh_flags & SHF_ALLOC;
  if (data->shdr[i].sh_type == SHT_NOBITS)
    return (0);
  if (data->shdr[i].sh_type == SHT_PROGBITS
       || data->shdr[i].sh_type == SHT_NOTE
      || getA == SHF_ALLOC || getW == SHF_WRITE)
    return (1);
  return (0);
}

int             conformity_32(t_data_32 *data)
{
    int     i;

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

int 	       good_type_32(t_data_32 *data, int i)
{
   int getA;
  int getW;

  getW = data->shdr[i].sh_flags & SHF_WRITE;
  getA = data->shdr[i].sh_flags & SHF_ALLOC;
  if (data->shdr[i].sh_type == SHT_NOBITS)
    return (0);
  if (data->shdr[i].sh_type == SHT_PROGBITS
       || data->shdr[i].sh_type == SHT_NOTE
      || getA == SHF_ALLOC || getW == SHF_WRITE)
    return (1);
  return (0);
}
