/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhachimi <yhachimi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 17:43:29 by yhachimi          #+#    #+#             */
/*   Updated: 2026/04/11 18:11:19 by yhachimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	clean_exit(t_memory **memory, int status)
{
	heap_free(memory);
	if (status == 1)
		write(2, "Error\n", 5);
	exit(status);
}
