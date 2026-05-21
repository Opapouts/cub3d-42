#include "../../includes/cub3d.h"

// NO ./path_with_texture
//We can have spaces at the beginning, midway or at the end
static void	fill_out_coordinate(t_elem *elem, char **split)
{
	if (!ft_strncmp(split[0], "NO", 3))
	{
		elem->north.present = true;
		elem->north.path = split[1];//To fix 
	}
	if (!ft_strncmp(split[0], "SO", 3))
	{
		elem->south.present = true;
		elem->south.path = split[1];
	}
	if (!ft_strncmp(split[0], "WE", 3))
	{
		elem->west.present = true;
		elem->west.path = split[1];
	}
	if (!ft_strncmp(split[0], "EA", 3))
	{
		elem->east.present = true;
		elem->east.path = split[1];
	}
}

static bool	check_texture(t_elem *elem, char *line)
{
	int		i;
	char	**split;
	int		fd;

	i = 0;
	split = ft_split(line, ' ');
	if (!split)
		return (custom_write("Split error\n"), false);
	while (split[i])
		i++;
	if (i != 2)
		return (free_split(split), custom_write("Wrong input for texture\n"), false);
	fd = open(split[1], O_RDONLY);
	if (fd < 0)
		return (free_split(split), custom_write("Wrong texture path\n"), false);
	close(fd);
	fill_out_coordinate(elem, split);
	return (true);
}

	

