/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_highest_lowest_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:55:44 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 09:57:53 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_search_highest_lowest(t_var *var, t_cdlst *list)
{
	t_node *current;
	t_node *next;
	long	small;

	var->smaller = list->head->content;
	var->bigger = list->head->content;
	next = list->head->next;
	current = next;
	while (current != list->head)
	{
		if (current->content < var->smaller)
			var->smaller = current->content;
		if (current->content > var->bigger)
			var->bigger = current->content;
		current = next;
		next = next->next;
	}
}