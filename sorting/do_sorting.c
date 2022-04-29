/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 19:31:20 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/29 22:16:39 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//analize the input and call the best algo depending on the number list. for now, it mostly discriminate between short/long array
void	do_sorting(stack *sa, stack *sb)
{
	int len;
	len = get_stack_len(sa)
	if (is_stack_sorted(sa) )
		exit(0);
	else if (len == 3)
		sort_three(sa, sb);
	else if (len <= 6)
		sort_short(sa, sb);

}
