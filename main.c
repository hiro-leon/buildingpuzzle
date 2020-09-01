/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasao <kasao@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:19:16 by kasao             #+#    #+#             */
/*   Updated: 2020/08/16 21:20:45 by kasao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		solve(int row, int clo, char map[4][4], char pers[4][4]);

void	print_map(char map[4][4])
{
	int i;

	i = 0;
	while (i < 16)
	{
		write(1, &map[i / 4][i % 4], 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		else
			write(1, " ", 1);
		i++;
	}
}

int		parts_list(char pers[4][4], char argv[31])
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (argv[31] != '\0')
		return (0);
	while (i != 32)
	{
		if (argv[i] >= '1' && argv[i] <= '4')
		{
			pers[i / 8][(i % 8) / 2] = argv[i];
			count++;
		}
		i += 2;
	}
	if (count != 16)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char	map[4][4];
	char	pers[4][4];
	int		i;

	argc = argc + 0;
	if (!(parts_list(pers, argv[1])))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (i < 16)
	{
		map[i / 4][i % 4] = '0';
		i++;
	}
	i = 0;
	i = solve(0, 0, map, pers);
	if (!i)
		write(1, "Error\n", 6);
	return (0);
}
