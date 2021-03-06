/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:06:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 09:06:03 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	do_swap(t_stack **src)
{
	t_stack	*saves[3];

	if (get_stack_len(*src) < 2)
		return ;
	saves[0] = *src;
	saves[1] = (*src)->next;
	saves[2] = (*src)->next->next;
	*src = saves[1];
	saves[1]->next = saves[0];
	saves[0]->next = saves[2];
}

void	mv_sa(t_stack **sa, t_stack **sb)
{
	do_swap(sa);
	(void) *sb;
}

void	mv_sb(t_stack **sa, t_stack **sb)
{
	do_swap(sb);
	(void) *sa;
}

void	mv_ss(t_stack **sa, t_stack **sb)
{
	do_swap(sa);
	do_swap(sb);
}
