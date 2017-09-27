FCT:=btree
NAME:=libft${FCT}.a
CC:=gcc
CFLAGS:=-Wall -Wextra -Werror -O2
OBJ_D:=obj
ITEM:=\
	ft_btree_clear.o\
	ft_btree_count.o\
	ft_btree_create.o\
	ft_btree_foreach.o\
	ft_btree_rev_foreach.o\
	ft_btree_insert.o\
	ft_btree_ordered.o\
	ft_btree_search.o

OBJ:=$(addprefix ./${OBJ_D}/, $(ITEM))
HEADERS:=inc/ft_btree.h
INC:=\
	-I inc\
	-I ../ft_mem/inc

VPATH:=src:inc

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

./${OBJ_D}/%.o: %.c $(HEADERS)
	mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	/bin/rm -rf $(OBJ_D)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all

