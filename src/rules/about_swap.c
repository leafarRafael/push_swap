/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:10:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/15 13:46:17 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap_complex(t_cdlst *list);
static void	ft_simple_swap(t_cdlst *list);

void	ft_swap(t_cdlst *list, char *msg)
{
	if (!list)
		return ;
	if (list->size <= 1)
		return ;
	if (list->size == 2)
		ft_simple_swap(list);
	else
		ft_swap_complex(list);
	if (msg)
		ft_printf("%s\n", msg);
}

void	ft_swap_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg)
{
	if (!list_a->head || list_a->head->next == list_a->head)
		return ;
	if (!list_b->head || list_b->head->next == list_b->head)
		return ;
	ft_swap(list_a, NULL);
	ft_swap(list_b, NULL);
	ft_printf("%s\n", msg);
}

static void	ft_swap_complex(t_cdlst *list)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;
	t_node	*last;

	first = list->head;
	second = list->head->next;
	third = list->head->next->next;
	last = list->last;
	first->next = third;
	third->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = last;
	last->next = second;
	list->head = second;
}

static void	ft_simple_swap(t_cdlst *list)
{
	t_node	*first;

	first = list->head;
	list->head = list->last;
	list->last = first;
}
