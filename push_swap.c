/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:22:22 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/10 17:11:11 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;

	if (ac < 2)
		return (0);
	sa = read_args(ac, av);
	sb = NULL;
//	system("leaks push_swap");
//	show_stack(sa);//debug
	do_sorting(sa, sb);
}

/*
base	: 1 2 4 3 0 ;
rra		: 0 1 2 4 3 ;
pb		: 1 2 4 3 ; 0
pb		: 2 4 3 ; 1 0
rra		: 3 2 4 ; 1 0
sa		: 2 3 4 ; 1 0
pa		: 1 2 3 4 ; 0
pa		: 0 1 2 3 4 ;


base	: 2 4 1 3 0 ;
rra		: 0 2 4 1 3 ;
pb		: 2 4 1 3 ; 0
rra		: 3 2 4 1 ; 0
rra		: 1 3 2 4 ; 0
pb		: 3 2 4 ; 1 0
sa		: 2 3 4 ; 1 0
pa		: 1 2 3 4 ; 0
pa		: 0 1 2 3 4 ;
*/
