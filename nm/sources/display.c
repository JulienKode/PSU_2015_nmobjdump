/*
** display.c for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 17:35:25 2016 Julien Karst
** Last update Sun Feb 28 13:55:29 2016 Julien Karst
*/

#include	"nm.h"

char		get_the_type(int type, int flags, int shndx,
			    int info, int value)
{
  char        res;

  res = 'U';
  if (type == SHT_NOBITS && flags == (SHF_WRITE + SHF_ALLOC))
    res = 'B';
  if ( (type == SHT_PROGBITS || type == SHT_DYNAMIC)
       && flags == (SHF_WRITE + SHF_ALLOC))
    res = 'D';
  if (type == SHT_PROGBITS && flags == (SHF_ALLOC + SHF_EXECINSTR))
    res = 'T';
  if (type == SHT_PROGBITS && flags == SHF_ALLOC)
    res = 'R';
  if (ELF64_ST_BIND(info) == STB_WEAK)
    res = 'W';
  if (type > SHT_DYNSYM)
    res = 'T';
  if ((ELF64_ST_BIND(info) == STB_LOCAL || value == 0) && res != 'U')
    res += 32;
  return (res);
}
