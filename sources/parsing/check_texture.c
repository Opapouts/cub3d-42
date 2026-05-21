#include "../../includes/cub3d.h"

//At this point the .cub file is open. What we need to do here is to check that the texture files are really
//.xpm and that the path is valid and that we can open it. It would be nice if we could handle the colors in 
//this file as well. Meaning, this file will have the necessary functions that will read the opened file and verify
//each segment except the map
//we will need to do a bunch of gnl until we find a line with some content inside

static int	texture_or_color(char *s)
{
	if (((s[0] == 'N' && s[1] == 'O') || (s[0] == 'S' && s[1] == 'O')
			|| (s[0] == 'W' && s[1] == 'E') || (s[0] == 'E' && s[1] == 'A'))
			&& s[2] == ' ')
		return (TEXTURE);
	else if ((s[0] == 'F' || s[0] == 'C') && s[1] == ' ')
		return (COLOR);
	else
		return (NEITHER);
}

bool	space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (true);
	return (false);
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
//gnl->check if gnl failed->empty_line->if empty_line free line and continue gnl
//					->if not empty_line check the content
//					->if NEITHER return false
//					->else check the path and save that somewhere and check for doublicates
bool	check_textures_and_colors(int fd)
{
	char	*line;
	line = get_next_line(fd);
	if (!line)
		return (custom_write("Gnl error\n"), false);
	if (empty_line(line))
		free(line);
	else if (!empty_line(line))
	{
		if (texture_or_color(line) == COLOR)

