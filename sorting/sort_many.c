/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/31 16:40:22 by tmongell         ###   ########.fr       */
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

//function assume that sa is not sorted, but can be with only rotate/rev_rotate.
static t_stack	*get_dest(t_stack *node, t_stack *stk)
{
	t_stack	*cpy;
	t_stack *save_cpy;
	
	cpy = copy_stack(stk);
	save_cpy = cpy;
	while (!is_stack_sorted(cpy))
	{
		do_rotate(&cpy);
		if (cpy == save_cpy){//debug
			printf("error here. sa is :\n");//
			show_stack(stk);//
			exit(0);//
		}//debug
	}
	show_stack(cpy);//debug
	while (cpy->index < node->index && cpy->next)
		cpy = cpy->next;
	if (!cpy->next)
		cpy = save_cpy;
	printf("dest found : \033[1;32m%d\033[0m\n", cpy->index);//debug
	while (cpy->index != stk->index)
		stk = stk->next;
	destroy_stack(cpy);
	return(stk);
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
	printf("searching dst for element %d\n", node->index);//debug
	dst = get_dest(node, sa);
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
	show_both_stack(sa, sb, "presorting give :");//debug
	while (sb)
	{
		printf("\033[1;31mloop\033[0m\n");//debug
		mvs = find_best_moves(sa, sb);
		do_moves(mvs, &sa, &sb);
		show_both_stack(sa, sb, "new_state :");//debug
	}
}
