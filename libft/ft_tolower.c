/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 18:17:01 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/08 18:17:02 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
	(void)argc;
	
	printf("fonction handmade : %d\n", ft_tolower(atoi(argv[1])));
	printf("fonction de base : %d\n", tolower(atoi(argv[1])));
	return (0);
}*/