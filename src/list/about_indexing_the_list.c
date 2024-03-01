/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_indexing_the_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/01 14:06:22 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assigned_index_node(t_var *var)
{
	int	index;

	var->n_a = var->s_a->head;
	var->node = var->s_a->head;
	var->i = 0;
	var->i_a = 0;
	while (var->i_a != var->s_a->size)
	{
		var->i = 0;
		index = 1;
		while (var->i != var->s_a->size)
		{
			if (var->n_a->content > var->node->content)
				index++;
			var->node = var->node->next;
			var->i++;
		}
		var->n_a->index = index;
		var->i_a++;
		var->n_a = var->n_a->next;
	}
	var->larg_i = var->s_a->size;
	ft_largest_smallest_index_content(var, var->s_a);
}

void	ft_largest_smallest_index_content(t_var *var, t_cdlst *list)
{
	var->half_i = 1;
	var->node = list->head;
	var->smaller = 0;
	var->smal_i = 1;
	var->larg_i = 0;
	var->i = 0;
	while (var->i != list->size)
	{
		if (var->node->index == var->smal_i)
			var->smaller = var->node->content;
		if (var->node->index >= var->larg_i)
		{
			var->larg_i = var->node->index;
			var->bigger = var->node->content;
		}
		var->node = var->node->next;
		var->i++;
	}
	var->half_i = var->larg_i / 2;
}