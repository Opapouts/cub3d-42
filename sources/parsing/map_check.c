#include "../../includes/cub3d.h"

//The map will have a bunch of 1s 0s and one letter for the direction. I need
//to do a bunch of gnls to get the whole 2d array
//So here we will be at the end of the textures and colors. We will
//need to skip all the empty lines until we find the map. The map needs to be
//the last element in the file
//The file is already open at this point
// ***Overhead t_elem struct***


static	bool	skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (is_empty_line(line))
	{
		custom_free(line);
		line = get_next_line(fd);
		if (!line)
			return (custom_write("Gnl error"), false);
	}
	return (true);
}

bool	init_array(int fd, t_chain **chain)
{
	char	*line;
	t_chain	*tmp;

	if (!skip_empty_lines(fd))
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		tmp = new_node(line);
		if (!new_node(line))
			return (custom_free(line), free_chain(*chain), false);
		add_node(chain, tmp);
		line = get_next_line(fd);
	}
	return (true);
}
		
