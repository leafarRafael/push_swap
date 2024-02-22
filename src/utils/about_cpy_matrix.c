/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_cpy_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:23:47 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 14:11:03 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_cpy_matrix(char *argv[], int argc)
{
	char	**new_matrix;
	int		index_argc;
    int     index;

    index_argc = 1;
    index = 0;
	new_matrix = ft_calloc(sizeof(char*), argc);
	if (!new_matrix)
		return (NULL);
	while (argv[index_argc])
	{
		new_matrix[index] = ft_strdup(argv[index_argc]);
		if (!new_matrix[index])
			ft_free_matrix(new_matrix);
        index_argc++;
        index++;
	}
	return (new_matrix);
}
