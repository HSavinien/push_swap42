/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/30 15:20:45 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_moves	*optimise_mv(t_moves *mvs)
{
	while (mvs->ra && mvs->rb)
	{
		mvs->ra --;
		mvs->rb --;
		mvs->rr ++;
	}
	while (mvs->rra && mvs->rrb)
	{
		mvs->rra --;
		mvs->rrb --;
		mvs->rrr ++;
	}
	mvs->total = mvs->ra + mvs->rb + mvs->rr + mvs->rra + mvs->rrb + mvs->rrr;
	return (mvs);
}

static t_stack	*get_dest(t_stack *node, t_stack *stk)
{
	printf("%d | ", node->index);//debug
	while (stk->index < node->index && stk->next)
		stk = stk->next;
	if (stk->next)
		return (stk);
	return (NULL);
}

static t_moves	*count_moves(t_stack *node, t_stack *sa, t_stack *sb)
{
	t_moves	*mvs;
	int		tmp;
	t_stack	*dst;

	mvs = init_mvs();
	tmp = nb_mvs_to_top(node, sb);
	if (tmp > 0)
		mvs->rb += tmp;
	else
		mvs->rrb += -tmp;
	dst = get_dest(node, sa);
	printf("dst : %p\n", dst);//debug
	if (!dst)
		return (optimise_mv(mvs));
	tmp = nb_mvs_to_top(dst, sa);
	if (tmp > 0)
		mvs->ra += tmp;
	else
		mvs->rra += -tmp;
	return (optimise_mv(mvs));
}

static t_moves	*find_best_moves(t_stack *sa, t_stack *sb)
{
	t_stack	*curent;
	t_moves	*tmp_mvs;
	t_moves	*true_mvs;

	true_mvs = count_moves(sb, sa, sb);
	curent = sb->next;
	while (curent)
	{
		tmp_mvs = count_moves(curent, sa, sb);
		if (tmp_mvs->total < true_mvs->total)
			ft_swap_ptr((void **) &true_mvs, (void **) &tmp_mvs);
		free(tmp_mvs);
		curent = curent->next;
	}
	return (true_mvs);
}

void	sort_many(t_stack *sa, t_stack *sb)
{
	t_moves	*mvs;

	while (get_stack_len(sa) > 3)
		mv_pb(&sa, &sb);
	sa = sort_three(sa, sb);
	printf("presorting give : \n");//debug
	show_stack(sa);//debug
	show_stack(sb);//debug
	while (sb)
	{
		mvs = find_best_moves(sa, sb);
		do_moves(mvs, &sa, &sb);
		printf("new state :\n");
		show_stack(sa);//debug
		show_stack(sb);//debug
	}
}