/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 10:34:58 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/22 13:52:18 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_mystr *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp;
	tmp = stack->ind;
	stack->ind = stack->next->ind;
	stack->next->ind = tmp;
}

void	sa(t_mystr **stack_a)
{
	swap(*stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_mystr **stack_b)
{
	swap(*stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_mystr **stack_a, t_mystr **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	write(1, "ss\n", 3);
}
