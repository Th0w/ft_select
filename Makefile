####
# MANDATORY VARS
####

CC:=gcc
CFLAGS:=-Wall -Wextra -Werror
ifeq ($(SANITIZE), true)
CFLAGS+=-fsanitize=address -g3
endif

NAME:=ft_select
OBJ_D:=obj
INC_D:=inc
SEC_D:=src
LIB_D:=lib
INC:=-I $(INC_D)
CHECKER:=$(shell ./validate.sh)

####
# FT_CLIST
####

FT_CLIST:=ft_clist
FT_CLIST_DIR:=$(LIB_D)/$(FT_CLIST)
FT_CLIST_LIB:=-L $(FT_CLIST_DIR) -lftclist
FT_CLIST_INC:=-I $(FT_CLIST_DIR)/$(INC_D)
FT_CLIST_A:=libftclist.a
FT_CLIST_LA:=$(FT_CLIST_DIR)/$(FT_CLIST_A)


####
# FT_MEM
####

FT_MEM:=ft_mem
FT_MEM_DIR:=$(LIB_D)/$(FT_MEM)
FT_MEM_LIB:=-L $(FT_MEM_DIR) -lftmem
FT_MEM_INC:=-I $(FT_MEM_DIR)/$(INC_D)
FT_MEM_A:=libftmem.a
FT_MEM_LA:=$(FT_MEM_DIR)/$(FT_MEM_A)

####
# FT_BTREE
####

FT_BTREE:=ft_btree
FT_BTREE_DIR:=$(LIB_D)/$(FT_BTREE)
FT_BTREE_LIB:=-L $(FT_BTREE_DIR) -lftbtree
FT_BTREE_INC:=-I $(FT_BTREE_DIR)/$(INC_D)
FT_BTREE_A:=libftbtree.a
FT_BTREE_LA:=$(FT_BTREE_DIR)/$(FT_BTREE_A)

####
# FT_STRING
####

FT_STRING:=ft_string
FT_STRING_DIR:=$(LIB_D)/$(FT_STRING)
FT_STRING_LIB:=-L $(FT_STRING_DIR) -lftstring
FT_STRING_INC:=-I $(FT_STRING_DIR)/$(INC_D)
FT_STRING_A:=libftstring.a
FT_STRING_LA:=$(FT_STRING_DIR)/$(FT_STRING_A)

####
# DATA VARS
####

INCLUDES:=\
		  $(INC)\
		  $(FT_MEM_INC)\
		  $(FT_CLIST_INC)\
		  $(FT_BTREE_INC)\
		  $(FT_STRING_INC)

LIBRARIES:=\
		   $(FT_MEM_LIB)\
		   $(FT_CLIST_LIB)\
		   $(FT_BTREE_LIB)\
		   $(FT_STRING_LIB)\
		   -lcurses

LIBA:=\
	$(FT_MEM_LA)\
	$(FT_STRING_LA)\
	$(FT_BTREE_LA)\
	$(FT_CLIST_LA)

ITEM:=\
	ft_clist_bridge.o\
	ft_clist_move.o\
	ft_clist_get_data.o\
	callback_create.o\
	cb_mode.o\
	selection.o\
	hide_args.o\
	toggle.o\
	toggle_exe.o\
	ft_helpers.o\
	ft_intcmp.o\
	ft_match.o\
	ft_print_args.o\
	ft_print_ptrs.o\
	ft_readbuf.o\
	ft_sel_env.o\
	ft_signals.o\
	ft_sigempty.o\
	ft_style.o\
	ft_term.o\
	main.o
OBJ:=$(addprefix $(OBJ_D)/, $(ITEM))

vpath %.c src src/bridge src/callbacks
vpath %.h inc
HEADER:=ft_select.h ft_termcaps.h

####
# RULES
####

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBA)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(LIBRARIES) $(OBJ)

$(OBJ_D)/%.o: %.c
	@mkdir -p $(OBJ_D)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	$(MAKE) -C $(FT_MEM_DIR) clean
	$(MAKE) -C $(FT_CLIST_DIR) clean
	$(MAKE) -C $(FT_STRING_DIR) clean
	$(MAKE) -C $(FT_BTREE_DIR) clean
	/bin/rm -rf $(OBJ_D)

fclean: clean
	$(MAKE) -C $(FT_MEM_DIR) fclean
	$(MAKE) -C $(FT_CLIST_DIR) fclean
	$(MAKE) -C $(FT_STRING_DIR) fclean
	$(MAKE) -C $(FT_BTREE_DIR) fclean
	/bin/rm -f $(NAME)

re: fclean all

$(FT_MEM_LA):
	$(MAKE) -C $(FT_MEM_DIR) $(FT_MEM_A)

$(FT_STRING_LA):
	$(MAKE) -C $(FT_STRING_DIR) $(FT_STRING_A)

$(FT_BTREE_LA):
	$(MAKE) -C $(FT_BTREE_DIR) $(FT_BTREE_A)

$(FT_CLIST_LA):
	$(MAKE) -C $(FT_CLIST_DIR) $(FT_CLIST_A)
