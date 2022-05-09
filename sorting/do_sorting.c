/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:31:20 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/09 21:25:08 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//analize the input and call the best algo depending on the number list. for now, it mostly discriminate between short/long array
void	do_sorting(t_stack *sa, t_stack *sb)
{
	int len;
	len = get_stack_len(sa);
	if (is_stack_sorted(sa))
		exit(ft_printf("nothing to be done. Numbers are already sorted\n"));
	else if (len == 3)
		sort_three(sa, sb);
	else if (len == 5)
		sort_five(sa, sb);
	else
		printf("long sort is not yet implemented");//debug
}
