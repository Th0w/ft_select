NAME:=libftstring.a

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

INC_D:=inc
ITEM:=\
	ft_atoi.o\
	ft_atol.o\
	ft_is.o\
	ft_getnumber.o\
	ft_pathjoin.o\
	ft_putblank.o\
	ft_putstr_fd.o\
	ft_strcat.o\
	ft_strchr.o\
	ft_strclr.o\
	ft_strcmp.o\
	ft_strcpy.o\
	ft_strdel.o\
	ft_strdup.o\
	ft_strequ.o\
	ft_strforeach.o\
	ft_strindex.o\
	ft_striter.o\
	ft_striteri.o\
	ft_strjoin.o\
	ft_strlcat.o\
	ft_strlen.o\
	ft_strmap.o\
	ft_strmapi.o\
	ft_strncat.o\
	ft_strncmp.o\
	ft_strncpy.o\
	ft_strnequ.o\
	ft_strnew.o\
	ft_strnstr.o\
	ft_putchar.o\
	ft_strrchr.o\
	ft_strsplit.o\
	ft_strstr.o\
	ft_strsub.o\
	ft_strtrim.o\
	ft_uintlen.o

OBJ:=$(addprefix ./obj/, $(ITEM))

VPATH:=src:inc

HEADER:=ft_string.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

./obj/%.o: %.c $(HEADER)
	@mkdir -p obj
	$(CC) $(CFLAGS) -c -o $@ $<  -I $(INC_D)

clean:
	/bin/rm -rf ./obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
