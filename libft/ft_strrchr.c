/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:02:52 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/10 15:41:43 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen((char *)str);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	if (c == 0)
	{
		return ((char *)str);
	}
	return (0);
}

/*#include <string.h>
int	main(int argc, char **argv)
{
	(void)argc;
	printf("ft_strchr : %s\n", ft_strrchr(argv[1], 0));
	printf("strchr : %s\n", strrchr(argv[1], 0));
}*/