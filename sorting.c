/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:25:35 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/07 18:53:02 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int    is_sorted(t_list *stack)//single pointer as im just reading the content
{
	if (stack == NULL)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)// 3 2 1
			return (0);
		stack = stack->next;//aggiorno mettendo nodo successivo
	}
	return (1);//if it gets here the thing is sorted
}

int sort_ss_three(t_list **stack)
{
	int node1;
	int node2;
	int node3;

	if (is_sorted(*stack) == 1)
		return (0);
	if (lst_size(*stack) == 2)
		return (swap_a(stack), 0);
	node1 = (*stack)->content;
	node2 = (*stack)->next->content;
	node3 = (*stack)->next->next->content;
	if ( ((node1 < node2 && node1 < node3)//0 9 5
		|| (node3 > node1 && node2 < node3)// 5 0 9
		|| (node1 > node2 && node2 > node3) ))// 5 9 0
			swap_a(stack);
	node1 = (*stack)->content;
	node2 = (*stack)->next->content;
	if (node1 > node2 && node2 < node3)
		rotating_a(stack);
	else if (node1 < node2 && node2 > node3)
		rev_rotating_a(stack);
	return (0);
}

int	sort_ss_five(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return (0);
	while (lst_size(*stack_a) > 3 && !is_sorted(*stack_a))
		push_b(stack_b, stack_a);
	sort_ss_three(stack_a);
	//repush to stack_a in correct order
	// stack_a is 1 3 4 - stack_b is 5 2 - here it is 1 rotate then push_a	
	return (0);
}

t_list *where_to_insert(t_list *stack_a, t_list *top_b)
{
    t_list *current;
    t_list *previous;

	current = stack_a;
	previous = NULL;    
	while (current != NULL)
	{
        if (current->content > top_b->content)
		{
            // Found the correct position
            return previous;
        }
        previous = current;
        current = current->next;
    }
    // When here = top of stack_b is greater than all elements in stack_a
    // and should be inserted at the end.
    return previous;
}
/* 
void sort_organiser(t_list **stack)
{
	int len = lst_size(*stack);
	if (len == 1)
		return;
	else if (len == 2)
	{
		if ((*stack)->content > (*stack)->next->content)
			swap_a(stack);
	}
	else if (len == 3)
		sort_ss_three(stack);
	else if (len > 3 && len <= 5)
		sort_ss_five(stack);
	else
		big_sort(stack);
} */