/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_struct_rules.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbutzke <rbutzke@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:57:08 by rbutzke           #+#    #+#             */
/*   Updated: 2024/03/04 10:11:13 by rbutzke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rules	*ft_init_get_rules(void)
{
	static t_rules rules;

	rules.sa = ft_swap;
	rules.sb = ft_swap;
	rules.ss = ft_swap_stacks;
	rules.pa = ft_push;
	rules.pb = ft_push;
	rules.ra = ft_rotate;
	rules.rb = ft_rotate;
 	rules.rr = ft_rotate_stacks;
	rules.rra = ft_reverse_rotate;
	rules.rrb = ft_reverse_rotate;
	rules.rrr = ft_rev_rotate_stacks;
	return (&rules);
}