/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 11:45:28 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 16:00:37 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	validate_int(char *elem)
{
	unsigned int	i;

	i = 0;
	if (elem[i] == '-' || elem[i] == '+')
		i++;
	if (!elem[i])
		return (true);
	while (elem[i])
	{
		if (!ft_isdigit(elem[i]))
			return (true);
		i++;
	}
	return (false);
}

void	insert_sorted(int n, int *data, int size)
{
	int	i;

	i = size;
	while (--i >= 0 && data[i] > n)
		data[i + 1] = data[i];
	data[i + 1] = n;
}

static bool	already_exists(int n, t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 0)
	{
		if (stack->array[i] == n)
			return (true);
		i--;
	}
	return (false);
}

static int	fill_element(t_stack *stack, char *arg)
{
	unsigned int	j;
	int				n;
	int				status;
	char			**array;

	j = 0;
	status = 0;
	array = ft_split(arg, SPACE);
	if (!array || !array[0])
	{
		if (array)
			message_and_exit(stack, NULL, status);
		return (1);
	}
	while (array[j] && !status)
	{
		if (validate_int(array[j]))
			status = 1;
		if (atoiv(array[j], &n))
			status = 2;
		if (already_exists(n, stack))
			status = 3;
		else
			stack->array[++stack->top] = n;
		j++;
	}
	free_array((void **)array);
	return (status);
}

t_stack	*get_stack(int size, char **args)
{
	unsigned int	i;
	int				status;
	t_stack			*stack;

	if (size < 1)
		exit(0);
	i = 0;
	status = 0;
	stack = initialize(STACK_BUFFER);
	while (args[i] && !status)
		status = fill_element(stack, args[i++]);
	if (status)
	{
		free_stack(stack);
		ft_putendl_fd("Error", STDERR_FILENO);
		exit(status);
	}
	reverse_array(stack->array, stack->top + 1);
	return (stack);
}
