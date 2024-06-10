/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:07:21 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/10 15:01:22 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void parse(int argc, char *argv[])
{
	int i;

	i = 0;
	//num is integer
	if (ft_isdigit(argv[1][0]) == 0)
	{
		printf("Error\n Not a number\n");
		exit(1);
	}
	//num has correct sign
	if (argv[1][0] == '-' || argv[1][0] == '+')
	{
		i++;
	}
	else
	{
		printf("Error\n Issues with Sign\n");
		exit(1);
	}

	//num is not a duplicate
	int j;
	for (i = 0; i < argc; i++)
	{
		for (j = i + 1; j < argc; j++)
		{
			if (strcmp(argv[i], argv[j]) == 0)
			{
				printf("Error\n There's a duplicate\n");
				exit(1);
			}
		}
	}
	//num is not a letter
	if (ft_isalpha(argv[1][0]) == 1)
	{
		printf("Error\n It's alpha\n");
		exit(1);
	}
	//num is not too big/small   
}