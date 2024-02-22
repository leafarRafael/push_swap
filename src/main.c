/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 17:57:36 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_simple_sort(t_var *var, t_cdlst *s_a, t_cdlst *s_b)
{
	t_node	*current;
	t_node	*next;
	t_node	*last;
	t_rules *rules;

	rules = ft_init_get_rules();

	current = s_a->head;
	next = s_a->head->next;
	while(s_a->size != 0)
	{
		if (current->content > next->content)
			rules->sa(s_a, "sa");
		if (current->content > s_a->last->content)
			rules->rra(s_a, "rra");
		rules->pa(s_b, s_a, "pa");
		current = next;
		next = next->next;
		last = s_a->last;
	}
}

int main(int argc, char *argv[])
{
	t_cdlst	*s_a;
	t_cdlst	*s_b;
	t_var	*var;

	ft_valid_arg(argc, argv);
	var = malloc(sizeof(t_var));
	if (!var)
		ft_error("error", NULL);
	var->matrix = ft_cpy_matrix(argv, argc);
	s_a = ft_init_list();
	s_b = ft_init_list();
	ft_cpy_matrix_to_list(s_a, s_b, var);
	ft_simple_sort(var, s_a, s_b);

	ft_print_list(s_b);
	printf("\nhead = [%ld]\n", s_b->head->content);
	printf("\nlast = [%ld]\n", s_b->last->content);

	printf("\nsize s_a = [%d]\n", s_a->size);
	printf("size s_b = [%d]\n", s_b->size);
	ft_free_list(s_a);
	ft_free_list(s_b);
	free(var);
	return (1);
}