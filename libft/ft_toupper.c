/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmetayer <jmetayer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:42:51 by jmetayer          #+#    #+#             */
/*   Updated: 2025/11/08 18:05:16 by jmetayer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char **argv)
{
	(void)argc;
	
	printf("fonction handmade : %d\n", ft_toupper(atoi(argv[1])));
	printf("fonction de base : %d\n", toupper(atoi(argv[1])));
	return (0);
}*/