#include "../../includes/cub3d.h"

// NO ./path_with_texture
//We can have spaces at the beginning, midway or at the end

static	bool	north_or_south(t_elem *elem, int op_code)
{
	if (op_code == NORTH)
	{
		if (elem->north.present)
			return (custom_write("Duplicate texture\n"), false);
		else
		{
			elem->north.present = true;
			elem->north.path = ft_strdup(elem->tmp_path);
			if (!elem->north.path)
				return (custom_write("Strdup error"), false);
		}
	}
	else if (op_code == SOUTH)
	{
		if (elem->south.present)
			return (custom_write("Duplicate texture\n"), false);
		else
		{
			elem->south.present = true;
			elem->south.path = ft_strdup(elem->tmp_path);
			if (!elem->south.path)
				return (custom_write("Strdup error"), false);
		}
	}
	return (true);
}

static	bool	east_or_west(t_elem *elem, int op_code)
{
	if (op_code == EAST)
	{
		if (elem->east.present)
			return (custom_write("Duplicate texture\n"), false);
		else
		{
			elem->east.present = true;
			elem->east.path = ft_strdup(elem->tmp_path);
			if (!elem->east.path)
				return (custom_write("Strdup error"), false);
		}
	}
	else if (op_code == WEST)
	{
		if (elem->west.present)
			return (custom_write("Duplicate texture\n"), false);
		else
		{
			elem->west.present = true;
			elem->west.path = ft_strdup(elem->tmp_path);
			if (!elem->west.path)
				return (custom_write("Strdup error"), false);
		}
	}
	return (true);
}

static bool	fill_out_coordinate(t_elem *elem, char *line)
{
	if (!ft_strncmp(line, "NO", 2))
	{
		if (!north_or_south(elem, NORTH))
			return (false);
	}
	else if (!ft_strncmp(line, "SO", 2))
	{
		if (!north_or_south(elem, SOUTH))
			return (false);
	}
	else if (!ft_strncmp(line, "WE", 2))
	{
		if (!east_or_west(elem, EAST))
			return (false);
	}
	else if (!ft_strncmp(line, "EA", 2))
	{
		if (!east_or_west(elem, WEST))
			return (false);
	}
	return (true);
}

bool	handle_texture(t_elem *elem, char *line)
{
	int		i;
	int		start;
	int		fd;

	i = 2;

	while (space(line[i]))
		i++;
	start = i;
	while (!space(line[i]) && line[i] != '\n')
		i++;
	elem->tmp_path = ft_substr(line, start, i - start);
	if (!elem->tmp_path)
		return (custom_write("Substr error\n"), false);
	if (!is_xpm_file(elem->tmp_path))
		return (false);
	fd = open(elem->tmp_path, O_RDONLY);
	if (fd < 0)
		return (free(elem->tmp_path), custom_write("Wrong texture path\n"), false);
	close(fd);
	fill_out_coordinate(elem, line);
	free(elem->tmp_path);
	elem->tmp_path = NULL;
	return (true);
}
