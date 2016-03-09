/*
** get_symtab.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 11:44:35 2016 Julien Karst
** Last update Sun Feb 28 13:56:24 2016 Julien Karst
*/

#include		"nm.h"

void			get_symtab(t_data_64 *data)
{
  int			i;

  i = -1;
  data->symtab = NULL;
  data->real_strtab = NULL;
  data->size_symtab = 0;
  while (++i < data->elf->e_shnum)
    {
      if (data->shdr[i].sh_type == SHT_STRTAB
	  && (data->shdr[i].sh_flags | SHF_ALLOC) == SHF_ALLOC
	  && (data->data + data->shdr[i].sh_offset) != data->strtab)
	data->real_strtab = (char*)(data->data
				    + data->shdr[i].sh_offset);
      if (data->shdr[i].sh_type == SHT_SYMTAB)
        {
	  data->size_symtab = data->shdr[i].sh_size / sizeof(Elf64_Sym);
	  data->symtab = (Elf64_Sym*)(data->data + data->shdr[i].sh_offset);
        }
    }
  if (data->symtab == NULL
      || data->real_strtab == NULL
      || data->size_symtab == 0)
    print_error();
}

void			get_symtab_32(t_data_32 *data)
{
  int			i;

  i = -1;
  data->symtab = NULL;
  data->real_strtab = NULL;
  data->size_symtab = 0;
  while (++i < data->elf->e_shnum)
    {
      if (data->shdr[i].sh_type == SHT_STRTAB
	  && (data->shdr[i].sh_flags | SHF_ALLOC) == SHF_ALLOC
	  && (data->data + data->shdr[i].sh_offset) != data->strtab)
	data->real_strtab = (char*)(data->data
				    + data->shdr[i].sh_offset);
      if (data->shdr[i].sh_type == SHT_SYMTAB)
        {
	  data->size_symtab = data->shdr[i].sh_size / sizeof(Elf32_Sym);
	  data->symtab = (Elf32_Sym*)(data->data + data->shdr[i].sh_offset);
        }
    }
  if (data->symtab == NULL
      || data->real_strtab == NULL
      || data->size_symtab == 0)
    print_error();
}
