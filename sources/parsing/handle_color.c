#include "../../includes/cub3d.h"

//   F      15,   250,  33
bool	handle_color(t_elem *elem, char *line)
{
	int	i;
	int	color;

	i = 0;
	while (line[i] != 'F' || line[i] != 'C')
		i++;
	i++;
	if (line[i - 1] == 'F')
	{
		if (!is_rgb(&line[i]))
			return (false);
		set_color(&line[i])

