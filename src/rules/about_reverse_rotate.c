/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_reverse_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 11:41:51 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 08:57:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_cdlst *list, char *msg)
{
	t_node	*temp;

	if (!list || !list->head)
		return ;
	temp = list->last;
	list->head = temp;
	list->last = temp->prev;
	if (msg)
		ft_printf("%s\n", msg);
}

void    ft_rev_rotate_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg)
{
	if (!list_a || list_a->head == list_a->head->next)
		return ;
	if (!list_b || list_b->head == list_b->head->next)
		return ;
	ft_reverse_rotate(list_a, NULL);
	ft_reverse_rotate(list_b, NULL);
	ft_printf("%s\n", msg);	
}