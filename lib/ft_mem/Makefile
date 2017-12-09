NAME:=libftmem.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

INC_D:=inc
ITEM:=\
	ft_bzero.o\
	ft_memalloc.o\
	ft_memchr.o\
	ft_memcmp.o\
	ft_memcpy.o\
	ft_memdel.o\
	ft_memdup.o

OBJ:=$(addprefix ./obj/, $(ITEM))

VPATH:=src:inc

HEADER:=ft_mem.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

./obj/%.o: %.c $(HEADER)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_D)

clean:
	/bin/rm -rf ./obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
