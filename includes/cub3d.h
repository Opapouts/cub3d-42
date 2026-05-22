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
//We need a struct that will save the following things
//1)The elements encountered
//2)The color int
//3)The paths
typedef	struct	s_coordinate
{
	bool	present;
	char	*path;
}		t_coordinate;

typedef struct	s_color
{
	bool	present;
	int	color;
}		t_color;

enum
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct	s_elem
{
	t_coordinate	north;
	t_coordinate	south;
	t_coordinate	east;
	t_coordinate	west;
	t_color		floor;
	t_color		ceiling;
	char	*line;
	int	tmp;
	char	*tmp_path;

}		t_elem;

bool	is_cub_file(int ac, char **av);
bool	is_xpm_file(char *path);
bool	is_rgb(char *color);
bool	init_elem(int fd);
bool	handle_color(t_elem *elem, char *line);
bool	handle_texture(t_elem *elem, char *line);
bool	all_present(t_elem *elem);

bool	space(char c);
void	custom_write(char *msg);
void	custom_free(char *str);
void	free_split(char **split);
#endif
