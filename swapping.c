/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 19:02:44 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/01 13:45:48 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **stack)
{
	int	temp;

	temp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
}
void  swap_a(t_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
	//ft_putendl_fd("sa", 1);
}

void  swap_b(t_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
  //  ft_putendl_fd("sb", 1);
}
