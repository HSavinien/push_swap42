/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:02:12 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/02 18:29:15 by tmongell         ###   ########.fr       */
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
//	printf("after optimisation, total nb of moves is \033[37;44m%d\033[0m\n", mvs->total);//debug
	return (mvs);
}

//function assume that sa is not sorted, but can be with only rotate/rev_rotate.
static t_stack	*get_dest(t_stack *node, t_stack *stk)
{
	t_stack	*cpy;
	t_stack *save_cpy;
	
	printf("\033[4mabout to find the dest of node \033[1m#%d\033[0m in sa :\n", node->index);//debug
	show_stack(stk);//debug
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
	printf("\033[33mcpy sorted :\033[0m\n");//debug
	show_stack(cpy);//debug
	while (cpy->index < node->index && cpy->next){
		cpy = cpy->next; 
		printf("cpy is now #%d\n", cpy->index);//debug
	}
//PROBLEME ZONE : BEGIN=============================================PROBLEM ZONE
	if (!cpy->next)
	{
		printf("\033[31m!cpy->next\033[0m\n");//debug
		cpy = save_cpy;
	}
//PROBLEME ZONE : END===============================================PROBLEM ZONE
	printf("dest for \033[1m#%d\033[0m is element \033[1m#%d\033[0m\n", node->index, cpy->index);//debug
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

//	printf("testing for element \033[1;33m#%d\033[0m\n", node->index);//debug
	mvs = init_mvs();
	tmp = nb_mvs_to_top(node, sb);
	if (tmp > 0)
		mvs->rb += tmp;
	else
		mvs->rrb += -tmp;
//	printf("nb mvs to put node on top of sb : \033[32m%d\033[0m\n", tmp);//debug
	dst = get_dest(node, sa);
//	printf("dest is element \033[1m#%d\033[0m\n", dst->index);//debug
	tmp = nb_mvs_to_top(dst, sa);
	if (tmp > 0)
		mvs->ra += tmp;
	else
		mvs->rra += -tmp;
//	printf("nb mvs to put dest on top of sa : \033[32m%d\033[0m\n", tmp);//debug
	return (optimise_mv(mvs));
}

static t_moves	*find_best_moves(t_stack *sa, t_stack *sb)
{
	t_stack	*curent;
	t_moves	*tmp_mvs;
	t_moves	*true_mvs;

//	show_both_stack(sa, sb, "counting moves for situation :");//debug
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
