/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:25:35 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/09 15:04:26 by gmastroc         ###   ########.fr       */
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

int sort_three(t_list **stack)
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
	if (node1 > node2 && node2 < node3)// 9 0 5
		rotating_a(stack);
	else if (node1 < node2 && node2 > node3)
		rev_rotating_a(stack);
	return (0);
}
t_list	*where_to_insert(t_list *stack_a, int content_b)
{
	t_list *current;
	t_list *previous;
	int position;

	position = 0;
	current = stack_a;
	previous = NULL;    
	while (stack_a != NULL)
	{
		printf("Debug: Stack A: %d\n", (stack_a)->content);
		(stack_a) = (stack_a)->next;
	}
	// exit(0);
	while (current && current->next)
	{

		printf("Debug: Current: %d --- content: %d\n", current->content, content_b);
		if (current->content < content_b && 
		current->next->content > content_b)
			break;
		position++;
		current = current->next;
	}
	return (position);
}
void	reintegrate_with_a(t_list **stack_a, t_list **stack_b)
{
	t_list *position;

	while (*stack_b != NULL)
	{
		position = where_to_insert(*stack_a, (*stack_b)->content);
		 // Debugging: Print position and top of stack_a for comparison
        // printf("Debug: Position: %p, Stack A Top: %p\n", (void*)position, (void*)*stack_a);
		
		if (position == *stack_a)//direct push - pos at the top is right place
			push_a(stack_b, stack_a);
		else if (position == ft_lstlast(*stack_a))//position is at the bottom
		{
			rotating_a(stack_a);
			push_a(stack_b, stack_a);
		}
		else//general case
		{
			rotating_a(stack_a);
			position = where_to_insert(*stack_a, (*stack_b)->content);
		}
	}
}

int	sort_stack(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a) == 1)
		return (0);
	while (lst_size(*stack_a) > 3 && !is_sorted(*stack_a))
		push_b(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b != NULL)
		reintegrate_with_a(stack_a, stack_b);
	return (0);
}