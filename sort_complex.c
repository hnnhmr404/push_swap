/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:44:50 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 15:43:12 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	smart_rotate_a(a, to_move);
	run(PA, a, b);
}

static void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_min_or_max_to_top(b);
		put_in_position(a, b);
	}
}

static void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	size;
	int	mid;

	size = max - min + 1;
	mid = min + (size / 2);
	while (size && a->top >= 0)
	{
		move_to_top(a, min, max);
		run(PB, a, b);
		if (b->top > 0 && b->array[b->top] < mid)
			run(RB, NULL, b);
		size--;
	}
}

static size_t	get_chunks(t_stack *a)
{
	size_t	size;

	size = a->top + 1;
	if (size <= 100)
		return (5);
	else if (size <= 500)
		return (11);
	return (size / CHUNK_CONSTANT + 1);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int		limit_min;
	int		limit_max;
	size_t	chunks;
	size_t	step;
	size_t	c;

	chunks = get_chunks(a);
	step = (a->top + 1) / chunks;
	limit_min = min(a);
	c = 1;
	while (c <= chunks)
	{
		if (c == chunks)
			limit_max = max(a);
		else
			limit_max = limit_min + step - 1;
		move_chunk(a, b, limit_min, limit_max);
		limit_min = limit_max + 1;
		c++;
	}
	sort_chunk(a, b);
	smart_rotate_a(a, min(a));
}
