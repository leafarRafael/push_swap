/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_highest_lowest_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:55:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/02 12:58:23 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_largest_smallest_index(t_var *var, t_cdlst *list)
{
	var->i = 0;
	var->node = list->head;
	var->smaller = list->head->index;
	var->largest = var->smaller;
	while (var->i != list->size)
	{
		if (var->node->index <= var->smaller)
			var->smaller = var->node->index;
		if (var->node->index >= var->largest)
			var->largest = var->node->index;
		var->node = var->node->next;
		var->i++;
	}
}