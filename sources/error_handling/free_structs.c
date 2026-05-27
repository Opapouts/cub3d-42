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
	}
}

void	free_config(t_config *config)
{
	free(config->north_path);
	free(config->south_path);
	free(config->east_path);
	free(config->west_path);
	free(config);
}
