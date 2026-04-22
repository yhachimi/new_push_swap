#include "../libs/push_swap.h"
#include <stdio.h>

static void	s(t_stack **stack)
{
	t_stack *tmp;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->next = tmp;
}

void sa(t_stack **stack)
{
	s(stack);
	printf("sa\n");
}

void sb(t_stack **stack)
{
		s(stack);
		printf("sb\n");
}

void ss(t_stack **stack_a, t_stack **stack_b)
{
	s(stack_a);
	s(stack_b);
	printf("ss\n");
}

static void reversed_r(t_stack **stack)
{
	t_stack *tmp  = *stack;
	t_stack *prev ;

	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}
static void r(t_stack **stack)
{
	t_stack *first  = (*stack)->next;
	t_stack *last = *stack;


	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	*stack = first;
	last->next->next = NULL;
}

void rra(t_stack **stack)
{
	reversed_r(stack);
	printf("rra\n");
}

void rrb(t_stack **stack)
{
	reversed_r(stack);
	printf("rrb\n");
}

void ra(t_stack **stack)
{
	r(stack);
	printf("ra\n");
}
void rb(t_stack **stack)
{
	r(stack);
	printf("rb\n");
}
void rr(t_stack **stack_a, t_stack **stack_b)
{
	r(stack_a);
	r(stack_b);
	printf("rr\n");
}
void rrr(t_stack **stack_a, t_stack **stack_b)
{
	reversed_r(stack_a);
	reversed_r(stack_b);
	printf("rrr\n");
}
