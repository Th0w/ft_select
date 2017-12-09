#!/bin/sh
NAME=main
INC=\
	-I ../ft_btree/inc\
	-I ../ft_mem/inc\
	-I ../ft_string/inc\
	-I ../ft_printf/inc
LIBA=\
	../ft_mem/libftmem.a\
	../ft_string/libftstring.a\
	../ft_btree/libftbtree.a\
	../ft_printf/libftprintf.a
#CFLAG=-g -fsanitize=address
CC=gcc

all:
	$(CC) $(CFLAG) -o $(NAME) main.c $(INC) $(LIBA)
