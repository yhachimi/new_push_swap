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

typedef struct s_memory
{
	void			*content;
	struct s_memory	*next;
}					t_memory;

typedef struct s_stack
{
	int				a;
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

#endif
