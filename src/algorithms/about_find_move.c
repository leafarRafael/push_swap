/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_find_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:09:15 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 17:22:12 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int i);

void	ft_find_best_move(t_var *var)
{
	int	max_value;
	int	cost_a;
	int	cost_b;

	var->n_b = var->s_b->head;
	var->i_b = 0;
	max_value = var->max_index;
	while (var->i_b != var->s_b->size)
	{
		if (ft_abs(var->n_b->cost_a) + ft_abs(var->n_b->cost_b) < ft_abs(max_value))
		{
			max_value = ft_abs(max_value);
			cost_a = var->n_b->cost_a;
			cost_b = var->n_b->cost_b;
		}
		var->n_b = var->n_b->next;
		var->i_b++;
	}
	//ft_make_best_move(var, &cost_a, &cost_b);
}

static int	ft_abs(int i)
{
	if (i < 0)
		return (i = -1);
	return (i);
}