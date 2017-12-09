NAME:=libftclist.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

OBJ_D:=obj
LIB_D:=..

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_INC:=$(FT_MEM_DIR)/inc

INC_D:=\
	-I inc\
	-I $(FT_MEM_INC)
VPATH:=src:inc
HEADER:=ft_clist.h

ITEM:=\
	ft_clist_clear.o\
	ft_clist_new.o\
	ft_clist_pend.o\
	ft_clist_foreach.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

${OBJ_D}/%.o: %.c #$(HEADER)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_D)

clean:
	/bin/rm -rf $(OBJ_D)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
