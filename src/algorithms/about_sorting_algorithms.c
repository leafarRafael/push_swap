/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_sorting_algorithms.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:02:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 17:20:40 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack_b_healper(t_var *var, int *half_size);

void	ft_sort(t_var *var)
{
	ft_init_stack_b(var);
	ft_add_target_pos_list(var);
	ft_calculate_cost(var);
	ft_find_best_move(var);
	printf("lista A\n");
	ft_print_list_all_atribute(var->s_a);
	printf("lista B\n");
	ft_print_list_all_atribute(var->s_b);
}

void	ft_init_stack_b(t_var *var)
{
	int	half_size;

	ft_short_list(var->s_a, var);
	half_size = var->half_i;
	while (var->s_a->size != 3)
		ft_init_stack_b_healper(var, &half_size);
	ft_short_list(var->s_a, var);
}

static void	ft_init_stack_b_healper(t_var *var, int *half_size)
{
	if (var->s_a->head->index > (*half_size))
	{
		if (var->s_a->head->next->index < (*half_size))
			var->rules->sa(var->s_a, SA);
		else if (var->s_a->last->index < (*half_size))
			var->rules->rra(var->s_a, RRA);
		else if (var->s_a->last->prev->index < (*half_size))
		{
			var->rules->rra(var->s_a, RRA);
			var->rules->rra(var->s_a, RRA);
		}
		else if (var->s_a->head->next->index < (*half_size))
		{
			var->rules->ra(var->s_a, RA);
			var->rules->sa(var->s_a, SA);
		}
		else
			var->rules->ra(var->s_a, RA);
	}
	else
	{
		var->rules->pb(var->s_b, var->s_a, PB);
		(*half_size)++;
	}
}