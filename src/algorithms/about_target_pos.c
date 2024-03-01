/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_target_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:37:24 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 16:59:30 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_target(t_var *var, int index_b, int max_index)
{
	var->n_a = var->s_a->head;
	var->i_a = 0;
	while (var->i_a != var->s_a->size)
	{
		if (var->n_a->index > index_b && var->n_a->index < max_index)
		{
			max_index = var->n_a->index;
			var->t_pos = var->n_a->pos;
		}
		var->n_a = var->n_a->next;
		var->i_a++;
	}
	if (max_index != var->max_index)
		return (var->t_pos);
	while (var->i_a != 0)
	{
		if (var->n_a->index < max_index)
		{
			max_index = var->n_a->index;
			var->t_pos = var->n_a->pos;
		}
		var->i_a--;
		var->n_a = var->n_a->prev;
	}
	return (var->t_pos);
}

void    ft_add_target_pos_list(t_var *var)
{
	var->n_b = var->s_b->head;
	ft_add_position_list(var);
	var->i_b = 0;
	var->t_pos = 0;
	var->max_index = var->larg_i +2;
	while (var->i_b != var->s_b->size)
	{
		var->n_b->target_pos = ft_find_target(var, var->n_b->index, var->max_index);
		var->n_b = var->n_b->next;
		var->i_b++;
	}
}
