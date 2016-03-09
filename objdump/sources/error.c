/*
** error.c for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/sources/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sat Feb 27 22:43:56 2016 Julien Karst
** Last update Feb 28 0:18:29 2016 Julien Karst
*/

#include "objdump.h"

void     error_open_file(char *str, char *param)
{
    if (param != NULL)
        fprintf(stderr, str, param);
    else
        fprintf(stderr, str);
    exit(-1);
}
