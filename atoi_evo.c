/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_evo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmastroc <gmastroc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 19:23:04 by gmastroc          #+#    #+#             */
/*   Updated: 2024/06/24 17:40:03 by gmastroc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*atoi_evo(const char *str)
{
	int		i;
	int		sign;
	int		temp;
	int 	*result;

	result = malloc(sizeof(int));
	if (!result)
		return (NULL);
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (!ft_isdigit(str[i]))
			return (free(result), NULL);
	}
	*result = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		temp = *result;
		*result = (*result * 10) + (str[i] - '0');
		if (*result / 10 != temp)
			return (free(result), NULL);
		i++;
	}
	if (str[i] != '\0')
		return (free(result), NULL);
	*result = *result * sign;
	return (result);
}
