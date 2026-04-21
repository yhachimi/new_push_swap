/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:36:05 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 20:21:07 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

int	ft_ispace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_args(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i] != NULL)
	{
		j = 0;
		while (args[i][j])
		{
			while (ft_ispace(args[i][j]))
				j++;
			if (args[i][j] == '-' || args[i][j] == '+')
				j++;
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int check_dup(t_stack  *stack, int content)
{
	while (stack != NULL)
	{
		if (stack->a == content)
			return (1);
		stack = stack->next;
	}
	return (0);
}
