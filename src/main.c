/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 09:42:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/23 16:10:32 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_ask(t_var *var, t_cdlst *list)
{
	t_node *current;
	t_node *next;
	long	small;

	var->smaller = list->head->content;
	var->bigger = list->head->content;
	next = list->head->next;
	current = next;
	while (current != list->head)
	{
		if (current->content < var->smaller)
			var->smaller = current->content;
		if (current->content > var->bigger)
			var->bigger = current->content;
		current = next;
		next = next->next;
	}
}

void	ft_bubble_sort(t_var *var, t_cdlst *s_a, t_cdlst *s_b)
{
	t_rules *rules;
	int		i;

	i = 0;
	rules = ft_init_get_rules();

	while (s_a->size != 0)
	{
		if (s_a->head->content == var->smaller)
		{
			rules->pb(s_b, s_a, PB);
			ft_ask(var, s_a);
		}
		if (s_a->head->content > s_a->head->next->content)
			rules->sa(s_a, SA);
		else if (s_a->head->content > s_a->last->content)
			rules->ra(s_a, RA);
		else
			rules->rra(s_a, RRA);
	}
	while (s_b->size != 0)
		rules->pb(s_a, s_b, PA);
}

int main(int argc, char *argv[])
{
	t_cdlst	*s_a;
	t_cdlst	*s_b;
	t_var	*var;
	t_rules *rules;

	rules = ft_init_get_rules();
	ft_valid_arg(argc, argv);
	var = malloc(sizeof(t_var));
	if (!var)
		ft_error("error", NULL);
	var->matrix = ft_cpy_matrix(argv, argc);
	s_a = ft_init_list();
	s_b = ft_init_list();
	ft_cpy_matrix_to_list(s_a, s_b, var);
	ft_bubble_sort(var, s_a, s_b);
	ft_free_list(s_a);
	ft_free_list(s_b);
	free(var);
	return (1);
}