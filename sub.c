/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasao <kasao@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 21:21:11 by kasao             #+#    #+#             */
/*   Updated: 2020/08/16 21:21:32 by kasao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_map(char map[4][4]);

int		box_count(int dir, char map[4][4])
{
	int		i;
	int		j;
	char	hight;
	int		cnt;

	hight = '0';
	cnt = 0;
	i = 0;
	while (i < 4)
	{
		j = ((dir / 4) % 2) ? (3 - i) : (i);
		if (hight < map[dir % 4][j] && dir / 8 == 1)
		{
			cnt++;
			hight = map[dir % 4][j];
		}
		if (hight < map[j][dir % 4] && dir / 8 == 0)
		{
			cnt++;
			hight = map[j][dir % 4];
		}
		i++;
	}
	return (cnt);
}

int		check_pers(int row, int col, char map[4][4], char pers[4][4])
{
	int i;
	int cnt;

	i = 0;
	while (i < 16)
	{
		if (((i / 8) && (i % 4 == row)) || (!(i / 8) && (i % 4 == col)))
		{
			if ((col == 3 && i / 8) || (row == 3 && !(i / 8)))
			{
				cnt = box_count(i, (char(*)[4])(map));
				if (cnt != pers[i / 4][i % 4] - '0')
					return (0);
			}
		}
		i++;
	}
	return (1);
}

int		check_x(int row, int col, int c, char map[4][4])
{
	int i;

	i = 0;
	while (i < col)
	{
		if (map[row][i] == c)
			return (0);
		i++;
	}
	i = 0;
	while (i < row)
	{
		if (map[i][col] == c)
			return (0);
		i++;
	}
	return (1);
}

int		solve(int row, int col, char map[4][4], char pers[4][4])
{
	char	c;
	int		check;

	c = '1';
	while (c <= '4')
	{
		if (check_x(row, col, c, map))
		{
			map[row][col] = c;
			check = col == 3 || row == 3 ? check_pers(row, col, map, pers) : 1;
			if (check)
			{
				if (col == 3 && row == 3)
				{
					print_map(map);
					return (1);
				}
				if (solve((row * 4 + col + 1) / 4,
					(row * 4 + col + 1) % 4, map, pers))
					return (1);
			}
		}
		c++;
	}
	return (0);
}
