/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_cost_to_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:12:55 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 15:02:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_calculate_cost(t_var *var)
{
	int	size_a;
	int	size_b;

	var->n_a = var->s_a->head;
	var->n_b = var->s_b->head;
	var->i_b = 0;
	size_a = var->s_a->size;
	size_b = var->s_b->size ;
	while (var->i_b != var->s_b->size)
	{
		var->n_b->cost_b = var->n_b->pos;
		var->n_b->cost_a = var->n_b->target_pos;
		if (var->n_b->pos > size_b /2)
			var->n_b->cost_b = (size_b - var->n_b->pos) *-1;
		if (var->n_b->target_pos > size_a /2)
			var->n_b->cost_a = (size_a - var->n_b->target_pos) *-1;
		var->n_b = var->n_b->next;
		var->i_b++;
	}
}