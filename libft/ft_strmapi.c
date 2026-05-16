/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:18:17 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/16 16:52:31 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	str = malloc((sizeof(char) * (ft_strlen((char *)s) + 1)));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, (char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int	main(void)
{
	char const	str[] = "la mala est gangx";
	char		*str2;

	str2 = ft_strmapi(str, *ft_a);
	printf("%s", str2);
	return (0);
}*/
