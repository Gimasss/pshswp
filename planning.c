/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:12:30 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/09 15:06:43 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	moves_to_top(t_list *stack, int target_pos) 
{
	int moves;

	moves = 0;
	while (stack && stack->content != target_pos)
	{
		moves++;
		stack = stack->next;
	}
	return moves;
}

int	rev_moves_to_top(t_list *stack, int target_pos)
{
	int	size;
	int	moves;

	size = lst_size(stack);
	moves = moves_to_top(stack, target_pos);
	return size - moves;
}
int	calculate_total_moves(t_list *stack_a, t_list *stack_b)
{
    int content_b = stack_b->content;  // Assuming the top of stack_b
    int target_position = find_target_position(stack_a, content_b);
    int moves_a = calculate_moves_to_top(stack_a, target_position);
    int reverse_moves_a = calculate_reverse_moves_to_top(stack_a, target_position);
    int moves_b = 0; // Assuming the top of stack_b, so moves_b is 0
    int reverse_moves_b = 0; // Assuming the top of stack_b, so reverse_moves_b is 0

    // Combining rotations
    int total_moves = moves_a + moves_b;
    int total_reverse_moves = reverse_moves_a + reverse_moves_b;
    return total_moves < total_reverse_moves ? total_moves : total_reverse_moves;
}
