//This file will contain the validation of the N S W E F C elements
//We will play with gnl open and split in order to get those values and
//compare them with the accepted values
#include "../../includes/cub3d.h"

bool	is_cub_file(int ac, char **av)
{
	int	fd;
	int	len;

	if (ac != 2)
		return (custom_write("Wrong number of arguments\n"), false);
	len = ft_strlen(av[1]);
	if (len < 4)
		return (custom_write("Not a .cub file\n"), false);
	if (av[1][len - 4] != '.')
		return (custom_write("Not a .cub file\n"), false);
	if (av[1][len - 3] != 'c')
		return (custom_write("Not a .cub file\n"), false);
	if (av[1][len - 2] != 'u')
		return (custom_write("Not a .cub file\n"), false);
	if (av[1][len - 1] != 'b')
		return (custom_write("Not a .cub file\n"), false);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (custom_write("Error while opening the file given\n"), false);
	close(fd);
	return (true);
}

bool	is_xpm_file(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4)
		return (custom_write("Not an .xpm file\n"), false);
	if (path[len - 4] != '.')
		return (custom_write("Not an .xpm file\n"), false);
	if (path[len - 3] != 'x')
		return (custom_write("Not an .xpm file\n"), false);
	if (path[len - 2] != 'p')
		return (custom_write("Not an .xpm file\n"), false);
	if (path[len - 1] != 'm')
		return (custom_write("Not an .xpm file\n"), false);
	return (true);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		custom_free(split[i++]);
	free(split);
}

static	bool	bounds_check(char **split)
{
	int	i;
	int	j;

	j = 0;
	while (j < 3)
	{
		i = 0;
		while (space(split[j][i]))
			i++;
		while (split[j][i])
		{
			if (split[j][i] < '0' || split[j][i] > '9')
				return (custom_write("Wrong color input\n"), false);
			i++;
		}
		if (i > 3)
			return (custom_write("Wrong color input\n"), false);
		j++;
	}
	return (true);
}

bool	is_rgb(char *color)
{
	char	**split;
	int		i;
	int		red;
	int		green;
	int		blue;

	split = ft_split(color, ',');
	if (!split)
		return (custom_write("Split error\n"), false);
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		return (free_split(split), custom_write("Wrong color input\n"), false);
	if (!bounds_check(split))
		return (false);
	red = ft_atoi(split[0]);
	green = ft_atoi(split[1]);
	blue = ft_atoi(split[2]);
	if (red > 255 || green > 255 || blue > 255)
		return (free_split(split), custom_write("Wrong color input\n"), false);
	return (free_split(split), true);
}
