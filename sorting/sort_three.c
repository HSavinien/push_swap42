/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:24:01 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/08 17:14:41 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*sort_three(t_stack *sa, t_stack *sb)
{
	int	lst[3];

	lst[0] = *sa->content;
	lst[1] = *sa->next->content;
	lst[2] = *sa->next->next->content;
	if (lst[0] < lst[1] && lst[1] < lst[2])
		return (sa);
	else if (lst[0] < lst[2] && lst[2] < lst[1])
	{
		mv_rra(&sa, &sb);
		mv_sa(&sa, &sb);
	}
	else if (lst[1] < lst[0] && lst[0] < lst[2])
		mv_sa(&sa, &sb);
	else if (lst[2] < lst[0] && lst[0] < lst[1])
		mv_rra(&sa, &sb);
	else if (lst[1] < lst[2] && lst[2] < lst[0])
		mv_ra(&sa, &sb);
	else if (lst[2] < lst[1] && lst[1] < lst[0])
	{
		mv_ra(&sa, &sb);
		mv_sa(&sa, &sb);
	}
	if (!sb)
		destroy_main_stack(sa);
	return (sa);
}
