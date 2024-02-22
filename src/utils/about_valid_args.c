/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_valid_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:32:39 by rbutzke           #+#    #+#             */
/*   Updated: 2024/02/21 17:41:19 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_valid(char c)
{
    return ((c >= '0' && c <= '9') || c == '+' || c == '-');
}

void	ft_valid_arg(int argc, char *argv[])
{
	int	i;
	int	x;

	i = 1;
	if (argc == 1 || argc == 2)
	{
		exit(1);
	}
	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
		{
			if (!ft_valid(argv[i][x]))
				ft_error("error", NULL);
			x++;
		}
		i++;
	}	
}
