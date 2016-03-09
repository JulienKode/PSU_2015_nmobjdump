/*
** x86-64.c for Objdump in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sat Feb 27 22:15:52 2016 Julien Karst
** Last update Sun Feb 28 00:29:24 2016 Julien Karst
*/

#include		"objdump.h"

static int		good_elf_64(t_data *data)
{
  if (data->data64.elf->e_ident[EI_MAG0] == ELFMAG0
      && data->data64.elf->e_ident[EI_MAG1] == ELFMAG1
      && data->data64.elf->e_ident[EI_MAG2] == ELFMAG2
      && data->data64.elf->e_ident[EI_MAG3] == ELFMAG3
      && data->data64.elf->e_ident[EI_CLASS] == ELFCLASS64)
    return (1);
  return (-1);
}

static int		good_elf_32(t_data *data)
{
  if (data->data32.elf->e_ident[EI_MAG0] == ELFMAG0
      && data->data32.elf->e_ident[EI_MAG1] == ELFMAG1
      && data->data32.elf->e_ident[EI_MAG2] == ELFMAG2
      && data->data32.elf->e_ident[EI_MAG3] == ELFMAG3
      && data->data32.elf->e_ident[EI_CLASS] == ELFCLASS32)
    return (1);
  return (-1);
}

int			make_64bits(t_data *data)
{
  data->arch = ARCH_64;
  if (good_elf_64(data) == -1)
    error_open_file("objdump: %s: File format not recognized\n"
		    , data->data64.file);
  if ((data->data64.shdr = (Elf64_Shdr*)(data->data64.data
					 + data->data64.elf->e_shoff)) == NULL)
    error_open_file("Error -> invalid pointer\n", NULL);
  outside_the_file((void*)data->data64.shdr, (void*)data->data64.end);
  if ((data->data64.strtab =
       (char*)(data->data64.data + data->data64.shdr
	       [data->data64.elf->e_shstrndx].sh_offset)
       ) == NULL)
    error_open_file("Error -> invalid pointer\n", NULL);
  outside_the_file((void*)data->data64.strtab, (void*)data->data64.end);
  if (data->data64.strtab && data->data64.shdr && data->data64.elf)
    return (1);
  return (-1);
}

int			make_32bits(t_data *data)
{
  data->data32.file = data->data64.file;
  data->data32.data = data->data64.data;
  data->data32.end = data->data64.end;
  data->data32.elf = (Elf32_Ehdr*)(data->data64.elf);
  data->arch = ARCH_32;
  if (good_elf_32(data) == -1)
    error_open_file("objdump: %s: File format not recognized\n"
		    , data->data32.file);
  if ((data->data32.shdr =
       (Elf32_Shdr*)(data->data32.data
		     + data->data32.elf->e_shoff)) == NULL)
    error_open_file("Error -> invalid pointer\n", NULL);
  outside_the_file((void*)data->data32.shdr, (void*)data->data32.end);
  if ((data->data32.strtab = (char*)(data->data32.data
				     + data->data32.shdr
				     [data->data32.elf->e_shstrndx].sh_offset)) == NULL)
    error_open_file("Error -> invalid pointer\n", NULL);
  outside_the_file((void*)data->data32.strtab, (void*)data->data32.end);
  if (data->data32.strtab && data->data32.shdr && data->data32.elf)
    return (1);
  return (-1);
}
