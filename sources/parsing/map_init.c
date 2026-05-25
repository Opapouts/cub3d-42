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

bool	init_array(int fd, t_chain **chain)
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

bool	init_game(t_game *game, t_chain *chain)
{
	if (!is_valid_char(chain))
		return (false);
	if (!is_single_player(chain))
		return (false);

