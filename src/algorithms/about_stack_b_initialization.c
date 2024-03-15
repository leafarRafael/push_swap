/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_stack_b_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 07:50:18 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/13 15:40:34 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_b_init(t_var *var)
{
	t_sv	v;

	if (var->s_a->size == 5)
	{
		var->rules->pb(var->s_b, var->s_a, PB);
		var->rules->pb(var->s_b, var->s_a, PB);
	}
	if (var->s_a->size < 300)
		v.size = var->s_a->size / 2;
	if (var->s_a->size >= 300)
		v.size = var->s_a->size / 10;
	while (var->s_a->size != 3)
	{
		if (var->s_a->head->index < v.size)
		{
			var->rules->pb(var->s_b, var->s_a, PB);
			v.size++;
		}
		else
			var->rules->ra(var->s_a, RA);
	}
	ft_sort_three(var);
}
