/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 17:53:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

#include <stdio.h>
#include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define PA "pa"
# define PB "pb"
# define SA "sa"
# define SB	"sb"
# define SS "ss"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_node
{
	long            content;
	struct s_node   *prev;
	struct s_node   *next;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
}           t_node;

typedef struct s_cdlst
{
	t_node  *head;
	t_node  *last;
	int     size;
}			t_cdlst;

typedef struct s_rules
{
	void	(*sa)(t_cdlst *list, char *msg);
	void	(*sb)(t_cdlst *list, char *msg);
	void	(*ss)(t_cdlst *list_a, t_cdlst *list_b, char *msg);
	void	(*pa)(t_cdlst *to_stack, t_cdlst *from_stack, char *msg);
	void	(*pb)(t_cdlst *to_stack, t_cdlst *from_stack, char *msg);
	void	(*ra)(t_cdlst *list, char *msg);
	void	(*rb)(t_cdlst *list, char *msg);
	void	(*rr)(t_cdlst *list_a, t_cdlst *list_b, char *msg);
	void	(*rra)(t_cdlst *list, char *msg);
	void	(*rrb)(t_cdlst *list, char *msg);
	void	(*rrr)(t_cdlst *list_a, t_cdlst *list_b, char *msg);
}			t_rules;

typedef struct s_var
{
	long	bigger;
	long	smaller;
	int		half_size;
	int		larg_i;
	int		smal_i;
	int		half_i;
	int		i_a;
	int		i_b;
	int		i;
	int		t_pos;
	int		max_index;
	t_node	*n_a;
	t_node	*n_b;
	t_node	*node;
	t_cdlst	*s_a;
	t_cdlst	*s_b;
	t_rules	*rules;
}			t_var;

/*
	functions utils
*/
void	ft_valid_arg(int argc, char *argv[]);
void	ft_error(char *msg, t_cdlst *list);
void	ft_error_cpy_m_l(char *msg, t_cdlst *stack_a, t_cdlst *stack_b, t_var *var);
void	ft_free_matrix(char **matrix);
void	ft_free_list(t_cdlst *list);
char	**ft_cpy_matrix(char *argv[], int argc);
t_rules	*ft_init_get_rules(void);
void    ft_cpy_matrix_to_list(t_var *var, char  *matrix[]);
int		ft_check_repeated_numbers(t_cdlst *s_a);
void	ft_search_highest_lowest(t_var *var, t_cdlst *list);
void	ft_assigned_index_node(t_var *var);
/*
	functions about algorithms
*/
int		ft_already_sorted(t_cdlst *s_a);
void    ft_add_position_list(t_var *var);
void	ft_short_list(t_cdlst *list, t_var *var);
void	ft_sort(t_var *var);
void	ft_init_stack_b(t_var *var);
void    ft_add_target_pos_list(t_var *var);
void	ft_largest_smallest_index_content(t_var *var, t_cdlst *list);
void	ft_calculate_cost(t_var *var);
void	ft_find_best_move(t_var *var);

/*
	functions about rules push_swap
*/
void    ft_swap(t_cdlst *list, char *msg);
void    ft_swap_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg);
void    ft_push(t_cdlst *to_stack, t_cdlst *from_stack, char *msg);
void	ft_rotate(t_cdlst *list, char *msg);
void    ft_rotate_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg);
void	ft_reverse_rotate(t_cdlst *list, char *msg);
void    ft_rev_rotate_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg);

/*
	functions about list creation
*/

t_cdlst	*ft_init_list(void);
void	ft_creating_node(t_cdlst *list, long content);
void	ft_include_node(t_cdlst *list, t_node  *new_node);

/*
	FUNÇÕES TEMPORARIAS
*/
void	ft_print_list(t_cdlst *list);
void	ft_print_list_index(t_cdlst *list);
void	print_matrix(char **matrix);
void	ft_print_list_all_atribute(t_cdlst *list);

#endif
