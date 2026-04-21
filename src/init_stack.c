#include "../libs/push_swap.h"

int ft_atoi(char *str, t_memory **memory)
{
	long res = 0;
	int sign = 1;
	int i = 0;

	while (ft_ispace(str[i]))
		i++;
	if (str[i] ==  '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign  = -sign;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		if ((res * sign) > 2147483647 || (res * sign) < -2147483648)
			clean_exit(memory, 1);
		i++;
	}

	return (res * sign);
}

int init_stack(t_stack **stack , char  **av,  int ac, t_memory **memory)
{
	int i;
	int j;
	char  **args;
	t_stack		*new;
	t_stack 	*tmp;

	i  = 1;
	while (i < ac)
	{
		j = 0;
		args = ft_split(av[i],  ' ', memory);
		if (!args)
			clean_exit(memory, 1);
		while (args[j])
		{
			new = ft_malloc(sizeof(t_stack), 1, memory);
			if (!new)
				clean_exit(memory, 1);
			new->a =  ft_atoi(args[j],  memory);
			if (check_dup(*stack, new->a))
				clean_exit(memory, 1);
			new->next = NULL;
			if (*stack == NULL)
				*stack = new;
			else
			{
				tmp = *stack;
				while (tmp->next != NULL)
					tmp = tmp->next;
				tmp->next = new;
			}
			j++;
		}
		i++;	
	}
	return (0);
}
