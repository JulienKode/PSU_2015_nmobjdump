/*
** nm_action.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 14:10:26 2016 Julien Karst
** Last update Sun Feb 28 13:59:31 2016 Julien Karst
*/

#include		"nm.h"

static void		add_elem_to_data_32(t_data_32 *data)
{
  t_elem_32		*elem;
  int			i;

  i = 0;
  if ((elem = malloc(data->size_symtab * sizeof(t_elem_32))) == NULL)
    {
      fprintf(stderr, "Malloc Failed\n");
      exit(1);
    }
  while (i < data->size_symtab)
    {
      elem[i].name = (char*)(data->real_strtab + data->symtab[i].st_name);
      elem[i].elem = data->symtab + i;
      elem[i].pos = i;
      i++;
    }
  data->elem = elem;
}

static void		nm_printf_32(t_data_32 *data, Elf32_Sym *tmp, int i)
{
  if (tmp->st_value)
    printf("%08x %c %s\n",
	   tmp->st_value,
	   get_the_type(data->shdr[tmp->st_shndx].sh_type,
			data->shdr[tmp->st_shndx].sh_flags,
			tmp->st_shndx,
			tmp->st_info,
			tmp->st_value),
	   data->elem[i].name);
  else
    printf("         %c %s\n",
	   get_the_type(data->shdr[tmp->st_shndx].sh_type,
			data->shdr[tmp->st_shndx].sh_flags,
			tmp->st_shndx,
			tmp->st_info,
			tmp->st_value),
	   data->elem[i].name);
}

void			nm_action_32(t_data_32 *data)
{
  int			i;
  Elf32_Sym		*tmp;
  t_elem_32		*new;

  i = -1;
  get_symtab_32(data);
  add_elem_to_data_32(data);
  new = malloc(data->size_symtab * sizeof(t_elem_32));
  new = sort_elem_to_data_32(data->elem, new, 0, data->size_symtab);
  if (data->elem)
    free(data->elem);
  data->elem = new;
  while (++i < data->size_symtab)
    {
      tmp = data->elem[i].elem;
      if (tmp)
	nm_printf_32(data, tmp, i);
    }
  if (data->elem)
    free(data->elem);
}
