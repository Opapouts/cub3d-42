#include "../../includes/cub3d.h"

//Here we will write down all the functions needed for the t_map chained list

t_chain	*new_node(char *line)
{
	t_chain	*list;

	if (*line)
		return (NULL);
	list = malloc(sizeof(t_chain));
	if (!list)
		return (custom_write("malloc error"), NULL);
	list->line = ft_strdup(line);
	custom_free(line);
	if (!list->line)
		return (custom_write("malloc error"), NULL);
	list->next = NULL;
	return (list);
}

void	add_node(t_chain **list, t_chain *node)
{
	t_chain	*tmp;

	if (!list || !node)
		return ;
	if (!*list)
	{
		*list = node;
		return ;
	}
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

int	size_of_chain(t_chain *chain)
{
	int	i;

	i = 0;
	while (chain)
	{
		chain = chain->next;
		i++;
	}
	return (i);
}
