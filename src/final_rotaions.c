#include  "../libs/push_swap.h"


static void fn_rotate(t_stack **stack, int poss)
{
	int size = stack_size(*stack);
	if (poss <= size / 2)
	{
		while (poss > 0)
		{
			ra(stack);
			poss--;
		}
	}
	else
	{
		while (poss <  size)
		{
			rra(stack);
			poss++;
		}
	}
}

void final_rotaions(t_stack **stack_a)
{
	int poss;
	int value;
	t_stack *tmp;

	tmp = *stack_a;
	value = 2147483647;
	while (tmp)
	{
		if (tmp->a < value)
		{
			value = tmp->a;
			poss = tmp->pos;
		}
		tmp = tmp->next;
	}
	fn_rotate(stack_a, poss);
}
