/*
** nm_action.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 14:10:26 2016 Julien Karst
** Last update Sun Feb 28 13:58:38 2016 Julien Karst
*/

#include		"nm.h"

static void		add_elem_to_data(t_data_64 *data)
{
  t_elem_64		*elem;
  int			i;

  i = 0;
  if ((elem = malloc(data->size_symtab * sizeof(t_elem_64))) == NULL)
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

static void		nm_printf(t_data_64 *data, Elf64_Sym *tmp, int i)
{
  if (tmp->st_value)
    printf("%016x %c %s\n",
	   tmp->st_value,
	   get_the_type(data->shdr[tmp->st_shndx].sh_type,
			data->shdr[tmp->st_shndx].sh_flags,
			tmp->st_shndx,
			tmp->st_info,
			tmp->st_value),
	   data->elem[i].name);
  else
    printf("                 %c %s\n",
	   get_the_type(data->shdr[tmp->st_shndx].sh_type,
			data->shdr[tmp->st_shndx].sh_flags,
			tmp->st_shndx,
			tmp->st_info,
			tmp->st_value),
	   data->elem[i].name);
}

void			nm_action(t_data_64 *data)
{
  int			i;
  Elf64_Sym		*tmp;
  t_elem_64		*new;

  i = -1;
  get_symtab(data);
  add_elem_to_data(data);
  new = malloc(data->size_symtab * sizeof(t_elem_64));
  new = sort_elem_to_data(data->elem, new, 0, data->size_symtab);
  if (data->elem)
    free(data->elem);
  data->elem = new;
  while (++i < data->size_symtab)
    {
      tmp = data->elem[i].elem;
      if (tmp)
	nm_printf(data, tmp, i);
    }
  if (data->elem)
    free(data->elem);
}
