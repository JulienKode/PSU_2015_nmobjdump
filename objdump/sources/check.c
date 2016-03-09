/*
** check.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 12:43:21 2016 Julien Karst
** Last update Sun Feb 28 14:57:45 2016 Julien Karst
*/

#include 		"objdump.h"

static int 		filesize(int fd);

static int 		filesize(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

int			outside_the_file(void *pos, void *end)
{
  if (pos < end)
    return (1);
  error_open_file("objdump: truncated file\n", NULL);
  return (0);
}

int 			open_file(t_data *data, char *file)
{
  data->data64.file = file;
  data->fd = -1;
  if ((data->fd = open(file, O_RDONLY)) == -1)
    error_open_file("objdump: '%s': No such file\n", file);
  if ((data->data64.data = mmap(NULL, filesize(data->fd), PROT_READ,
				MAP_SHARED, data->fd, 0)) == MAP_FAILED)
    error_open_file("mmap failed sorry\n", NULL);
  data->data64.end = data->data64.data + filesize(data->fd);
  if ((data->data64.elf = (Elf64_Ehdr*)data->data64.data) == NULL)
    error_open_file("Error -> invalid pointer\n", file);
  outside_the_file((void*)data->data64.elf, (void*)data->data64.end);
  if (data->data64.elf->e_ident[EI_CLASS] == ELFCLASS32)
    return (make_32bits(data));
  else if (data->data64.elf->e_ident[EI_CLASS] == ELFCLASS64)
    return (make_64bits(data));
  else
    error_open_file("objdump: %s: File format not recognized\n"
		    , data->data64.file);
}
