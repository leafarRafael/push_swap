/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_add_content_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:28:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 15:26:08 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_add_1st_node(t_cdlst *list, t_node *new_node);
static void	ft_add_second_onwards(t_cdlst *list, t_node *new_node);

void	ft_creating_node(t_cdlst *list, long content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node || !list)
		ft_error("error\n", list);
	new_node->content = content;
	if (list->size == 0)
		ft_add_1st_node(list, new_node);
	else
		ft_add_second_onwards(list, new_node);
	list->size++;
}

static void	ft_add_1st_node(t_cdlst *list, t_node *new_node)
{
	new_node->next = new_node;
	new_node->prev = new_node;
	list->head = new_node;
	list->last = new_node;
}

static void	ft_add_second_onwards(t_cdlst *list, t_node *new_node)
{
	t_node	*temp;

	temp = list->last;
	new_node->next = list->head;
	new_node->prev = temp;
	list->head->prev = new_node;
	temp->next = new_node;
	list->last = new_node;
}
