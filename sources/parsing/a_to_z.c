#include "../../includes/cub3d.h"
//The role of this function is to do the full parsing phase from beginning to end
//This function will receive a string and open that file etc etc
//We first open the file.
//Things I need to add
//1)Freeing elem struct after I am done using it
//2)Initialise the t_config field of t_game struct
//3)Make function to execute repetitive actions
//4)Be better
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
	chain = init_chain(fd);
	if (!chain)
	{
		close(fd);
		exit(EXIT_FAILURE);
	}
	if (!init_game(game, chain))
	{
		close(fd);
		free_chain(chain);
		exit(EXIT_FAILURE);
	}
	free_chain(chain);





	


