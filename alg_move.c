/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 09:32:14 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/29 16:45:46 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rrr_both:
Reverse rotates both stack A and B until one of them is in position.
The given cost is negative since both positions are in the bottom half
of their respective stacks. The cost is increased as the stacks are
rotated, when one reaches 0, the stack has been rotated as far as possible
and the top position is correct.
*/

static void	rrr_both(t_mystr **a, t_mystr **b,
												int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

/* do_rotate_both:
Rotates both stack A and B until one of them is in position.
The given cost is positive since both positions are in the top half
of their respective stacks. The cost is decreased as the stacks are
rotated, when one reaches 0, the stack has been rotated as far as possible
and the top position is correct.
*/

static void	rr_both(t_mystr **a, t_mystr **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

static void	rotate_a(t_mystr **a, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
	}
}

static void	rotate_b(t_mystr **b, int *cost)
{
	while (*cost)
	{
		if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
	}
}

/* move:
Chooses which move to make to get the B stack element to the correct
position in stack A.
If the costs of moving stack A and B into position match (i.e. both negative
of both positive), both will be	rotated or reverse rotated at the same time.
They might also be rotated separately, before finally pushing the top B element
to the top stack A.
*/

void	move(t_mystr **a, t_mystr **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rrr_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rr_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	pa(a, b);
}
