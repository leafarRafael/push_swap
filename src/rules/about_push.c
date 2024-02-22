/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:36:16 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 18:03:48 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_push(t_cdlst *to_stack, t_cdlst *from_stack, char *msg)
{
    t_node *temp;

    if (!to_stack || !from_stack)
        ft_error("error\n", NULL);
	if(from_stack->size == 0)
		return ;
	temp = from_stack->head;
	from_stack->head = from_stack->head->next;
	from_stack->head->prev = from_stack->last;
	from_stack->last->next = from_stack->head;
	from_stack->size--;
	ft_include_node(to_stack, temp);
	ft_printf("%s\n", msg);
}
