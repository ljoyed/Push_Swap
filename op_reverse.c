/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:12:17 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/22 18:15:38 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_mystr **stack)
{
	t_mystr	*head;
	t_mystr	*tail;

	head = *stack;
	*stack = (*stack)->next;
	tail = stack_last(*stack);
	head->next = NULL;
	tail->next = head;
}

void	ra(t_mystr **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_mystr **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_mystr **stack_a, t_mystr **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
