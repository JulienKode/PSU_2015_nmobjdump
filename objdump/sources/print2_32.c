/*
** print2.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 17:02:06 2016 Julien Karst
** Last update Feb 27 23:26:39 2016 Julien Karst
*/

#include 	"objdump.h"

void 		option_s_32(t_data_32 *data)
{
  printf("\n");
  file_format_32(data);
  printf("\n");
  display_all_section_32(data);
}

void 		option_f_32(t_data_32 *data)
{
  printf("\n");
  file_format_32(data);
  display_header_32(data);
  printf("\n");
}

void 		option_sf_32(t_data_32 *data)
{
    if (conformity_32(data) == -1)
        return;
  option_f_32(data);
  display_all_section_32(data);
}
