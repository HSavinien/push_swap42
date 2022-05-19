/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:46:55 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 12:59:04 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_move(char	*line, t_stack **sa, t_stack **sb)
{
	if(!ft_strncmp(line, "sa", 2))
		mv_sa(sa, sb);
	else if(!ft_strncmp(line, "sb", 2))
		mv_sb(sa, sb);
	else if(!ft_strncmp(line, "ss", 2))
		mv_ss(sa, sb);
	else if(!ft_strncmp(line, "ra", 2))
		mv_ra(sa, sb);
	else if(!ft_strncmp(line, "rb", 2))
		mv_rb(sa, sb);
	else if(!ft_strncmp(line, "rr", 2))
		mv_rr(sa, sb);
	else if(!ft_strncmp(line, "rra", 3))
		mv_rra(sa, sb);
	else if(!ft_strncmp(line, "rrb", 3))
		mv_rrb(sa, sb);
	else if(!ft_strncmp(line, "rrr", 3))
		mv_rrr(sa, sb);
	else if(!ft_strncmp(line, "pa", 2))
		mv_pa(sa, sb);
	else if(!ft_strncmp(line, "pb", 2))
		mv_pb(sa, sb);
	else
		exit(ft_printf("error\n"));
//	show_stack(*sa);//debug
//	show_stack(*sb);//debug
}

void	do_checking(t_stack *sa, t_stack *sb)
{
	char	*line;

	line = get_next_line(0);
	while (line && line[0] != '\n')
	{
		read_move(line, &sa, &sb);
		free(line);
		line = get_next_line(0);
	}
	if (is_stack_sorted(sa))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;

	if (ac < 2)
		return(0);
	sa = read_args(ac, av);
	sb = NULL;
	do_checking(sa, sb);
}
