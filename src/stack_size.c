#include "../libs/push_swap.h"

int is_sorted(t_stack  *stack)
{
	t_stack *tmp;


	while (stack->next)
	{
		tmp = stack->next;
		if (tmp->a < stack->a)
			return (0);
		stack  = stack->next;
	}
	return (1);
}

int		stack_size(t_stack *stack)
{
	int size = 0;
	while(stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	return size;
}
