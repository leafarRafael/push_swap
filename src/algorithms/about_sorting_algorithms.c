/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_sorting_algorithms.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:02:00 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 17:47:16 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bubble_sort(t_var *var, t_cdlst *s_a, t_cdlst *s_b)
{
	t_rules *rules;
	int		i;

	ft_short_list(var);
	i = 0;
	rules = ft_init_get_rules();
	while (s_a->size != 0)
	{
		if (s_a->head->content == var->smaller)
		{
			rules->pb(s_b, s_a, PB);
			ft_search_highest_lowest(var, s_a);
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

void	ft_short_list(t_var *var)
{
	t_rules	*rules;

	rules = ft_init_get_rules();
	if (var->s_a->size <= 3)
	{
		if (var->s_a->size == 2)
			rules->sa(var->s_a, SA);
		while (ft_already_sorted(var->s_a))
		{
			if (var->s_a->head->index < var->s_a->head->next->index
				&&var->s_a->head->index > var->s_a->last->index)
				rules->rra(var->s_a, RRA);
			if (var->s_a->head->index > var->s_a->last->index)
				rules->ra(var->s_a, RA);
			if (var->s_a->head->index > var->s_a->head->next->content)
				rules->sa(var->s_a, SA);
			if (var->s_a->head->next->index > var->s_a->last->index
				&& var->s_a->head->next->index > var->s_a->head->index)
			{
				rules->rra(var->s_a, RRA);
				rules->sa(var->s_a, SA);
			}
		}
		ft_print_list(var->s_a);
		ft_error_cpy_m_l(NULL, var->s_a, var->s_b, var);
	}
}

void	ft_sort(t_var *var)
{
	t_rules	*rules;
	t_node	*node;

	rules->pb(var->s_b, var->s_a, PB);
	rules->pb(var->s_b, var->s_a, PB);
	ft_search_highest_lowest(var, var->s_a);
	while(var->s_a->size != 0)
	{
		
	}
}