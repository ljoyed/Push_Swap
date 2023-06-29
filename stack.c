/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:09:02 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/25 16:32:32 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mystr	*stack_last(t_mystr *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_mystr	*stack_second_last(t_mystr *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_last(t_mystr **stack, t_mystr *new)
{
	t_mystr	*tail;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tail = stack_last(*stack);
	tail->next = new;
}

t_mystr	*stack_new(int value)
{
	t_mystr	*new;

	new = malloc(sizeof(t_mystr));
	if (!new)
		return (NULL);
	new->num = value;
	new->ind = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

t_mystr	*fill_stack_values(int *numbers, int len)
{
	t_mystr	*stack_a;
	t_mystr	*current;
	t_mystr	*new;
	int		i;

	i = 0;
	stack_a = stack_new(numbers[i]);
	current = stack_a;
	i++;
	while (i < len)
	{
		new = stack_new(numbers[i]);
		current->next = new;
		current = new;
		i++;
	}
	return (stack_a);
}
