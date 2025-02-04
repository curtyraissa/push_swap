/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:59:24 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/01/30 10:50:35 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		sort_small(t_stacks *stacks);
void		radix_sort(t_stacks *stacks);
void		parse_numbers(t_stacks *stacks);
void		create_index(t_stacks *stacks);
void		initialize_stacks(int argc, char **argv, t_stacks *stacks);
void		free_and_exit(t_stacks *stacks, char *error_message);
void		check_sorted_or_duplicate(t_stacks *stacks, int i);
int			is_sorted(t_stacks *stacks);
int			ft_atoi_ps(const char *str, t_stacks *stacks);

#endif