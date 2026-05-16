/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:00:08 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/17 10:53:56 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}
/*
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_strchr : %s\n", ft_strchr(argv[1], 65));
	printf("strchr : %s\n", strchr(argv[1], 65));
}*/