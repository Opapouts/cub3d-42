#include "../../includes/cub3d.h"

void	free_chain(t_chain *chain)
{
	t_chain *tmp;

	while (chain)
	{
		
		tmp = chain;
		custom_free(chain->line);
		chain = chain->next;
		free(tmp);
		tmp = NULL;
	}
}

void	free_config(t_config *config)
{
	custom_free(config->north_path);
	custom_free(config->south_path);
	custom_free(config->east_path);
	custom_free(config->west_path);
	config = NULL;
}

void	free_elem(t_elem *elem)
{
	custom_free(elem->north.path);
	custom_free(elem->south.path);
	custom_free(elem->east.path);
	custom_free(elem->west.path);
	custom_free(elem->line);
	elem = NULL;
}
