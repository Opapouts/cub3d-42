/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:17:33 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/18 11:04:53 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str_bis;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (str[i])
	{
		size++;
		i++;
	}
	str_bis = malloc(sizeof(char) * size + 1);
	if (!str_bis)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_bis[i] = str[i];
		i++;
	}
	str_bis[i] = str[i];
	return (str_bis);
}
