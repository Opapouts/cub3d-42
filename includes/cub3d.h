/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opapouts <opapouts@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 20:16:31 by opapouts          #+#    #+#             */
/*   Updated: 2026/05/19 20:16:33 by opapouts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include <stdbool.h>
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>



/***********************************************************
 *                         Parsing                          *
 ***********************************************************/

typedef struct	s_elem
{
	char	*elements[6];
	char	*paths[4];

}		t_elem;

void	first_step(int ac, char **av);
#endif
