/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:18:00 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 16:18:01 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/push_swap.h"


void push_swap(t_stack *stack)
{
	//t_stack *stack_b;
	//stack_b = NULL;
	int size = stack_size(stack);
	if (size == 2)
	{
		sa(&stack);
	}
}
