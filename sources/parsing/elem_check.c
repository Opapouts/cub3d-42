#include "../../includes/cub3d.h"

//At this point the .cub file is open. What we need to do here is to check 
//that the texture files are really .xpm and that the path is valid and 
//that we can open it. It would be nice if we could handle the colors in 
//this file as well. Meaning, this file will have the necessary functions 
//that will read the opened file and verify each segment except the map
//we will need to do a bunch of gnl until we 
//find a line with some content inside

static int	texture_or_color(char *s)
{
	int	i;

	i = 0;
	while (space(s[i]))
		i++;
	if (((s[i] == 'N' && s[i + 1] == 'O') || (s[i] == 'S' && s[i + 1] == 'O')
			|| (s[i] == 'W' && s[i + 1] == 'E')
			|| (s[i] == 'E' && s[i + 1] == 'A'))
		&& space(s[i + 2]))
		return (TEXTURE);
	else if ((s[i] == 'F' || s[i] == 'C') && space(s[i + 1]))
		return (COLOR);
	else
		return (NEITHER);
}

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\n' && !space(line[i]))
			return (false);
		i++;
	}
	return (true);
}

static	void	set_elem_to_null(t_elem *elem)
{
	int	i;

	i = 0;
	elem->tmp = 0;
	elem->north.present = false;
	elem->north.path = NULL;
	elem->south.present = false;
	elem->south.path = NULL;
	elem->east.present = false;
	elem->east.path = NULL;
	elem->west.present = false;
	elem->west.path = NULL;
	elem->floor.present = false;
	elem->floor.color = 0;
	elem->ceiling.present = false;
	elem->ceiling.color = 0;
	elem->line = NULL;
	elem->tmp_path = NULL;
}

static bool	process_line(t_elem *elem, int fd)
{
	int		i;

	i = 0;
	elem->line = get_next_line(fd);
	if (!elem->line)
		return (custom_write("Gnl error\n"), false);
	else if (!is_empty_line(elem->line))
	{
		while (space(elem->line[i]))
			i++;
		if (texture_or_color(elem->line) == COLOR)
		{
			if (!handle_color(elem, &elem->line[i]))
				return (custom_free(elem->line), false);
		}
		else if (texture_or_color(elem->line) == TEXTURE)
		{
			if (!handle_texture(elem, &elem->line[i]))
				return (custom_free(elem->line), false);
		}
		else if (texture_or_color(elem->line) == NEITHER)
			return (custom_free(elem->line), false);
	}
	return (true);
}

bool	init_elem(int fd, t_elem *elem)
{

	set_elem_to_null(elem);
	if (!process_line(elem, fd))
		return (false);
	while (elem->line)
	{
		if (all_present(elem))
		{
			custom_free(elem->line);
			break ;
		}
		custom_free(elem->line);
		if (!process_line(elem, fd))
			return (false);
	}
	return (true);
}
