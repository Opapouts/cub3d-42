#include "../../includes/cub3d.h"

static	void	find_player(char **map, int *x, int *y)
{
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'N' || map[*y][*x] == 'S' || map[*y][*x] == 'E'
					|| map[*y][*x] == 'W')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static char	**copy_map(char **map)
{
	int		i;
	char	**copy;

	i = 0;
	while (map[i])
		i++;
	copy = malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (custom_write("Malloc error"), NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (i >= 0)
				custom_free(copy[i--]);
			free(copy);
			return (custom_write("Malloc error"), NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static bool	is_inside_bounds(char **copy, int x, int y)
{
	int	height;
	int	line_length;

	height = 0;
	line_length = 0;
	if (y < 0 || x < 0)
		return (custom_write("Map is not valid\n"), false);
	while (copy[height])
		height++;
	if (y >= height)
		return (custom_write("Map is not valid\n"), false);
	while (copy[y][line_length])
		line_length++;
	if (x >= line_length)
		return (custom_write("Map is not valid\n"), false);
	return (true);
}

static bool	fill(char **copy, int x, int y)
{
	if (!is_inside_bounds(copy, x, y))
		return (false);
	if (copy[y][x] == 'V' || copy[y][x] == '1')
		return (true);
	if (copy[y][x] == ' ')
		return (custom_write("Map is not valid\n"), false);
	copy[y][x] = 'V';
	if (!fill(copy, x, y - 1))
		return (false);
	if (!fill(copy, x, y + 1))
		return (false);
	if (!fill(copy, x - 1, y))
		return (false);
	if (!fill(copy, x + 1, y))
		return (false);
	return (true);
}

bool	is_map_closed(char **map)
{
	int	x;
	int	y;
	char	**copy;

	x = 0;
	y = 0;
	find_player(map, &x, &y);
	copy = copy_map(map);
	if (!copy)
		return (false);
	if (!fill(copy, x, y))
		return (free_split(copy), false);
	return (free_split(copy), true);
}
