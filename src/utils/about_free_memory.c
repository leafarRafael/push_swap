/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_free_memory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:53:58 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/06 15:19:56 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
	matrix = NULL;
}

void	ft_free_list(t_cdlst *list)
{
	t_node	*node_current;
	t_node	*next_node;

	if (list->size == 0)
	{
		free(list);
		return ;
	}
	if (list->size == 1)
	{
		free(list->head);
		free(list);
		return ;
	}
	node_current = list->head;
	while (node_current)
	{
		next_node = node_current->next;
		free(node_current);
		node_current = next_node;
		if (next_node == list->head)
			break ;
	}
	free(list);
}
