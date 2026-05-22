#include "../../includes/cub3d.h"

//   F      15,   250,  33
//Okay we need to handle the color case. We will receive the full line
//First we need to skip the spaces
static bool	set_color(t_elem *elem, char *line)
{
	char	**split;
	int		red;
	int		green;
	int		blue;

	if (!is_rgb(line + 1))
		return (false);
	split = ft_split(line + 1, ',');
	if (!split)
		return (custom_write("Split error\n"), false);
	red = ft_atoi(split[0]);
	green = ft_atoi(split[1]);
	blue = ft_atoi(split[2]);
	elem->tmp = (red << 16) | (green << 8) | blue;
	free_split(split);
	split = NULL;
	return (true);
}

bool	handle_color(t_elem *elem, char *line)
{
	if (line[0] == 'F')
	{
		if (elem->floor.present)
			return (custom_write("Duplicate color\n"), false);
		if (!set_color(elem, line))
			return (false);
		elem->floor.color = elem->tmp;
		elem->floor.present = true;
	}
	else if (line[0] == 'C')
	{
		if (elem->ceiling.present)
			return (custom_write("Duplicate color\n"), false);
		if (!set_color(elem, line))
			return (false);
		elem->ceiling.color = elem->tmp;
		elem->ceiling.present = true;
	}
	return (true);
}
