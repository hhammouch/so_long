/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammouc <hhammouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 23:00:38 by hhammouc          #+#    #+#             */
/*   Updated: 2025/03/27 13:01:24 by hhammouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_check(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i < 5 || path[i - 1] != 'r' || path[i - 2] != 'e' || path[i - 3] != 'b'
		|| path[i - 4] != '.' || path[i - 5] == '/')
		print_error("Invalid map file extension.");
}

char	*read_file(int fd)
{
	char	*line;
	char	*temp_map;
	char	*temp;

	temp_map = NULL;
	line = get_next_line(fd);
	while (line)
	{
		if (!temp_map)
			temp_map = ft_strdup(line);
		else
		{
			temp = temp_map;
			temp_map = ft_strjoin(temp_map, line);
			free(temp);
		}
		if (line[0] == '\n' || line[0] == '\0')
			print_error("Map is not rectangular.");
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (temp_map);
}

char	**read_map(const char *file_path)
{
	int		fd;
	char	*temp_map;
	char	**map;

	path_check((char *)file_path);
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		print_error("Failed to open the map file.");
	temp_map = read_file(fd);
	close(fd);
	if (!temp_map)
		print_error("Map is empty.");
	map = ft_split(temp_map, '\n');
	free(temp_map);
	return (map);
}
