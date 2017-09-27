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
# FT_BTREE
####

FT_BTREE:=ft_btree
FT_BTREE_DIR:=$(LIB_D)/$(FT_BTREE)
FT_BTREE_LIB:=-L $(FT_BTREE_DIR) -lftbtree
FT_BTREE_INC:=-I $(FT_BTREE_DIR)/$(INC_D)

####
# DATA VARS
####

INCLUDES:=\
		  $(INC)\
		  $(FT_MEM_INC)\
		  $(FT_CLIST_INC)\
		  $(FT_BTREE_INC)

LIBRARIES:=\
		   $(FT_MEM_LIB)\
		   $(FT_CLIST_LIB)\
		   $(FT_BTREE_LIB)\
		   -lcurses

ITEM:=\
	callback_create.o\
	move.o\
	selection.o\
	ft_clist_bridge.o\
	ft_intcmp.o\
	ft_sel_args.o\
	ft_sel_env.o\
	helpers.o\
	main.o\
	signals.o\
	term_mod.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

VPATH:=src:src/callbacks:inc

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
