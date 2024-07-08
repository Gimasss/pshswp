/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:28:08 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/03 18:21:27 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void   rev_rotating(t_list **stack)
{
    t_list *temp_head;
    t_list *bfrlast;
    t_list *last;

    if(lst_size(*stack) < 2)
        return ;
    temp_head = *stack;
    bfrlast = ft_lst_bfrlast(*stack);
    last = bfrlast->next;
    bfrlast->next = NULL;
    last->next = temp_head;
    *stack = last;
}

void   rev_rotating_a(t_list **stack_a)
{
    rev_rotating(stack_a);
    ft_putendl_fd("rra", 1);
}

void   rev_rotating_b(t_list **stack_b)
{
    rev_rotating(stack_b);
    ft_putendl_fd("rrb", 1);
}

void   rev_rotating_r(t_list **stack_a, t_list **stack_b)
{
    rev_rotating(stack_a);
    rev_rotating(stack_b);
    ft_putendl_fd("rrr", 1);
}