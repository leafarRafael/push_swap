/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_cpy_matrix_to_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:56:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/24 13:50:52 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_valid(char c)
{
    return ((c >= '0' && c <= '9') || c == '+' || c == '-');
}

void    ft_cpy_matrix_to_list(t_var *var)
{
    int     i;
    long    content;

    i = 0;
    content = 0;
    var->bigger = 0;
    var->smaller = ft_atol(var->matrix[0]);
    while (var->matrix[i])
    {
        content = ft_atol(var->matrix[i]);
        if (content >= var->bigger)
            var->bigger = content;
        if (content < var->smaller)
            var->smaller = content;
        ft_creating_node(var->s_a, content);
        i++;
    }
    ft_free_matrix(var->matrix);
    var->matrix = NULL;
}