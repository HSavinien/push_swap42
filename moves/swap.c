/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:06:34 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/04 00:02:05 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../push_swap.h>

void	do_swap(t_stack *src)
{
	if(get_stack_len(src) < 2)
		return;
	ft_swap_ptr()

}

void	mv_sa(t_stack *sa, t_stack *sb)
{
	do_swap(sa);
	printf("sa\n");
	(void) *sb;
}

void	mv_sb(t_stack *sa, t_stack *sb)
{
	do_swap(sa);
	printf("sa\n");
	(void) *sb;
}

void	mv_ss(t_stack *sa, t_stack *sb)
{
	do_swap(sa);
	do_swap(sb);
	printf("ss\n");
}
