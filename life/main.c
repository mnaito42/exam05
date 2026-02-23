/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaito <mnaito@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:22:33 by mnaito            #+#    #+#             */
/*   Updated: 2026/02/23 20:34:40 by mnaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "life.h"

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define ALIVE 'O'
#define DEAD ' '

typedef	struct s_life
{
    int width;
    int height;
    int iteration;

    char **grid;
    char **next;

    int w_now;
    int h_now;
    int is_writing;
}	t_life;

t_life	l;

char	**create_board()
{
	char **ret;

	ret = (char **)calloc(sizeof(char *), l.height + 2);
	int i = 0;
	int j;
	while (i < l.height + 2)
	{
		ret[i] = (char *)calloc(sizeof(char), l.width + 2);
		if (i != 0 && i != l.height + 1)
		{
			j = 1;
			while (j < l.width + 1)
			{
				ret[i][j] = DEAD;
				j++;
			}
		}
		i++;
	}
	return (ret);
}

void	read_and_init_board()
{
	char c;
	l.w_now = 1;
	l.h_now = 1;
	l.is_writing = 0;
	while (read(0, &c, 1) > 0)
    {
        if (c == 'w' && 1 < l.h_now)
            l.h_now--;
        else if (c == 's' && l.h_now < l.height)
            l.h_now++;
        else if (c == 'a' && 1 < l.w_now)
            l.w_now--;
        else if (c == 'd' && l.w_now < l.width)
            l.w_now++;
        else if (c == 'x')
            l.is_writing = !l.is_writing;

        if (l.is_writing)
            l.grid[l.h_now][l.w_now] = ALIVE;
    }
}

int	count_neighbours(int h, int w)
{
	int ret;

	ret = 0;
	if (l.grid[h - 1][w - 1] == ALIVE)
		ret++;
	if (l.grid[h - 1][w] == ALIVE)
		ret++;
	if (l.grid[h - 1][w + 1] == ALIVE)
		ret++;
	if (l.grid[h][w - 1] == ALIVE)
		ret++;
	if (l.grid[h][w + 1] == ALIVE)
		ret++;
	if (l.grid[h + 1][w - 1] == ALIVE)
		ret++;
	if (l.grid[h + 1][w] == ALIVE)
		ret++;
	if (l.grid[h + 1][w + 1] == ALIVE)
		ret++;
	return (ret);
}

void	update_board()
{
	int i;
	int j;
	int nbs;

	i = 1;
	while (i < l.height + 1)
	{
		j = 1;
		while (j < l.width + 1)
		{
			nbs = count_neighbours(i, j);
			if (l.grid[i][j] == ALIVE && (nbs == 2 || nbs == 3))
				l.next[i][j] = ALIVE;
			else if (l.grid[i][j] == DEAD && nbs == 3)
				l.next[i][j] = ALIVE;
			else
				l.next[i][j] = DEAD;
			j++;
		}
		i++;
	}
}

void	swap_board()
{
	char **tmp;

	tmp = l.grid;
	l.grid = l.next;
	l.next = tmp;
}

void	print_board()
{
	int	i;
	int	j;

	i = 1;
	while (i < l.height + 1)
	{
		j = 1;
		while (j < l.width + 1)
		{
			putchar(l.grid[i][j]);
			j++;
		}
		putchar('\n');
		i++;
	}
}

void	free_board(char **board)
{
	int i;

	i = 0;
	while (i < l.height + 2)
	{
		free(board[i]);
		i++;
	}
	free(board);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
		
    l.width = atoi(argv[1]);
    l.height = atoi(argv[2]);
    l.iteration = atoi(argv[3]);

	if (l.width <= 0 || l.height <= 0 || l.iteration < 0)
        return (1);

	l.grid = create_board();
	l.next = create_board();

	read_and_init_board();

	int i;
	i = 0;
	while (i < l.iteration)
	{
		update_board();
		swap_board();
		i++;
	}

	print_board();

	free_board(l.grid);
	free_board(l.next);
}
