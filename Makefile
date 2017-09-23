####
# MANDATORY VARS
####

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror

NAME:=ft_select
OBJ_D:=obj
INC_D:=inc
SEC_D:=src
LIB_D:=lib
INC:=-I $(INC_D)

####
# FT_CLIST
####

FT_CLIST:=ft_clist
FT_CLIST_DIR:=$(LIB_D)/$(FT_CLIST)
FT_CLIST_LIB:=-L $(FT_CLIST_DIR) -lftclist
FT_CLIST_INC:=-I $(FT_CLIST_DIR)/$(INC_D)

####
# FT_MEM
####

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_LIB:=-L $(FT_MEM_DIR) -lftmem
FT_MEM_INC:=-I $(FT_MEM_DIR)/$(INC_D)

####
# DATA VARS
####

INCLUDES:=\
		  $(INC)\
		  $(FT_MEM_INC)\
		  $(FT_CLIST_INC)

LIBRARIES:=\
		   $(FT_MEM_LIB)\
		   $(FT_CLIST_LIB)

ITEM:=\
	main.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

VPATH:=inc:src

####
# RULES
####

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(OBJ)

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	/bin/rm -rf $(OBJ_D)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
