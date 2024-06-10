/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 18:33:06 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/10 14:51:18 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int value;//?? for min max value
	int		content;
	struct	s_list *next;
}	t_list;



//creare nuova lista
t_list    *ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
//add to front of the list
void    ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
//go to the end of the list
t_list    *ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
//add to the end of the list
void    ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

t_list* max_value_lst(t_list* head)
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

t_list* min_value_lst(t_list* head)
{
    if (head == NULL) {
        return NULL;
    }
    t_list* min_val = head;
    while (head != NULL) {
        if (head->value < min_val->value) {
            min_val = head;
        }
        head = head->next;
    }
    return min_val;
}
int lst_size(t_list *lst)
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

int main()
{
	t_list* head;
	head = ft_lstnew(5);
	while (head != NULL)
	{
		printf("List:%d\n", head->content);
		head = head->next;
	}
	ft_lstadd_back(&head, ft_lstnew(10));
	ft_lstadd_back(&head, ft_lstnew(15));
	ft_lstadd_back(&head, ft_lstnew(20));
	ft_lstadd_front(&head, ft_lstnew(3));
	ft_lstadd_front(&head, ft_lstnew(1));

	printf("List:%d\n", head->content);
	return 0;
}