/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:27 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/23 15:50:48 by rbutzke          ###   ########.fr       */
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
	char	**matrix;
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
void    ft_cpy_matrix_to_list(t_cdlst *stack_a, t_cdlst *stack_b, t_var *var);

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
void	print_matrix(char **matrix);

#endif

