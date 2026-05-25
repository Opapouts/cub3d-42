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

