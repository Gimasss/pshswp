/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 12:43:40 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/08 15:24:26 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*max_value_lst(t_list* head)
{
	if (!head)
		return NULL;

	t_list* max_val = head;
	while (head != NULL)
	{
		if (head->content > max_val->content)
		{
			max_val = head;
		}
		head = head->next;
	}
	return (max_val);
}

t_list	*min_value_lst(t_list* head)
{
	if (head == NULL) {
		return NULL;
	}
	t_list* min_val = head;
	while (head != NULL) {
		if (head->content < min_val->content) {
			min_val = head;
		}
		head = head->next;
	}
	return min_val;
}
int	lst_size(t_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}