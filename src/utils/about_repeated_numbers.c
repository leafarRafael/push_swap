/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_repeated_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:00:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 09:41:21 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_repeated_numbers(t_cdlst *s_a)
{
	t_node	*current;
	t_node	*c_temp;
	int		i;

	if (!s_a)
		return (-1);
	if (s_a->head->content == s_a->head->next->content)
		return (-1);
	i = 0;
	current = s_a->head;
	c_temp = s_a->head->next;
	while (i != s_a->size)
	{
		while (c_temp != s_a->head)
		{
			if (current->content == c_temp->content)
				return (-1);
			c_temp = c_temp->next;
		}
		current = current->next;
		c_temp = current->next;
		i++;
	}
	return (0);
}