/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_already_sorted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:12:37 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/04 10:07:45 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_already_sorted(t_cdlst *s_a)
{
	t_sv v;

	v.node_a = s_a->head;
	v.node = s_a->head->next;
	v.i = 0;
	if (!s_a)
		return (-1);
	while (v.i != s_a->size)
	{
		if (v.node_a->content > v.node->content)
			return (-1);
		v.node_a = v.node;
		v.node = v.node->next;
		if (v.node == s_a->head)
			return (0);
		v.i++;
	}
	return (0);
}