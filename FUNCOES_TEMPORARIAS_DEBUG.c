/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FUNCOES_TEMPORARIAS_DEBUG.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:43:20 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/22 11:12:02 by rbutzke          ###   ########.fr       */
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