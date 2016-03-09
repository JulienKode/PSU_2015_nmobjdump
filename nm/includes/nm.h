/*
** nm.h for Nm by karst_j in /home/karst_j/psu_2015_nmobjdump/nm/includes/
**
** Made by Julien Karst
** Login   <karst_j@epitech.eu>
**
** Started on  Fri Feb 26 11:12:19 2016 Julien Karst
** Last update Sun Feb 28 16:08:53 2016 Julien Karst
*/

#ifndef				NM_H_
# define			NM_H_

#include			<elf.h>
#include			<sys/mman.h>
#include			<unistd.h>
#include			<sys/stat.h>
#include			<fcntl.h>
#include			<stdio.h>
#include			<string.h>
#include			<stdlib.h>

#define ARCH_32			1
#define ARCH_64			2

typedef struct			s_elem_32
{
  Elf32_Sym			*elem;
  char				*name;
  int				pos;
}				t_elem_32;

typedef struct			s_elem_64
{
  Elf64_Sym			*elem;
  char				*name;
  int				pos;
}				t_elem_64;

typedef struct			s_data_64
{
  void				*data;
  void				*end;
  Elf64_Ehdr			*elf;
  Elf64_Shdr			*shdr;
  char				*strtab;
  char				*file;
  char				*real_strtab;
  int				size_symtab;
  Elf64_Sym			*symtab;
  t_elem_64			*elem;
}				t_data_64;

typedef struct			s_data_32
{
  void				*data;
  void				*end;
  Elf32_Ehdr			*elf;
  Elf32_Shdr			*shdr;
  char				*strtab;
  char				*file;
  char				*real_strtab;
  int				size_symtab;
  Elf32_Sym			*symtab;
  t_elem_32			*elem;
}				t_data_32;

typedef struct			s_data
{
  int				fd;
  int				arch;
  t_data_32			data32;
  t_data_64			data64;
}				t_data;

				/*--- main.c ---*/
int				nm(int, char **);

				/*--- check.c ---*/
int				outside_the_file(void *, void *);
int				open_file(t_data *, char *);

				/*--- x86-64.c ---*/
int				make_64bits(t_data *);
int				make_32bits(t_data *);

				/*--- nm_action.c ---*/
void				nm_action(t_data_64 *);

				/*--- nm_action_32.c ---*/
void				nm_action_32(t_data_32 *);

				/*--- get_symtab.c ---*/
void				get_symtab(t_data_64 *);
void				get_symtab_32(t_data_32 *);

				/*--- sort.c ---*/
int				get_the_best(char *, char *);

				/*--- sort_sym.c ---*/
t_elem_64			*sort_elem_to_data(t_elem_64 *, t_elem_64 *, int, int);
t_elem_32			*sort_elem_to_data_32(t_elem_32 *, t_elem_32 *, int, int);

				/*--- display.c ---*/
char				get_the_type(int, int, int, int, int);

				/*--- nm.c ---*/
int				conformity(t_data_64 *);
int				conformity_32(t_data_32 *);

				/*--- error.c ---*/
void				error_open_file(char *, char *);
void				print_error();

#endif				/* NM_H_ */
