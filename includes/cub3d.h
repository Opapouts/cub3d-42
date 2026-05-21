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

enum
{
	TEXTURE,
	COLOR,
	NEITHER
};

typedef struct	s_elem
{
	char	*elements[6];
	char	*paths[4];

}		t_elem;

bool	is_cub_file(int ac, char **av);
bool	is_xpm_file(char *path);
bool	is_rgb(char *color);

bool	space(char c);
void	custom_write(char *msg);
#endif
