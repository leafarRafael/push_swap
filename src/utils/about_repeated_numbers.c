/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_repeated_numbers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 09:00:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/04 10:04:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_repeated_numbers(t_cdlst *s_a)
{
	t_sv v;

	if (!s_a)
		return (-1);
	if (s_a->head->content == s_a->head->next->content)
		return (-1);
	v.i = 0;
	v.node_a = s_a->head;
	v.node = s_a->head->next;
	while (v.i != s_a->size)
	{
		while (v.node != s_a->head)
		{
			if (v.node_a->content == v.node->content)
				return (-1);
			v.node = v.node->next;
		}
		v.node_a = v.node_a->next;
		v.node = v.node_a->next;
		v.i++;
	}
	return (0);
}