#include "../libs/push_swap.h"

void calc_cost_a(t_stack *stack , int size)
{
	while (stack)
	{
		if (stack->target_pos <= size / 2)
			stack->cost_a =  stack->target_pos;

		else
			stack->cost_a = stack->target_pos - size;
		stack = stack->next;
	}
}

void calc_cost_b(t_stack *stack, int size)
{
	while (stack)
	{
		if (stack->pos <=  size / 2)
			stack->cost_b = stack->pos;

		else 
			stack->cost_b = stack->pos -  size;
		stack = stack->next;
	}
}
