NAME			:= push_swap
CFLAGS			:= -Wextra -Wall -Werror
CC				:= cc
LIBFT			:= ./lib/lib_get_print/libft.a
PATH_MAKE_LIB	:= ./lib/lib_get_print

FILES			:= ./src/about_already_sorted.c\
				./src/algorithms/about_sort.c\
				./src/algorithms/about_sorting_three.c\
				./src/algorithms/about_stack_b_initialization.c\
				./src/algorithms/about_position_node.c\
				./src/algorithms/about_target_position.c\
				./src/algorithms/about_cost_move.c\
				./src/algorithms/about_lowest_cost_move.c\
				./src/algorithms/about_make_move.c\
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
				./src/utils/about_highest_lowest_index.c\
				./src/utils/about_repeated_numbers.c\
				./src/utils/about_struct_rules.c\
				./src/utils/about_valid_args.c\
				./src/main.c\

INCLUDE			:= -I ./include -I ./lib/lib_get_print/includes
CMD_CLEAN		:= rm -rf

all: $(NAME)

$(NAME): $(LIBFT) $(FILES)

$(NAME):
	@$(CC) $(CFLAGS) $(FILES) $(LIBFT) $(INCLUDE) -o $(NAME)

$(LIBFT): libft

libft:
	@$(MAKE) -C $(PATH_MAKE_LIB) --no-print-directory

libft_clean:
	@$(MAKE) -C $(PATH_MAKE_LIB) clean --no-print-directory

libft_fclean:
	@$(MAKE) -C $(PATH_MAKE_LIB) fclean --no-print-directory

libft_re:
	@$(MAKE) -C $(PATH_MAKE_LIB) re --no-print-directory

clean:
	@$(CMD_CLEAN) $(NAME)

fclean: clean libft_fclean
	@$(CMD_CLEAN) $(NAME)

re: fclean libft_fclean all