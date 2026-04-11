/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:18:08 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 20:21:42 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/push_swap.h"

static int	check_data(char **argv, int size, t_memory **memory)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (check_args(ft_split(argv[i], ' ', memory)))
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_memory	*memory;

	memory = NULL;
	if (argc < 2)
		return (write(1, "Error", 6), 1);
	if (check_data(argv, argc, &memory))
		clean_exit(&memory, 1);
	heap_free(&memory);
}
