/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:46:29 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/25 18:54:53 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(t_mystr **stack)
{
	t_mystr	*tmp;
	t_mystr	*tail;
	t_mystr	*second_last;

	tail = stack_last(*stack);
	second_last = stack_second_last(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	second_last->next = NULL;
}

void	rra(t_mystr **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_mystr **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_mystr **stack_a, t_mystr **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
