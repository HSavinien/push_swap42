/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:04:57 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 06:32:09 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test_init_mvs()
{
	printf("\033[1;4mtesting function \033[2minit_mvs\n\033[0m");
}

void	test_find_pos_in_stack()
{
	printf("\033[1;4mtesting function \033[2mfind_pos_in_stack\n\033[0m");
}

void	test_nb_mvs_to_top()
{
	printf("\033[1;4mtesting function \033[2mtest_nb_mvs_to_top\n\033[0m");
}

void	test_do_moves()
{
	printf("\033[1;4mtesting function \033[2mtest_do_moves\n\033[0m");
}

int	main()
{
	test_init_mvs();
	test_find_pos_in_stack();
	test_nb_mvs_to_top();
	test_do_moves();
}
