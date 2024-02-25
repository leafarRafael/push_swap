/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_sorting_small.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 09:46:28 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/25 15:21:50 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_short_list(t_cdlst *list)
{
	t_rules	*rules;

	rules = ft_init_get_rules();
	if (list->size == 2)
		rules->sa(list, SA);
	if (list->size == 3)
	{
		while (ft_already_sorted(list) != 0)
		{
			if (list->head->index > list->head->next->index
				&& list->head->index > list->last->index)
				rules->ra(list, RA);
			if (list->head->next->index > list->head->index
				&& list->head->next->index > list->last->index)
				rules->rra(list, RRA);
			if (list->head->index > list->head->next->index)
				rules->sa(list, SA);
		}
	}
}