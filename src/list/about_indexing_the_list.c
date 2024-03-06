/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_indexing_the_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 15:08:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assigned_index_node(t_var *var)
{
	t_sv	v;

	v.node_a = var->s_a->head;
	v.node = var->s_a->head;
	v.i = 0;
	v.x = 0;
	while (v.i != var->s_a->size)
	{
		v.x = 0;
		v.index = 1;
		while (v.x != var->s_a->size)
		{
			if (v.node_a->content > v.node->content)
				v.index++;
			v.node = v.node->next;
			v.x++;
		}
		v.node_a->index = v.index;
		v.i++;
		v.node_a = v.node_a->next;
	}
}
