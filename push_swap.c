/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:22:22 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/05 20:17:30 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*build_stack_b(size_t len)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (len --)
		stack_b = stack_add_front(stack_b, 0);
	return (stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;

	if (ac < 2)
		return (0);
	sa = read_args(ac, av);
	sb = build_stack_b(get_stack_len(sa));
	show_stack(sa);//debug
	show_stack(sb);//debug
	test_moves(sa, sb);//debug
}
