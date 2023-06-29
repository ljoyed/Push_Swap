/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:57:38 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/27 11:08:03 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exit_err(char **str)
{
	free_args(str);
	write(1, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	free_args(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_mystr *stack)
{
	t_mystr	*tmp;
	t_mystr	*current;

	current = stack;
	while (current != NULL)
	{
		tmp = current;
		current = current->next;
		free(tmp);
	}
}
