#include "../../includes/cub3d.h"

// ***Overhead t_elem struct***
//We will need to transform this list into a 2d array
bool	is_valid_char(t_chain *chain)
{
	int	i;

	while (chain)
	{
		i = 0;
		while (chain->line[i])
		{
			if (chain->line[i] != '0' && chain->line[i] != '1'
					&& chain->line[i] != 'N' && chain->line[i] != 'S'
					&& chain->line[i] != 'E' && chain->line[i] != 'W'
					&& chain->line[i] != ' ')
				return (custom_write("Not allowed character found"), 
					free_chain(chain), false);
			i++;
		}
		chain = chain->next;
	}
	return (true);
}

//The map must be completely closed/surrounded by walls (1).
bool	is_single_player(t_chain *chain)
{
	int	players;
	int	i;

	players = 0;
	while (chain)
	{
		i = 0;
		while (chain->line[i])
		{
			if (chain->line[i] == 'N' || chain->line[i] == 'S'
					|| chain->line[i] == 'E' || chain->line[i] == 'W')
				players++;
			i++;
		}
		chain = chain->next;
	}
	if (players != 1)
		return (custom_write("Multiple players detected"), free_chain(chain), false);
	return (true);
}
//I am thinking of doing a wrapper function that will take as code left or right, and it will
//check if there is a 1 at the edge or spaces and after a 1.Do we really need two functions
//for left and right? We will have this check everywhere so I can make a single function 
//that makes sure that each line is like this  "    1000000101  "
static bool	left_wall(t_chain *chain)
{
	int	i;

	while (chain)
	{
		if (

bool	is_map_closed(t_chain *chain)
{

