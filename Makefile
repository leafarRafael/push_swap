NAME			:= push_swap
CFLAGS			:= -Wextra -Wall -Werror -g3
CC				:= cc
LIBFT			:= ./lib/lib_get_print/libft.a
PATH_MAKE_LIB	:= ./lib/lib_get_print

FILES			:= ./src/about_already_sorted.c \
				./src/list/about_add_content_node.c\
				./src/list/about_add_node_front.c\
				./src/list/about_indexing_the_list.c\
				./src/list/about_initializing_list.c\
				./src/rules/about_push.c\
				./src/rules/about_reverse_rotate.c\
				./src/rules/about_rotate.c\
				./src/rules/about_swap.c\
				./src/utils/about_cpy_matrix_to_list.c\
				./src/utils/about_error.c\
				./src/utils/about_free_memory.c\
				./src/utils/about_highest_lowest_value.c\
				./src/utils/about_repeated_numbers.c\
				./src/utils/about_struct_rules.c\
				./src/utils/about_valid_args.c\
				./src/main.c\
				FUNCOES_TEMPORARIAS_DEBUG.c


INCLUDE			:= -I ./include -I ./lib/lib_get_print/includes
CMD_CLEAN		:= rm -Rf
CMD_FCLEAN		:= rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(FILES)

$(NAME):
	@$(CC) $(FILES) $(LIBFT) $(INCLUDE) -o $(NAME)

$(LIBFT): libft

libft:
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory

clean:
	@$(CMD_CLEAN) $(NAME)

fclean: clean libft_clean
	@$(CMD_CLEAN) $(NAME)

re: clean, fclean, libft_re, pipex_re, $(LIBFT)