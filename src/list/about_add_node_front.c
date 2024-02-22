/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_add_node_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:35:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 18:03:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_include_node(t_cdlst *list, t_node  *new_node)
{
	t_node	*node;

	node = list->head;
	if (!new_node || !list)
		ft_error("error\n", list);
	if (!node)
	{
		new_node->next = new_node;
    	new_node->prev = new_node;
		list->head = new_node;
		list->last = new_node;
	}
	else
	{
		list->head = new_node;
		new_node->next = node;
		new_node->prev = node->prev;
		node->prev->next = new_node;
		node->prev = new_node;	
	}
	list->size++;
}
