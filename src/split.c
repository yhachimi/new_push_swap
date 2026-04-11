/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:36:55 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 20:11:55 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libs/push_swap.h"

int	count(char *str, char sep)
{
	int	i;
	int	in_word;
	int	count;
	int	size;

	size = ft_strlen(str);
	i = 0;
	in_word = 0;
	count = 0;
	while (i < size)
	{
		if (str[i] == sep)
			in_word = 0;
		if (in_word == 0 && str[i] != sep)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

char	*spl_dup(char *str, char sep, int *pos, t_memory **memory)
{
	int		i;
	int		size;
	char	*new;

	i = 0;
	size = 0;
	while (str[*pos + size] != sep && str[*pos + size])
		size++;
	new = ft_malloc(size + 1, 1, memory);
	if (!new)
		clean_exit(memory, 1);
	while (str[*pos + i] && str[*pos + i] != sep)
	{
		new[i] = str[*pos + i];
		i++;
	}
	*pos += i;
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str, char sep, t_memory **memory)
{
	char	**splt;
	int		size;
	int		i;
	int		pos;

	i = 0;
	pos = 0;
	size = count(str, sep) + 1;
	splt = ft_malloc(size, sizeof(char *), memory);
	if (splt == NULL)
		clean_exit(memory, 1);
	while (i < size - 1)
	{
		while (str[pos] == sep)
			pos++;
		splt[i] = spl_dup(str, sep, &pos, memory);
		i++;
	}
	splt[i] = NULL;
	return (splt);
}
