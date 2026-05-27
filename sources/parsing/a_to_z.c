#include "../../includes/cub3d.h"
//The role of this function is to do the full parsing phase from beginning to end
//This function will receive a string and open that file etc etc
//We first open the file.
//Things I need to add
//1)Freeing elem struct after I am done using it
//2)Initialise the t_config field of t_game struct
//3)Make function to execute repetitive actions
//4)Be better

static	void	set_config_to_null(t_config *config)
{
	config->north_path = NULL;
	config->south_path = NULL;
	config->east_path = NULL;
	config->west_path = NULL;
}

static bool	init_config(t_config *config, t_elem *elem)
{
	config = malloc(sizeof(t_config));
	if (!config)
		return (custom_write("Malloc error\n"), false);
	set_config_to_null(config);
	config->north_path = ft_strdup(elem->north.path);
	if (!config->north_path)
		return (custom_write("Malloc error\n"), free_config(config), false);
	config->south_path = ft_strdup(elem->south.path);
	if (!config->south_path)
		return (custom_write("Malloc error\n"), free_config(config), false);
	config->east_path = ft_strdup(elem->east.path);
	if (!config->east_path)
		return (custom_write("Malloc error\n"), free_config(config), false);
	config->west_path = ft_strdup(elem->west.path);
	if (!config->west_path)
		return (custom_write("Malloc error\n"), free_config(config), false);
	config->floor_color = elem->floor.color;
	config->ceiling_color = elem->ceiling.color;
	return (true);
}
//t_elem struct -> t_config
//Then the map is validated and we init_map
//Or the map is not valid and we free config 
void	a_to_z(int ac, char **av, t_game *game)
{
	int	fd;
	t_elem	elem;
	t_chain	*chain;

	if (!is_cub_file(ac, av))
		exit(EXIT_FAILURE);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		custom_write("fd open error\n");
		exit(EXIT_FAILURE);
	}
	if (!init_elem(fd, &elem))
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!init_config(game->config, &elem))
	{
		close(fd);
		exit(EXIT_FAILURE);//We need to free the t_elem struct 
	}
	chain = init_chain(fd);
	if (!chain)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!init_map(game, chain))
	{
		close(fd);
		free_chain(chain);
		exit(EXIT_FAILURE);
	}
	free_chain(chain);





	


