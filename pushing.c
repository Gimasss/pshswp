/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:07:24 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/08 14:26:15 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **origin, t_list **stack)
{
	t_list *temp;

	if (*origin == NULL)
		return ;
	if  (*stack == NULL)
	{
		temp = (*origin)->next;
		(*origin)->next = NULL;
		*stack = *origin;
		*origin = temp;
		return ;
	}
	temp = (*origin)->next;
	(*origin)->next = *stack;
	*stack = *origin;
	*origin = temp;
}
	

void	push_a(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}
