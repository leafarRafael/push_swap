/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:14:23 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 11:56:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_cdlst *list, char *msg)
{
	t_node	*first;

	if (!list || !list->head)
		return ;
	first = list->head;
	list->head = list->head->next;
	list->last = first;
	if (msg)
		ft_printf("%s\n", msg);
}

void    ft_rotate_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg)
{
	if (!list_a || list_a->head == list_a->head->next)
		return ;
	if (!list_b || list_b->head == list_b->head->next)
		return ;
	ft_rotate(list_a, NULL);
	ft_rotate(list_b, NULL);
	ft_printf("%s\n", msg);	
}