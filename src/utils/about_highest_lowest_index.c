/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_highest_lowest_index.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:55:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/05 10:50:43 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_largest_smallest_index(t_var *var, t_cdlst *list)
{
	t_sv	v;

	v.i = 0;
	v.node = list->head;
	var->smaller = list->head->index;
	var->largest = var->smaller;
	while (v.i != list->size)
	{
		if (v.node->index <= var->smaller)
			var->smaller = v.node->index;
		if (v.node->index >= var->largest)
			var->largest = v.node->index;
		v.node = v.node->next;
		v.i++;
	}
}