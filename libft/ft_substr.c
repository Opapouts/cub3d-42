/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 13:37:32 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/18 11:08:32 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	string_size;

	if (s == 0)
		return (NULL);
	string_size = ft_strlen(s);
	if (string_size < start)
	{
		substr = (char *)malloc(sizeof(char) * 1);
		if (substr == 0)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > string_size - start)
		len = string_size - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	substr[len] = '\0';
	return (substr);
}
