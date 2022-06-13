/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 14:22:22 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/13 15:51:47 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;

	if (ac < 2)
		return (0);
	sa = read_args(ac, ac, av);
	sb = NULL;
	do_sorting(sa, sb);
}
