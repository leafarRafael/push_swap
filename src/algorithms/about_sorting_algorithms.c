/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_sorting_algorithms.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:02:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/28 18:08:28 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack_b_healper(t_var *var, int *half_size, t_rules *rules);

void	ft_sort(t_var *var)
{
	t_rules	*rules;
	t_node	*node;

	rules = ft_init_get_rules();
	ft_init_stack_b(var);
	ft_short_list(var->s_a);
	get_target_position(var->s_a, var->s_b, var);
	ft_add_target_pos_list(var);

	printf("lista a\n");
	ft_print_list_all_atribute(var->s_a);
	printf("lista b\n");
	ft_print_list_all_atribute(var->s_b);
}

void	ft_init_stack_b(t_var *var)
{
	t_rules	*rules;
	int		half_size;

	rules = ft_init_get_rules();
	half_size = var->s_a->size / 2;
	while (var->s_a->size != 3)
		ft_init_stack_b_healper(var, &half_size, rules);
}

static void	ft_init_stack_b_healper(t_var *var, int *half_size, t_rules *rules)
{
	if (var->s_a->head->index > (*half_size))
	{
		if (var->s_a->head->next->index < (*half_size))
			rules->sa(var->s_a, SA);
		else if (var->s_a->last->index < (*half_size))
			rules->rra(var->s_a, RRA);
		else if (var->s_a->last->prev->index < (*half_size))
		{
			rules->rra(var->s_a, RRA);
			rules->rra(var->s_a, RRA);
		}
		else if (var->s_a->head->next->index < (*half_size))
		{
			rules->ra(var->s_a, RA);
			rules->sa(var->s_a, SA);
		}
		else
			rules->ra(var->s_a, RA);
	}
	else
	{
		rules->pb(var->s_b, var->s_a, PB);
		(*half_size)++;
	}
}