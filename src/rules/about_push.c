/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:36:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 15:13:27 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_cdlst *to_stack, t_cdlst *from_stack, char *msg)
{
	t_node	*remove_add;
	t_node	*second;

	if (!to_stack || !from_stack)
		ft_error("error\n", NULL);
	if (from_stack->size == 0)
		return ;
	remove_add = from_stack->head;
	second = from_stack->head->next;
	second->prev = from_stack->last;
	from_stack->last->next = second;
	from_stack->head = second;
	from_stack->size--;
	ft_include_node(to_stack, remove_add);
	ft_printf("%s\n", msg);
}
