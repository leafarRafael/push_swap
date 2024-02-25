/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_indexing_the_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:05:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 13:58:24 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_assigned_index_node(t_var *var)
{
	t_node	*current;
	t_node	*c_temp;
	int		i;
	int		x;
	int		index;

	i = 0;
	index = 1;
	current = var->s_a->head;
	c_temp = var->s_a->head;
	while (i != var->s_a->size)
	{
		x = 0;
		while (x != var->s_a->size)
		{
			if (current->content > c_temp->content)
				index++;
			c_temp = c_temp->next;
			x++;
		}
		current->index = index;
		index = 1;
		current = current->next;
		c_temp = var->s_a->head;
		i++;
	}
}