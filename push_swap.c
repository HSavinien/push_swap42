/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:22:22 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/20 20:46:44 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_A;
	t_stack	*stack_B;
	if (ac < 2)
		return(0);
	stack_A = read_args(ac, av);
	stack_B = malloc(sizeof (t_stack));
	printf("%d element in stack\n", show_stack(stack_A));//debug
	if(check_double(stack_A))
		error("found duplicates values");
	

}
