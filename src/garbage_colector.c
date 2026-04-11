/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_colector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:28:39 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 16:30:32 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/push_swap.h"

void	*ft_malloc(int size, int count, t_memory **memory)
{
	void	*add;

	if (size > 2147483647 / count)
		return (NULL);
	add = malloc(size * count);
	if (!add)
		return (NULL);
	if (garbage_collector(memory, add))
		return (NULL);
	return (add);
}

void	heap_free(t_memory **memory)
{
	t_memory	*tmp;

	if (!memory || !*memory)
		return ;
	while (*memory != NULL)
	{
		tmp = (*memory)->next;
		free((*memory)->content);
		free(*memory);
		*memory = tmp;
	}
}

int	garbage_collector(t_memory **memory, void *data)
{
	t_memory	*new;
	t_memory	*tmp;

	if (memory == NULL)
		return (1);
	new = malloc(sizeof(t_memory));
	if (!new)
		return (1);
	new->content = data;
	new->next = NULL;
	if (*memory == NULL)
	{
		*memory = new;
		return (0);
	}
	tmp = *memory;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}
