/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:31:05 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/29 16:50:20 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	position(t_mystr **stack)
{
	t_mystr	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

int	lowest_position(t_mystr **stack)
{
	t_mystr	*tmp;
	int		lowest_ind;
	int		lowest_pos;

	tmp = *stack;
	lowest_ind = INT_MAX;
	position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->ind < lowest_ind)
		{
			lowest_ind = tmp->ind;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* get_target:
Picks the best target position in stack A for the given index of
an element in stack B. First checks if the index of the B element can
be placed somewhere in between elements in stack A, by checking whether
there is an element in stack A with a bigger index. If not, it finds the
element with the smallest index in A and assigns that as the target position.
*/

static int	target(t_mystr **a, int b_ind,
								int target_ind, int target_pos)
{
	t_mystr	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->ind > b_ind && tmp_a->ind < target_ind)
		{
			target_ind = tmp_a->ind;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_ind != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->ind < target_ind)
		{
			target_ind = tmp_a->ind;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* target_position:
Assigns a target position in stack A to each element of stack A.
The target position is the spot the element in B needs to
get to in order to be sorted correctly. This position will
be used to calculate the cost of moving each element to
its target position in stack A.
*/

void	target_position(t_mystr **a, t_mystr **b)
{
	t_mystr	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	position(a);
	position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = target(a, tmp_b->ind, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
