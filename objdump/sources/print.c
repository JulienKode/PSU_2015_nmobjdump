/*
** print.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 12:58:00 2016 Julien Karst
** Last update Feb 27 23:48:44 2016 Julien Karst
*/

#include 	"objdump.h"

void 		display_section(t_data_64 *data, int shnum)
{
  char		str[16];
  unsigned int	hex;
  int 		i;
  unsigned char	tmp;

  i = 0;
  hex = (unsigned int)(data->shdr[shnum].sh_addr);
  str[0] = 0;
  printf("Contents of section %s:\n",
	 &(data->strtab[data->shdr[shnum].sh_name]));
  while (i < data->shdr[shnum].sh_size)
    {
      tmp = *(char*)(data->data + data->shdr[shnum].sh_offset + i);
      if (i % 16 == 0)
	display_sub(str, &hex, 1, 16, i);
      else if (i % 4 == 0)
	printf(" ");
      printf("%02x", tmp);
      str[i % 16] = tmp;
      i++;
    }
  if (i % 16 != 0)
    display_sub(str, &hex, 0, i % 16, i);
  if (i % 16 == 0)
    display_sub(str, &hex, 0, 16, i);
}

void 		display_section_32(t_data_32 *data, int shnum)
{
  char		str[16];
  unsigned int	hex;
  int 		i;
  unsigned char	tmp;

  i = 0;
  hex = (unsigned int)(data->shdr[shnum].sh_addr);
  str[0] = 0;
  printf("Contents of section %s:\n",
	 &(data->strtab[data->shdr[shnum].sh_name]));
  while (i < data->shdr[shnum].sh_size)
    {
      tmp = *(char*)(data->data + data->shdr[shnum].sh_offset + i);
      if (i % 16 == 0)
	display_sub(str, &hex, 1, 16, i);
      else if (i % 4 == 0)
	printf(" ");
      printf("%02x", tmp);
      str[i % 16] = tmp;
      i++;
    }
  if (i % 16 != 0)
    display_sub(str, &hex, 0, i % 16, i);
  if (i % 16 == 0)
    display_sub(str, &hex, 0, 16, i);
}
