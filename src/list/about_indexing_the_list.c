/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_indexing_the_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/02 12:55:10 by rbutzke          ###   ########.fr       */
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
}
