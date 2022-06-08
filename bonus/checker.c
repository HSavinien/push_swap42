/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 06:46:55 by tmongell          #+#    #+#             */
/*   Updated: 2022/06/08 17:39:29 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	read_move(char	*line, t_stack **sa, t_stack **sb)
{
	if (!ft_strncmp(line, "sa\n", 3))
		mv_sa(sa, sb);
	else if (!ft_strncmp(line, "sb\n", 3))
		mv_sb(sa, sb);
	else if (!ft_strncmp(line, "ss\n", 3))
		mv_ss(sa, sb);
	else if (!ft_strncmp(line, "ra\n", 3))
		mv_ra(sa, sb);
	else if (!ft_strncmp(line, "rb\n", 3))
		mv_rb(sa, sb);
	else if (!ft_strncmp(line, "rr\n", 3))
		mv_rr(sa, sb);
	else if (!ft_strncmp(line, "rra\n", 4))
		mv_rra(sa, sb);
	else if (!ft_strncmp(line, "rrb\n", 4))
		mv_rrb(sa, sb);
	else if (!ft_strncmp(line, "rrr\n", 4))
		mv_rrr(sa, sb);
	else if (!ft_strncmp(line, "pa\n", 3))
		mv_pa(sa, sb);
	else if (!ft_strncmp(line, "pb\n", 3))
		mv_pb(sa, sb);
	else
		exit(write(1, "error\n", 6));
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
	destroy_main_stack(sa);
	destroy_main_stack(sb);
}

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;

	if (ac < 2)
		return (0);
	sa = read_args(ac, ac, av);
	sb = NULL;
	do_checking(sa, sb);
}
