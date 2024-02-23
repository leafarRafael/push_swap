/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_add_node_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:35:50 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/23 09:39:15 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ft_add_1st_node(t_cdlst *list, t_node *new_node);
static void ft_add_2st_node(t_cdlst *list, t_node *new_node);
static void	ft_add_onwards(t_cdlst *list, t_node *new_node);

void	ft_include_node(t_cdlst *list, t_node  *new_node)
{
	if (!new_node || !list)
		ft_error("error\n", list);
	if (list->size == 0)
		ft_add_1st_node(list, new_node);
	else if (list->size == 1)
		ft_add_2st_node(list, new_node);
	else if (list->size > 1)
		ft_add_onwards(list, new_node);
	list->size++;
}

static void ft_add_1st_node(t_cdlst *list, t_node *new_node)
{
	new_node->next = new_node;
	new_node->prev = new_node;
	list->head = new_node;
	list->last = new_node;
}

static void ft_add_2st_node(t_cdlst *list, t_node *new_node)
{
	t_node	*temp;

	temp = list->head;
	temp->next = new_node;
	temp->prev = new_node;
	new_node->next = temp;
	new_node->prev = temp;
	list->head = new_node;
	list->last = temp;
}

static void	ft_add_onwards(t_cdlst *list, t_node *new_node)
{
	t_node	*temp;

	temp = list->head;
	new_node->next = temp;
	new_node->prev = list->last;
	temp->prev = new_node;
	list->last->next = new_node;
	list->head = new_node;
}