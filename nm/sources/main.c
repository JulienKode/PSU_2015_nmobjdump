/*
** main.c for  in /home/karst_j/psu_2015_nmobjdump/nm/sources
**
** Made by Julien Karst
** Login   <karst_j@epitech.net>
**
** Started on  Fri Feb 26 13:46:12 2016 Julien Karst
** Last update Sun Feb 28 15:04:02 2016 Julien Karst
*/

#include 		"nm.h"

static int		nm_make(t_data *data, char *str)
{
  if (open_file(data, str) == -1)
    return (-1);
  if (data->arch == ARCH_64)
    nm_action(&(data->data64));
  else if (data->arch == ARCH_32)
    nm_action_32(&(data->data32));
  if (data->fd != -1)
    close(data->fd);
  return (0);
}

int 			nm(int ac, char **argv)
{
  int			i;
  t_data 		data;

  i = 1;
  if (ac == 1)
    if (nm_make(&data, "a.out") == -1)
      return (0);
  while (i < ac)
    {
      if (nm_make(&data, argv[i]) == -1)
	return (0);
      i++;
    }
  return (0);
}

int			main(int ac, char **argv)
{
  nm(ac, argv);
  return (0);
}
