/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 18:48:50 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/10 14:43:30 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int value;//?? for min max value
	int		content;
	struct	s_list *next;
}	t_list;


/*
typedef struct s_stack a
{
	int		*top;
	int		size;
	int     data;
}	t_stack a;

typedef struct s_stack b
{
	int		*top;
	int		size;
	int     data;
}	t_stack b;

 */
#endif