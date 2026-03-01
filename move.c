/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:30:27 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/03/01 13:14:11 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	between(int n, int min, int max)
{
	return (n >= min && n <= max);
}

static int	find_from_top(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (between(a->array[i], min, max))
			return (i);
		i++;
	}
	return (-1);
}

static int	find_from_bottom(t_stack *a, int min, int max)
{
	int	i;

	i = a->top;
	while (i >= 0)
	{
		if (between(a->array[i], min, max))
			return (i);
		i--;
	}
	return (-1);
}

void	move_to_top(t_stack *a, int min, int max)
{
	int	i;
	int	index[2];
	int	dist_bottom;
	int	dist_top;

	index[0] = find_from_top(a, min, max);
	index[1] = find_from_bottom(a, min, max);
	dist_bottom = index[0] + 1;
	dist_top = a->top - index[1];
	if (dist_bottom < dist_top)
		i = index[0];
	else
		i = index[1];
	smart_rotate_a(a, a->array[i]);
}

void	move_min_or_max_to_top(t_stack *b)
{
	int	i;
	int	index[2];
	int	dist_min;
	int	dist_max;

	index[0] = _index(b, min(b));
	index[1] = _index(b, max(b));
	if (index[0] < b->top / 2)
		dist_min = index[0] + 1;
	else
		dist_min = b->top - index[0];
	if (index[1] < b->top / 2)
		dist_max = index[1] + 1;
	else
		dist_max = b->top - index[1];
	if (dist_min < dist_max)
		i = index[0];
	else
		i = index[1];
	smart_rotate_b(b, b->array[i]);
}
