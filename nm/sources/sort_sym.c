/*
** sort_sym.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 14:02:36 2016 Julien Karst
** Last update Sun Feb 28 14:00:54 2016 Julien Karst
*/

#include		"nm.h"

t_elem_64		*sort_elem_to_data(
					   t_elem_64 *base, t_elem_64 *new, int pos, int size)
{
  int			i;
  t_elem_64		*tmp;

  i = 0;
  tmp = &base[0];
  while (++i < size)
    if (base[i].elem && *(base[i].name) && base[i].elem != NULL)
      if (get_the_best(tmp->name, base[i].name) == 2)
	tmp = &base[i];
  if (tmp->elem && *tmp->name && tmp->elem->st_info != STT_FILE)
    {
      new[pos].name = tmp->name;
      new[pos].elem = tmp->elem;
      new[pos].pos = pos;
    }
  else if (*tmp->name == 0)
    return (new);
  else
    new[pos].elem = NULL;
  tmp->elem = NULL;
  pos++;
  if ((pos + 1) < size)
    sort_elem_to_data(base, new, pos, size);
  return (new);
}

t_elem_32		*sort_elem_to_data_32(
					      t_elem_32 *base, t_elem_32 *new, int pos, int size)
{
  int			i;
  t_elem_32		*tmp;

  i = 0;
  tmp = &base[0];
  while (++i < size)
    if (base[i].elem && *(base[i].name) && base[i].elem != NULL)
      if (get_the_best(tmp->name, base[i].name) == 2)
	tmp = &base[i];
  if (tmp->elem && *tmp->name && tmp->elem->st_info != STT_FILE)
    {
      new[pos].name = tmp->name;
      new[pos].elem = tmp->elem;
      new[pos].pos = pos;
    }
  else if (*tmp->name == 0)
    return (new);
  else
    new[pos].elem = NULL;
  tmp->elem = NULL;
  pos++;
  if ((pos + 1) < size)
    sort_elem_to_data_32(base, new, pos, size);
  return (new);
}
