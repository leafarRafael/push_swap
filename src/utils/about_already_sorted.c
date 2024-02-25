/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_already_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:12:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 10:27:01 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_already_sorted(t_cdlst *s_a)
{
	t_node	*current;
	t_node	*next;
	int		i;

	if (!s_a)
		return (-1);
	i = 0;
	current = s_a->head;
	next = s_a->head->next;
	while (i != s_a->size)
	{
		if (current->content > next->content)
			return (-1);
		current = next;
		next = next->next;
		if (next == s_a->head)
			return (0);
		i++;
	}
	return (0);
}