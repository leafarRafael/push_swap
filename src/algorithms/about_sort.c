/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:38:10 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 14:55:31 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_finishes_sorting(t_var *var, t_cdlst *s_a);

void	ft_sort(t_var *var)
{
	ft_sort_three(var);
	ft_stack_b_init(var);
	while (var->s_b->size != 0)
	{
		ft_find_target_position(var->s_a, var->s_b);
		ft_calculate_cost_move(var->s_a, var->s_b);
		ft_find_lowest_cost_and_move(var, var->s_a, var->s_b);
	}
	if (ft_already_sorted(var->s_a) != 0)
	{
		if (ft_finishes_sorting(var, var->s_a) != 0)
			while (ft_already_sorted(var->s_a) != 0)
				var->rules->rra(var->s_a, RRA);
		else
			while (ft_already_sorted(var->s_a) != 0)
				var->rules->ra(var->s_a, RA);
	}
}

static int	ft_finishes_sorting(t_var *var, t_cdlst *s_a)
{
	t_sv	v;

	v.node_a = s_a->head;
	v.i = 0;
	ft_find_largest_smallest_index(var, s_a);
	while (v.i != s_a->size)
	{
		if (v.node_a->index == var->smaller)
			break ;
		v.node_a = v.node_a->next;
		v.i++;
	}
	if (v.i > s_a->size / 2)
		return (-1);
	return (0);
}
