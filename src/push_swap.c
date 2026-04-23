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

void sort_three(t_stack **stack)
{
	int a;
	int c;
	int b;

	a = (*stack)->a;
	b = (*stack)->next->a;
	c = (*stack)->next->next->a;
	if (a > b && b  < c && c > a)
		sa(stack);
	if (a < b && b > c && c < a)
		rra(stack);
	if (a > b  && b < c  && c < a)
		ra(stack);
	if (a > b  && b > c)
	{
		ra(stack);
		sa(stack);
	}
	if (a < b && b > c && c > a)
	{

		rra(stack);
		sa(stack);
	}
}

void pos(t_stack *stack)
{
	int i = 0;
	while  (stack)
	{
		stack->pos =  i;
		stack = stack->next;
		i++;
	}
}

void push_swap(t_stack **stack)
{
	t_stack *stack_b;
	t_stack *cheapset;

	stack_b = NULL;
	int size = stack_size(*stack);
	if (size == 2)
		return (sa(stack));
	else if (size == 3)
		(sort_three(stack));
	else if (size <= 100)
	{
		while (stack_size(*stack) != 3)
		{
			pb(stack, &stack_b);
		}
		sort_three(stack);
		while (stack_b)
		{
			pos(*stack);
			pos(stack_b);
			get_target_pos(*stack, stack_b);
			calc_cost_a(stack_b, stack_size(stack_b));
			calc_cost_b(stack_b, stack_size(stack_b));
			cheapset = find_cheapset(stack_b);
			if (!cheapset || !stack_b)
				break;
			excut_moves(stack, &stack_b,  cheapset);
		}
	}
}
