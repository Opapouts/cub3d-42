/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:31:59 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/16 16:53:06 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static unsigned int	ft_count_words(char const *s, char c)
{
	int	i;
	int	count;
	int	sep;

	i = 0;
	sep = 0;
	count = 0;
	while (s[i])
	{
		if (sep == 0 && s[i] != c)
		{
			count++;
			sep = 1;
		}
		if (sep == 1 && s[i] == c)
			sep = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char		**str;
	const char	*start;
	int			i;

	str = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	i = 0;
	if (!str)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			str[i] = NULL;
			while (*s != c && *s)
				s++;
			str[i++] = ft_substr(start, 0, (s - start));
			if (!str[i - 1])
				return (ft_free(str));
			continue ;
		}
		s++;
	}
	str[i] = NULL;
	return (str);
}
/*
int	main(int argc, char **argv)
{
	char	str[] = "Test/de/si/ca/fonctionne";
	char	sep;
	int		i;
	char	**array;
	int		i;

	(void) argc;
	sep = '/';
	array = ft_split(str, sep);
	i = 0;
	while (array[i])
	{
		printf("%s\n", array[i]);
		i++;
	}
	i = 0;
	char **a=ft_split(argv[1], argv[2][0]);
	while (a[i])
	{
		printf("%s", a[i]);
		i++;
	}
	return (0);
}
int	main(int argc, char **argv)
{
	int i = 0;
	(void)argc;
	char **a = ft_split(argv[1], argv[2][0]);
	while (a[i])
		printf("%s\n", a[i++]);
	return (0);
}*/