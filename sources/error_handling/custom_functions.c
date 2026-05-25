/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:15:40 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/19 20:16:03 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//Testing github email modifications
#include "../../includes/cub3d.h"

void	custom_write(char *msg)
{
	int	len;

	len = ft_strlen(msg);
	write(2, "Error\n", 6);
	write(2, msg, len);
}

void	custom_free(char *str)
{
	free(str);
	str = NULL;
}
