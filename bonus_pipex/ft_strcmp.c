/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oait-bad <oait-bad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 01:25:50 by oait-bad          #+#    #+#             */
/*   Updated: 2023/01/07 16:31:01 by oait-bad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] > str2[i])
		{
			return (1);
		}
		if (str1[i] < str2[i])
		{
			return (-1);
		}
		i++;
	}
	return (0);
}

void	error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
