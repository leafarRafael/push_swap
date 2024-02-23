/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_initializing_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 10:05:05 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/23 14:02:51 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cdlst	*ft_init_list(void)
{
	t_cdlst	*new_list;

	new_list = malloc(sizeof(t_cdlst));
	new_list->head = NULL;
	new_list->last = NULL;
	new_list->size = 0;
	return (new_list);
}