/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:36:28 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/18 11:39:36 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s);
	j = 0;
	if (s && f)
	{
		while (i > j)
		{
			(*f)(j, s);
			j++;
			s++;
		}
	}
}
/*
int	main(void)
{
	char str[] = "la mala est gangx";

	ft_striteri(str, ft_a);
	printf("%s", str);
	return (0);
}*/