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


static void	init_config(t_config *config, t_elem *elem)
{
	set_config_to_null(config);
	config->north_path = elem->north.path;
	config->south_path = elem->south.path;
	config->east_path = elem->east.path;
	config->west_path = elem->west.path;
	config->floor_color = elem->floor.color;
	config->ceiling_color = elem->ceiling.color;
}

static void	nullify_elem(t_elem *elem)
{
	elem->north.path = NULL;
	elem->south.path = NULL;
	elem->east.path = NULL;
	elem->west.path = NULL;
}

//t_elem struct -> t_config
//Then the map is validated and we init_map
//Or the map is not valid and we free config 
bool	parsing(int ac, char **av, t_game *game)
{
	int	fd;
	t_elem	elem;
	t_chain	*chain;

	if (!is_cub_file(ac, av))
		return (false);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (custom_write("fd open error\n"), false);
	if (!init_elem(fd, &elem))
		return (close(fd), false);
	init_config(&game->config, &elem);
	nullify_elem(&elem);
	chain = init_chain(fd);
	if (!chain)
		return (close(fd), free_config(&game->config), false);
	if (!init_map(game, chain))
		return (free_chain(chain), free_config(&game->config), close(fd), false);
	return (free_chain(chain), close(fd), true);
}
