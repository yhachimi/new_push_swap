#include "../libs/push_swap.h"

static int total_cost(t_stack *stack)
{
	return (ABS(stack->cost_a) + ABS(stack->cost_b));
}

t_stack *find_cheapset(t_stack *stack)
{
	t_stack *chep;

	chep  = stack;
	int smallest_cost  = total_cost(chep);
	while (stack)
	{
		if (total_cost(stack) < smallest_cost)
		{
			chep  = stack;
			smallest_cost = total_cost(stack);
		}
		stack = stack->next;
	}
	return (chep);
}

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
