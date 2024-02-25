/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_cpy_matrix_to_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42so.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:56:12 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/25 14:40:10 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_cpy_matrix_to_list(t_var *var, char  *matrix[])
{
    int     i;
    long    content;

    i = 1;
    content = 0;
    var->bigger = 0;
    var->smaller = ft_atol(matrix[1]);
    while (matrix[i])
    {
        content = ft_atol(matrix[i]);
        if (content >= var->bigger)
            var->bigger = content;
        if (content < var->smaller)
            var->smaller = content;
        ft_creating_node(var->s_a, content);
        i++;
    }
}