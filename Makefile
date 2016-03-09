##
## Makefile for  in /home/karst_j/psu_2015_nmobjdump
##
## Made by Julien Karst
## Login   <karst_j@epitech.net>
##
## Started on  Sun Feb 21 11:59:51 2016 Julien Karst
## Last update Feb 23 22:49:30 2016 Julien Karst
##

$@

SUBDIRS = nm objdump

all: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

re clean fclean all:
	$(MAKE) -C nm $@
	$(MAKE) -C objdump $@

.PHONY: $(SUBDIRS)
