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
#include <stdio.h>

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
	t_stack 	*main_stack;

	memory = NULL;
	main_stack = NULL;
	if (argc < 2)
		return (write(1, "Error", 6), 1);
	if (check_data(argv, argc, &memory))
		clean_exit(&memory, 1);
	init_stack(&main_stack, argv, argc,  &memory);
	if (is_sorted(main_stack))
		clean_exit(&memory, 0);
	rra(&main_stack);
	while (main_stack)
	{
		printf("stack: %d\n", main_stack->a);
		main_stack = main_stack->next;
	}
	//push_swap(main_stack);
	heap_free(&memory);
}
