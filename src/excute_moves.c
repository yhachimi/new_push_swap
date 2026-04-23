#include "../libs/push_swap.h"

static int min_abs(int a, int b)
{
	int abs_a = ft_abs(a);
	int abs_b = ft_abs(b);

	return (abs_a < abs_b ? abs_a : abs_b);
}

void rotate_both(int *a, int *b, t_stack **stack_a, t_stack **stack_b)
{
	int m;

	if (*a < 0 && *b < 0)
	{
		m = min_abs(*a, *b);
		while (m-- > 0)
		{
			rrr(stack_a, stack_b);
			(*a)++;
			(*b)++;
		}
	}
	else if (*a > 0 && *b > 0)
	{
		m = min_abs(*a, *b);
		while (m-- > 0)
		{
			rr(stack_a, stack_b);
			(*a)--;
			(*b)--;
		}
	}
}
void rotate_a(t_stack  **stack_a, int *a)
{
	if (*a > 0)
	{
		while (*a > 0)
		{
			ra(stack_a);
			*a -= 1;
		}
	}
	else if (*a < 0)
	{
		while (*a < 0)
		{
			rra(stack_a);
			*a += 1;
		}
	}
}

void rotate_b(t_stack  **stack_b, int *b)
{
	if (*b > 0)
	{
		while (*b > 0)
		{
			rb(stack_b);
			*b -= 1;
		}
	}
	else if (*b < 0)
	{
		while (*b < 0)
		{
			rrb(stack_b);
			*b += 1;
		}
	}
}

void excut_moves(t_stack **stack_a, t_stack **stack_b,  t_stack *chep)
{
	int a;
	int b;

	a = chep->cost_a;
	b = chep->cost_b;
	rotate_both(&a, &b, stack_a, stack_b);
	rotate_a(stack_a, &a);
	rotate_b(stack_b, &b);
	pa(stack_a, stack_b);
}
