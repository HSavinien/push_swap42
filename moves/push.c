/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:54:43 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/04 22:19:03 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_push(t_stack **src, t_stack **dst)
{
	t_stack	*save;

	save = *src;
	*src = (*src)->next;
	save->next = *dst;
	*dst = save;
}

void	mv_pa(t_stack **sa, t_stack **sb)
{
	do_push(sa, sb);
	ft_printf("pa\n");
}

void	mv_pb(t_stack **sa, t_stack **sb)
{
	do_push(sb, sa);
	ft_printf("pb\n");
}
