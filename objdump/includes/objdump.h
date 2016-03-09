/*
** objdump.h for Objdump by karst_j in /home/karst_j/psu_2015_nmobjdump/objdump/includes/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Sun Feb 21 12:31:43 2016 Julien Karst
** Last update Sun Feb 28 14:53:47 2016 Julien Karst
*/

#ifndef 		OBJDUMP_H_
# define 		OBJDUMP_H_

#include 		<elf.h>
#include		<sys/mman.h>
#include 		<unistd.h>
#include 		<sys/stat.h>
#include 		<fcntl.h>
#include 		<stdio.h>
#include 		<string.h>
#include		<stdlib.h>
#include 		"flags.h"
#include 		"my.h"

#define ARCH_32         1
#define ARCH_64         2

typedef struct		s_data_64
{
  void			*data;
  void			*end;
  Elf64_Ehdr		*elf;
  Elf64_Shdr		*shdr;
  char 			*strtab;
  char 			*file;
}			t_data_64;

typedef struct		s_data_32
{
  void			*data;
  void			*end;
  Elf32_Ehdr	        *elf;
  Elf32_Shdr		*shdr;
  char 			*strtab;
  char 			*file;
}			t_data_32;

typedef struct		s_data
{
  int			fd;
    int                 arch;
    t_data_32           data32;
    t_data_64           data64;
}			t_data;

			/*--- main.c ---*/
int 			objdump(int, char **);

			/*--- check.c ---*/
int 			open_file(t_data *, char *);
int			outside_the_file(void *, void *);

			/*--- x86-64.c ---*/
int			make_64bits(t_data *data);
int			make_32bits(t_data *data);

			/*--- print2.c ---*/
void			option_s(t_data_64 *);
void			option_f(t_data_64 *);
void			option_sf(t_data_64 *);

			/*--- print2_32.c ---*/
void			option_f_32(t_data_32 *);
void			option_s_32(t_data_32 *);
void			option_sf_32(t_data_32 *);

			/*--- objdump.c ---*/
int			conformity(t_data_64 *);
int			good_type(t_data_64 *, int);
int			conformity_32(t_data_32 *);
int			good_type_32(t_data_32 *, int);

			/*--- print3.c ---*/
void			file_format(t_data_64 *);
void			display_all_section(t_data_64 *);
void			display_header(t_data_64 *);

			/*--- print3_32.c ---*/
void			file_format_32(t_data_32 *);
void			display_all_section_32(t_data_32 *);
void			display_header_32(t_data_32 *);

			/*--- print_function.c ---*/
void			display_sub(char str[16], unsigned int *hex, char ok, int end, int i);
void			print_16(char str[16], int end);
char			is_printable(char);
void			print_space(int);

			/*--- print.c ---*/
void			display_section(t_data_64 *, int);
void			display_section_32(t_data_32 *, int);

			/*--- check_option.c ---*/
int 			are_in(char **, char *);

			/*--- error.c ---*/
void			error_open_file(char *, char *);

#endif 			/* OBJDUMP_H_ */
