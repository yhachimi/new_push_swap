#include "../libs/push_swap.h"


static void get_smallest_tar(t_stack **tar, t_stack *stack_a)
{
	int value =  2147483647;
	while (stack_a)
	{
		if (stack_a->a < value)
		{
			value = stack_a->a;
			*tar = stack_a;
		}
		stack_a = stack_a->next;
	}
}

void get_tar(t_stack **tar, t_stack *stack_a, t_stack *stack_b)
{
	int value = 2147483647;
	int content;

	*tar = NULL;
	while  (stack_a)
	{
		content =  stack_a->a;
		if (content > stack_b->a && content < value)
		{
			value =  content;
			 *tar =  stack_a;
		}
		stack_a = stack_a->next;
	}
	if (tar == NULL)
	{
		get_smallest_tar(tar, stack_a);
	}
}

void get_target_pos(t_stack *stack_a,  t_stack *stack_b)
{
	t_stack *tar;

	while (stack_b)
	{
		get_tar(&tar, stack_a, stack_b);
		stack_b->target_pos = tar->pos;
		stack_b = stack_b->next;
	}
}
