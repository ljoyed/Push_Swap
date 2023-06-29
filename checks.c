/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 12:55:45 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/27 10:51:12 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_a_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (0);
	else
		return (1);
}

static int	is_a_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
		i++;
	while (str[i])
	{
		if (is_a_digit(str[i]) == 0)
			i++;
		else
			return (1);
	}
	return (0);
}

static bool	is_in_int_range(char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	num = sign * num;
	if (num >= INT_MIN && num <= INT_MAX)
		return (true);
	else
		return (false);
}

void	check_duplicates(int *num, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] == num[j])
			{
				free(num);
				write(1, "Error\n", 6);
				exit (EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	checker(char **str)
{
	int	i;

	i = 0;
	if (!str[i])
		exit_err(str);
	while (str[i])
	{
		if (is_a_num(str[i]) == 0)
		{
			if (is_in_int_range(str[i]) == true)
				i++;
			else
				exit_err(str);
		}
		else
			exit_err(str);
	}
}
