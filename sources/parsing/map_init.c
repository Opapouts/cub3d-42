#include "../../includes/cub3d.h"

static	bool	skip_empty_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (is_empty_line(line))
	{
		custom_free(line);
		line = get_next_line(fd);
		if (!line)
			return (custom_write("Gnl error"), false);
	}
	return (true);
}

bool	init_chain(int fd, t_chain **chain)
{
	char	*line;
	t_chain	*tmp;

	if (!skip_empty_lines(fd))
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		tmp = new_node(line);
		if (!new_node(line))
			return (custom_free(line), free_chain(*chain), false);
		add_node(chain, tmp);
		line = get_next_line(fd);
	}
	return (true);
}

static	bool	chain_to_array(t_game *game, t_chain *chain)
{
	int		i;
	t_chain *tmp;

	i = 0;
	tmp = NULL;
	game->map = malloc(sizeof(char *) * (size_of_chain(chain) + 1));
	if (!game->map)
		return (custom_write("Malloc error\n"), false);
	tmp = chain;
	while (tmp)
	{
		game->map[i++] = ft_strdup(tmp->line);
		if (!game->map[i - 1])
		{
			i--;
			while (i >= 0)
				custom_free(game->map[i--]);
			free(game->map);
			return (false);
		}
		tmp = tmp->next;
	}
	game->map[i] = NULL;
	return (true);
}

bool	init_game(t_game *game, t_chain *chain)
{
	if (!is_valid_char(chain))
		return (false);
	if (!is_single_player(chain))
		return (false);
	if (!chain_to_array(game, chain))
		return (false);

