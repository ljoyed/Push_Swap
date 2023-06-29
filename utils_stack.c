/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:16:10 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/27 15:19:54 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	stack_size(t_mystr	*stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	is_sorted(t_mystr *stack)
{
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_mystr	*assign_index(t_mystr *stack, int count)
{
	t_mystr	*highest;
	t_mystr	*current;
	int		target;

	while (count > 0)
	{
		highest = NULL;
		target = INT_MIN;
		current = stack;
		while (current != NULL)
		{
			if (current->num >= target && current->ind == 0)
			{
				target = current->num;
				highest = current;
			}
			current = current->next;
		}
		if (highest != NULL)
			highest->ind = count;
		count--;
	}
	return (stack);
}
