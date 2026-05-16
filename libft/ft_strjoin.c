/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 18:34:24 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/17 10:33:40 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*final_str;

	i = 0;
	j = 0;
	final_str = malloc(sizeof(char) * (ft_strlen(s2) + ft_strlen(s1) + 1));
	if (!final_str)
		return (NULL);
	while (s1[i])
	{
		final_str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final_str[i + j] = s2[j];
		j++;
	}
	final_str[i + j] = '\0';
	return (final_str);
}
/*
{
	char s1[] = "On prie pour aue";
	char s2[] = "ca marche";
	char *s3 = ft_strjoin(s1, s2);
	printf("%s\n", s3);
	return (0);
}*/