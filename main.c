/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:20:30 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/27 15:16:42 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count(int argc, char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**args;

	i = 1;
	count = 0;
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		checker(args);
		while (args[j])
			j++;
		i++;
		count = count + j;
		free_args(args);
	}
	return (count);
}

static int	*numbers(int argc, char **argv, int count)
{
	int		i;
	int		j;
	int		k;
	char	**args;
	int		*num;

	i = 1;
	k = 0;
	num = malloc(sizeof(int) * count);
	while (i < argc)
	{
		j = 0;
		args = ft_split(argv[i], ' ');
		while (args[j])
		{
			num[k] = ft_atoi(args[j]);
			k++;
			j++;
		}
		i++;
		free_args(args);
	}
	return (num);
}

static void	begin_ops(t_mystr **stack_a, t_mystr **stack_b, int count)
{
	if (count <= 3 && (!is_sorted(*stack_a)))
		sort_3(stack_a);
	else if ((!is_sorted(*stack_a)))
		sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	int		count;
	int		*nums;
	t_mystr	*stack_a;
	t_mystr	*stack_b;

	if (argc < 2)
		return (0);
	count = ft_count(argc, argv);
	nums = numbers(argc, argv, count);
	check_duplicates(nums, count);
	stack_a = fill_stack_values(nums, count);
	stack_b = NULL;
	stack_a = assign_index(stack_a, count);
	free(nums);
	begin_ops(&stack_a, &stack_b, count);
	free_stack(stack_a);
	return (0);
}
