/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:37:17 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/21 21:17:23 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(int ac, char **av);
{
	while (ac)
	{
		if ()
	}
}
void	check_value(char *content)
{
	if(content[0] != '-' && content[0] != '+' && !ft_isdigit(content[0]))
		error("parameter contain non-atoiable values");
}

int		value_in_tab(int val, int *tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		if (tab[i] == val)
			return (1);
		i ++;
	}
	return (0);
}

t_stack	*read_args(int ac, char **av)
{
	t_stack	*element;

	element = NULL;
	check_duplicate(ac, av);
	ft_bzero(values, ac * sizeof (int));
	ac --;
	while (ac)
	{
		check_value(av[ac]);
		element = stack_add_front(element, av[ac]);
		ac --;
	}
	return (element);
}
