#include "../../includes/cub3d.h"

//At this point the .cub file is open. What we need to do here is to check that the texture files are really
//.xpm and that the path is valid and that we can open it. It would be nice if we could handle the colors in 
//this file as well. Meaning, this file will have the necessary functions that will read the opened file and verify
//each segment except the map
//we will need to do a bunch of gnl until we find a line with some content inside

bool	space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

static int	texture_or_color(char *s)
{
	if (((s[0] == 'N' && s[1] == 'O') || (s[0] == 'S' && s[1] == 'O')
			|| (s[0] == 'W' && s[1] == 'E') || (s[0] == 'E' && s[1] == 'A'))
			&& space(s[2]))
		return (TEXTURE);
	else if ((s[0] == 'F' || s[0] == 'C') && s[1] == ' ')
		return (COLOR);
	else
		return (NEITHER);
}

static	bool	empty_line(char *line)
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
	elem->tmp_path = NULL;
}
//gnl->check if gnl failed->empty_line->if empty_line free line and continue gnl
//					->if not empty_line check the content
//					->if NEITHER return false
//					->else check the path and save that somewhere and check for doublicates

bool	init_elem(int fd)
{
	int		counter;
	int		i;
	t_elem	elem;
	char	*line;

	counter = 0;
	i = 0;
	set_elem_to_null(&elem);
	line = get_next_line(fd);
	if (!line)
		return (custom_write("Gnl error\n"), false);
	if (empty_line(line))
		free(line);
	else if (!empty_line(line))
	{
		while (space(line[i]))
			i++;
		if (texture_or_color(line) == COLOR)
			handle_color(&elem, &line[i]);
		else if (texture_or_color(line) == TEXTURE)
			handle_texture(&elem, &line[i]);
		else if (texture_or_color(line) == NEITHER)
			exit(EXIT_FAILURE);//TO DO


