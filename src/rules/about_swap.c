/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:10:49 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 11:57:02 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap(t_cdlst *list, char *msg)
{
    t_node  *temp_node;
    
    if (!list->head || (list->head->next == list->head))
        return ;
    temp_node = list->head;
    list->head->next->prev = list->last;
    list->last->next = list->head->next;
    list->head = list->head->next;  
    temp_node->next = list->head->next;
    temp_node->prev = list->head;
    list->head->next->next->prev = temp_node;
    list->head->next = temp_node;
    if (msg)
        ft_printf("%s\n", msg);
}

void    ft_swap_stacks(t_cdlst *list_a, t_cdlst *list_b, char *msg)
{
    if (!list_a->head || list_a->head->next == list_a->head)
        return ;
    if(!list_b->head || list_b->head->next == list_b->head)
        return ;
    ft_swap(list_a, NULL);
    ft_swap(list_b, NULL);
    ft_printf("%s\n", msg);
}
