/*
** main.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 12:31:02 2016 Julien Karst
** Last update Sun Feb 28 14:56:15 2016 Julien Karst
*/

#include 	"objdump.h"

static int     objdump_action(t_data *data, char *str)
{
    if (open_file(data, str) == -1)
        return (-1);
    if (data->arch == ARCH_64)
        option_sf(&(data->data64));
    else if (data->arch == ARCH_32)
        option_sf_32(&(data->data32));
    if (data->fd != -1)
      close(data->fd);
    return (0);
}

int 			objdump(int ac, char **argv)
{
    int         i;
  t_data 		data;

  i = 1;
  if (ac == 1)
    if (objdump_action(&data, "a.out") == -1)
        return (0);
  while (i < ac)
    {
        if (objdump_action(&data, argv[i]) == -1)
            return (0);
        i++;
    }
  return (0);
}

int		main(int ac, char **argv)
{
    return (objdump(ac, argv));
}
