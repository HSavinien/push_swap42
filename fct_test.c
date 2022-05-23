/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:04:57 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/23 19:38:57 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_init_mvs()
{
	t_moves	*mv;
	
	printf("\033[1;4mtesting function \033[2minit_mvs\033[0m\n");
	mv = init_mvs();
	printf("mvs ra:%d;rb:%d;rr:%d;rra:%d;rrb:%d;rrr:%d;total:%d\n",
		mv->ra, mv->rb, mv->rr, mv->rra, mv->rrb, mv->rrr, mv->total);
}

void	test_find_pos_in_stack()
{
//	t_stack * stk;
	t_stack	*stk;
	t_stack	*curr;
	char	**args;

	printf("\033[1;4mtesting function \033[2mfind_pos_in_stack\033[0m\n");
	args=ft_split("name/1 2 3 4 5 6 7 8 9 10", '/');
	stk = read_args(2, args);
	show_stack(stk);
	curr = stk;
	while (curr)
	{
		printf("%d ; ", find_pos_in_stack(curr, stk));
		curr = curr->next;
	}
	printf("\n");
}

void	test_nb_mvs_to_top()
{
	t_stack	*stk;
	t_stack	*curr;
	char	**args;

	printf("\033[1;4mtesting function \033[2mtest_nb_mvs_to_top\033[0m\n");
	args=ft_split("name/1 2 3 4 5 6 7 8 9 10", '/');
	stk = read_args(2, args);
	show_stack(stk);
	curr = stk;
	while (curr)
	{
		printf("%d : %d\n", curr->index, nb_mvs_to_top(curr, stk));
		curr = curr->next;
	}
}

void	test_do_moves()
{	
	t_stack	*sa;
	t_stack	*sb;
	t_moves	*mvs;
	char	**args;
	
	printf("\033[1;4mtesting function \033[2mtest_do_moves\033[0m\n");
	args = ft_split("name/1 2 3 4 5 6 7 8 9", '/');
	sb = read_args(2, args);
	sa = NULL;
	mvs = init_mvs();
	mvs->ra = 3;
	mvs->total = 3;
	do_moves(mvs, &sa, &sb);
	free(mvs);
	mvs = init_mvs()
	mvs->rrb = 2;
	mvs->total = 2;
	printf("doing_moves\n");
	do_moves(mvs, &sa, &sb);
}

int	main()
{
	test_init_mvs();
	test_find_pos_in_stack();
	test_nb_mvs_to_top();
	test_do_moves();
}
