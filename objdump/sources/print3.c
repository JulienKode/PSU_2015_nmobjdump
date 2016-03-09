/*
** print3.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 18:53:29 2016 Julien Karst
** Last update Feb 28 0:1:51 2016 Julien Karst
*/

#include 	"objdump.h"

void		file_format(t_data_64 *data)
{
  if (data->elf->e_ident[EI_CLASS] == ELFCLASS64)
    printf("%s:     file format elf64-x86-64\n", data->file);
  else
    printf("%s:     file format elf32-i386\n", data->file);
}

void		display_all_section(t_data_64 *data)
{
  int 		i;

  i = 0;
  while (i < data->elf->e_shnum)
    {
      if (good_type(data, i) && data->shdr[i].sh_size != 0)
	display_section(data, i);
      i++;
  }
}

static char 	*display_header_part_one(t_data_64 *data, unsigned int *flags)
{
  int 		i;
  char		*str;

  i = -1;
  str = NULL;
  if (data->elf->e_type == ET_REL)
    {
      str = my_strcat(str, "HAS_RELOC, ");
      *flags |= HAS_RELOC;
    }
  if (data->elf->e_type == ET_EXEC)
    {
      str = my_strcat(str, "EXEC_P, ");
      *flags |= EXEC_P;
    }
  return (str);
}

static char 	*display_header_part_two(t_data_64 *data, unsigned int *flags)
{
  int 		i;
  char 		*str;

  i = 0;
  str = NULL;
  while (i < data->elf->e_shnum)
    {
      if (data->shdr[i].sh_type == SHT_SYMTAB)
	{
	  str = my_strcat(str, "HAS_SYMS, ");
	  *flags |= HAS_SYMS;
	}
      i++;
    }
  if (data->elf->e_type == ET_DYN)
    {
      str = my_strcat(str, "DYNAMIC, ");
      *flags |= DYNAMIC;
    }
  if (data->elf->e_phnum > 0)
    {
      str = my_strcat(str, "D_PAGED, ");
      *flags |= D_PAGED;
    }
  return (str);
}

void		display_header(t_data_64 *data)
{
  char 		*str;
  unsigned int	flags;

  flags = 0;
  str = display_header_part_one(data, &flags);
  str = my_strcat(str, display_header_part_two(data, &flags));
  str[strlen(str) - 2] = 0;
  printf("architecture: %s, flags 0x%08x:\n%s\n", "i386:x86-64", flags, str);
  printf("start address 0x%016x\n", (unsigned int)data->elf->e_entry);
}
