/*
** print2.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 17:02:06 2016 Julien Karst
** Last update Feb 27 23:19:26 2016 Julien Karst
*/

#include 	"objdump.h"

void 		option_s(t_data_64 *data)
{
  printf("\n");
  file_format(data);
  printf("\n");
  display_all_section(data);
}

void 		option_f(t_data_64 *data)
{
  printf("\n");
  file_format(data);
  display_header(data);
  printf("\n");
}

void 		option_sf(t_data_64 *data)
{
    if (conformity(data) == -1)
        return;
  option_f(data);
  display_all_section(data);
}
