/*
** print_function.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sat Feb 27 23:43:41 2016 Julien Karst
** Last update Feb 27 23:44:51 2016 Julien Karst
*/

#include 	"objdump.h"

void	print_space(int i)
{
  int 		a;

  a = 0;
  while (a < i)
    {
      printf(" ");
      a++;
    }
}

char 	is_printable(char c)
{
  if (c >= 32 && c <= 126)
    return (c);
  return ('.');
}

void 	print_16(char str[16], int end)
{
  int 		i;

  i = 0;
  print_space(2);
  while (i < 16)
    {
      if (i < end)
	printf("%c", is_printable(str[i]));
      else
	print_space(1);
      i++;
    }
    printf("\n");
}

void 	display_sub(char str[16], unsigned int *hex,
			    char ok, int end, int i)
{
  int 		space;

  space = 16 - end;
  space = space + (space / 4) + (16 - end);
  if (ok == 0)
    print_space(space);
  if (i != 0)
    print_16(str, end);
  if (ok == 1)
    {
      printf(" %04x ", *hex);
      *hex += 0x10;
    }
}
