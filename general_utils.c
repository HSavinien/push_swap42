/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:01:58 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 03:37:18 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*a = *a - *b;
	*b = *a - *b;
}

void	ft_swap_ptr(void **a, void **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}
