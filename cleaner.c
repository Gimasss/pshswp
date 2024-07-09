/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:45:40 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/21 16:33:46 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freefree(char **str)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
}

void	free_stack(t_list *stack)
{
	t_list *temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free (stack);
		stack = temp;
	}
}