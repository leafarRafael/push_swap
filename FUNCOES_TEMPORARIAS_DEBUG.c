/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FUNCOES_TEMPORARIAS_DEBUG.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/28 14:19:42 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_cdlst *list)
{
	t_node *temp;

	if (!list)
		return ;
	if (!list || list->size == 0)
		return ;
	if (list->size == 1)
	{
		printf("[%ld]\n", list->head->content);
		return ;
	}
	temp = list->head;
	printf("[%ld]\n", temp->content);
	temp = list->head->next;
	while (temp != list->head)
	{
		printf("[%ld]\n", temp->content);
		temp = temp->next;
	}
}


void	ft_print_list_index(t_cdlst *list)
{
	t_node *temp;

	if (!list)
		return ;
	if (!list || list->size == 0)
		return ;
	if (list->size == 1)
	{
		printf("[%d]\n", list->head->index);
		return ;
	}
	temp = list->head;
	printf("[%d]\n", temp->index);
	temp = list->head->next;
	while (temp != list->head)
	{
		printf("[%d]\n", temp->index);
		temp = temp->next;
	}
}

void	print_matrix(char **matrix)
{
	int i;

	i = 0;
	while(matrix[i])
	{
		ft_printf("%s\n", matrix[i]);
		i++;
	}
}

void	ft_print_list_all_atribute(t_cdlst *list)
{
	t_node *temp;

	if (!list)
		return ;
	if (!list || list->size == 0)
		return ;
	if (list->size == 1)
	{
		if (list->head->target_pos)
			printf("target_pos-> [%d]", list->head->target_pos);
		printf("index->[%d] position->[%d]\n", list->head->index, list->head->pos);
		return ;
	}
	temp = list->head;
	printf("index->[%d] | position->[%d] | target_pos-> [%d] \n", temp->index, temp->pos, temp->target_pos);
	temp = list->head->next;
	while (temp != list->head)
	{
		printf("index->[%d] | position->[%d] | target_pos-> [%d] \n", temp->index, temp->pos, temp->target_pos);
		temp = temp->next;
	}
}