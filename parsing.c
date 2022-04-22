/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/22 19:05:25 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_value(char *content)
{
	if(content[0] != '-' && content[0] != '+' && !ft_isdigit(content[0]))
		error("parameter contain non-atoiable values");
}

int		value_in_tab(int val, int *tab)
{
	int			i;
	static int	nb_zero;

	i = 0;
	if (!val)
		nb_zero ++;
	if (nb_zero > 1)
		return (1);
	while(tab[i])
	{
		if (tab[i] == val)
			return (1);
		i ++;
	}
	tab[i] = val;
	return (0);
}

t_stack	*read_args(int ac, char **av)
{
	t_stack	*element;
	int		*seen;

	element = NULL;
	seen = malloc(sizeof(int) * ac);
	ft_bzero(seen, ac * sizeof (int));
	ac --;
	while (ac)
	{
		check_value(av[ac]);
		if(value_in_tab(ft_atoi(av[ac]), seen))
			error("duplicated values in stack");
		element = stack_add_front(element, av[ac]);
		ac --;
	}
	return (element);
}
