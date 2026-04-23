/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:53:55 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 18:57:11 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

#define ABS(x) (x < 0 ? -x: x)

typedef struct s_memory
{
	void			*content;
	struct s_memory	*next;
}					t_memory;

typedef struct s_stack
{
	int				a;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

void				*ft_malloc(int size, int count, t_memory **memory);
void				heap_free(t_memory **memory);
int					garbage_collector(t_memory **memory, void *data);
int					ft_strlen(char *str);
int					check_args(char **args);
void				clean_exit(t_memory **memory, int status);
int					ft_isdigit(char c);
int					ft_ispace(char c);
char				**ft_split(char *str, char sep, t_memory **memory);
int					init_stack(t_stack **stack , char  **av,  int ac, t_memory **memory);
int					ft_atoi(char *str, t_memory **memory);
int check_dup(t_stack  *stack, int content);
int is_sorted(t_stack  *stack);
int		stack_size(t_stack *stack);
void push_swap(t_stack **stack);

//instractions
void	sa(t_stack **stack);
void sb(t_stack **stack);
void ra(t_stack **stack);
void rb(t_stack **stack);
void rr(t_stack **stack_a, t_stack **stack_b);
void ss(t_stack **stack_a, t_stack **stack_b);
void rra(t_stack **stack);
void rrb(t_stack **stack);
void rrr(t_stack **stack_a, t_stack **stack_b);
void pa(t_stack **stack_a, t_stack **stack_b);
void pb(t_stack **stack_a, t_stack **stack_b);

// turk method part
void get_target_pos(t_stack *stack_a,  t_stack *stack_b);
void calc_cost_a(t_stack *stack , int size);
void calc_cost_b(t_stack *stack, int size);
t_stack *find_cheapset(t_stack *stack);
void excut_moves(t_stack **stack_a, t_stack **stack_b,  t_stack *chep);
int ft_abs(int x);
void final_rotaions(t_stack **stack_a);

#endif
