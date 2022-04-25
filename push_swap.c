/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:22:22 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/25 16:49:26 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b = NULL;

	if (ac < 2)
		return (0);
	stack_a = read_args(ac, av);
	stack_b = build_stack_b(get_stack_len(stack_a));
	show_stack(stack_a);//debug
	printf("%d\n", is_stack_sorted(stack_a));//debug
	//do_sorting(stack_a, stack_b);
}
