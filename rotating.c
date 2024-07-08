/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:42:14 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/24 16:27:44 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotating(t_list **stack)
{
	t_list *temp;
	t_list *last;

	temp = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	temp->next = NULL;
	last->next = temp;
}
void   rotating_a(t_list **stack_a)
{
	rotating(stack_a);
	ft_putendl_fd("ra", 1);
}

void   rotating_b(t_list **stack_b)
{
	rotating(stack_b);
	ft_putendl_fd("rb", 1);
}

void   rotating_r(t_list **stack_a, t_list **stack_b)
{
	rotating(stack_a);
	rotating(stack_b);
	ft_putendl_fd("rr", 1);
}