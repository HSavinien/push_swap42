/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:13:32 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/17 13:50:36 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_moves	*init_mvs(void)
{
	t_moves	*mvs;

	mvs = malloc(sizeof (t_moves));
	mvs->ra = 0;
	mvs->rb = 0;
	mvs->rr = 0;
	mvs->rra = 0;
	mvs->rrb = 0;
	mvs->rrr = 0;
	mvs->total = 0;
	return (mvs);
}
