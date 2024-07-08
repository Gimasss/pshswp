/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:48:10 by gmastroc          #+#    #+#             */
/*   Updated: 2024/07/08 11:24:58 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	**mat_dupl(char **str, int argc)
{
	//int argc mi da' la dimensione
	int		i;
	char	**matrix;

	matrix = ft_calloc(argc + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		matrix[i] = ft_strdup(str[i]);
		if (!matrix[i])
			return (freefree(matrix), NULL);
	}
	return (matrix);
}

t_list	*parse_and_make_list(char **string)
{
	int	i;
	int	*number;
	t_list *stack_a;
	t_list *node;

	i = -1;
	stack_a = NULL;
	while (string[++i])
	{
		number = atoi_evo(string[i]);
		if (!number)
			return(ft_putendl_fd("Error", 2), free_stack(stack_a), NULL);
		t_list *s = stack_a;
		while (s != NULL)//this check for dups make sep func
		{
			if (s->content == *number)
				return(ft_putendl_fd("Error", 2), free_stack(stack_a), free(number), NULL);
			s = s->next;
		}
		node = ft_lstnew(*number);
		free(number);
		if (!node)
			return(ft_putendl_fd("Error", 2), free_stack(stack_a), NULL);
		ft_lstadd_back(&stack_a, node);
	}
	return (stack_a);
}


int	main(int argc, char *argv[])
{	
	char **string;//split
	t_list *stack_a;
	t_list *stack_b;

	if (argc == 1)//one arg is not enough
		return (0);
	if (argc == 2)//second argument is between brackets, split content
		string = ft_split(argv[1], ' ');
	else//if not between BRACKETS
		string = mat_dupl(&argv[1], argc - 1);//I use the address to skip argv[0]
	if (!string)
		return (printf("string: wtf\n"), 1);
	stack_a = parse_and_make_list(string);
	stack_b = NULL;
	if (stack_a == NULL && string[0] != NULL)
		return (printf("wtf\n"), freefree(string), 1);
	freefree(string);
	sort_ss_five(&stack_a, &stack_b);
	
	t_list *s = stack_a;
	while (s != NULL)//eliminare poi
	{
		printf("List:%d\n", s->content);
		s = s->next;
	}
	free_stack(stack_a);
}
