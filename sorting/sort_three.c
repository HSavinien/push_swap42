/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:24:01 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/09 22:21:03 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
t_stack	*sort_three(t_stack *sa, t_stack *sb)
{
	int	lst[3];

	lst[0] = *sa->content;
	lst[1] = *sa->next->content;
	lst[2] = *sa->next->next->content;
	if (lst[0] > lst[2] > lst[1])
	{
		printf("debug : case 3-1-2\n");//debug
		mv_ra(&sa, &sb);
		show_stack(sa);//debug
		return (sa);
	}
	if (lst[0] < lst[2] < lst[1])
	{
		printf("debug : case 1-3-2\n");//debug
		mv_rra(&sa, &sb);
		mv_sa(&sa, &sb);
	}
	if (lst[0] > lst[1])
	{
		printf("debug : case 2-1-?\n");//debug
		mv_sa(&sa, &sb);
		ft_swap(&lst[0], &lst[1]);
	}
	else if (lst[2] < lst[0] < lst[1]) {
		mv_rra(&sa, &sb); 
		printf("debug : case 2-3-1\n");//debug
	}
	else if (lst[1] < lst[2] < lst[0]) {
		mv_ra(&sa, &sb);
		printf("debug : case 3-1-2\n");//debug
	}
	show_stack(sa);//debug
	return (sa);
}
*/

t_stack	*sort_three(t_stack *sa, t_stack *sb)
{
	int	lst[3];

	lst[0] = *sa->content;
	lst[1] = *sa->next->content;
	lst[2] = *sa->next->next->content;
	printf("sorting lst %d %d %d\n", lst[0], lst[1], lst[2]);//debug
	if (lst[0] < lst[1] < lst[2])//case 1 2 3
		return (sa);
	else if (lst[0] < lst[2] < lst[1])//case 1 3 2
	{
		mv_rra(&sa, &sb);
		mv_sa(&sa, &sb);
	}
	else if (lst[1] < lst[0] < lst[2])//case 2 1 3
		mv_sa(&sa, &sb);
	else if (lst[1] < lst[2] < lst[0])//case 2 3 1
		mv_rra(&sa, &sb);
	else if (lst[2] < lst[0] < lst[1])//case 3 1 2
		mv_ra(&sa, &sb);
	else if (lst[2] < lst[1] < lst[0])//case 3 2 1
	{
		mv_ra(&sa, &sb);
		mv_sa(&sa, &sb);
	}
	show_stack(sa);
	return (sa);
}
