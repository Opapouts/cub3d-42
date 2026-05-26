#include "../../includes/cub3d.h"

static	void	find_player(char **map, int *j, int *i)
{
	while (map[*j])
	{
		*i = 0;
		while (map[*j][*i])
		{
			if (map[*j][*i] == 'N' || map[*j][*i] == 'S' || map[*j][*i] == 'E'
					|| map[*j][*i] == 'W')
				return ;
			(*i)++;
		}
		(*j)++;
	}
}
//1st step->Put V 
//2nd step->Try Up
//If 0 or space call the function for that coordinate
//If wall move to next check
//3rd step->Try down(same logic as before)
//4th step->Try left(same)
//5th step->Try right(same)
//Return
//The failure condition: If the current position is at the edge 
//of the array the map is invalid

bool	flood_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	find_player(map, &j, &i);


