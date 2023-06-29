/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:08:50 by loandrad          #+#    #+#             */
/*   Updated: 2023/06/28 10:28:39 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct mystr
{
	int				num;
	int				ind;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct mystr	*next;
}					t_mystr;

//checks
void	check_duplicates(int *num, int len);
void	checker(char **str);

//exit
int		exit_err(char **str);
void	free_args(char **str);
void	free_stack(t_mystr *stack);

//utils
int		ft_atoi(const char *ptr);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		ft_abs(int num);

//operations
void	pa(t_mystr **stack_a, t_mystr **stack_b);
void	pb(t_mystr **stack_a, t_mystr **stack_b);
void	ra(t_mystr **stack_a);
void	rb(t_mystr **stack_b);
void	rr(t_mystr **stack_a, t_mystr **stack_b);
void	rra(t_mystr **stack_a);
void	rrb(t_mystr **stack_b);
void	rrr(t_mystr **stack_a, t_mystr **stack_b);
void	sa(t_mystr **stack_a);
void	sb(t_mystr **stack_b);
void	ss(t_mystr **stack_a, t_mystr **stack_b);

//stack related
t_mystr	*stack_last(t_mystr *stack);
t_mystr	*stack_second_last(t_mystr *stack);
void	stack_add_last(t_mystr **stack, t_mystr *new);
t_mystr	*stack_new(int value);
t_mystr	*fill_stack_values(int *numbers, int len);
t_mystr	*assign_index(t_mystr *stack, int count);
int		stack_size(t_mystr	*stack);
int		is_sorted(t_mystr *stack);

//position
int		lowest_position(t_mystr **stack);
void	target_position(t_mystr **a, t_mystr **b);

//cost
void	get_cost(t_mystr **stack_a, t_mystr **stack_b);
void	cheapest_move(t_mystr **stack_a, t_mystr **stack_b);

//move
void	move(t_mystr **a, t_mystr **b, int cost_a, int cost_b);

//sort
void	sort_3(t_mystr **stack);
void	sort(t_mystr **stack_a, t_mystr **stack_b);

#endif
