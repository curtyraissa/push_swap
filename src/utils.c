/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:31:48 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/01/30 10:46:41 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_sorted_or_duplicate(t_stacks *stacks, int i)
{
	int	j;

	j = 0;
	if (i == 0)
	{
		while (i < stacks->a_size)
		{
			j = i + 1;
			while (j < stacks->a_size)
			{
				if (stacks->a[i] == stacks->a[j])
					free_and_exit(stacks, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_sorted(stacks))
		free_and_exit(stacks, NULL);
}

void	parse_numbers(t_stacks *stacks)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(stacks->join_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		stacks->a[z++] = ft_atoi_ps(tmp[i++], stacks);
		free(tmp[i - 1]);
	}
	free(tmp);
}

void	initialize_stacks(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
	while (--argc)
	{
		if (ft_count_words(argv[i + 1], ' '))
			stacks->a_size += ft_count_words(argv[i + 1], ' ');
		else
			stacks->a_size++;
		i++;
	}
	stacks->a = malloc(stacks->a_size * sizeof * stacks->a);
	if (stacks->a == NULL)
		free_and_exit(stacks, "Error\n");
	stacks->b = malloc(stacks->a_size * sizeof * stacks->b);
	if (stacks->b == NULL)
		free_and_exit(stacks, "Error\n");
}

void	create_index(t_stacks *stacks)
{
	int		i;
	int		j;
	int		k;
	int		*new_a;

	new_a = malloc(stacks->a_size * sizeof * new_a);
	if (new_a == NULL)
		free_and_exit(stacks, "Error\n");
	i = -1;
	while (++i < stacks->a_size)
	{
		k = 0;
		j = -1;
		while (++j < stacks->a_size)
			if (stacks->a[i] > stacks->a[j])
				k++;
		new_a[i] = k;
	}
	i = stacks->a_size;
	while (i--)
		stacks->a[i] = new_a[i];
	free(new_a);
}

int	ft_atoi_ps(const char *str, t_stacks *stacks)
{
	int	i;
	int	sig;
	int	res;

	i = 0;
	sig = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if ((str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			sig = -1;
		i++;
	}
	while (str[i])
	{
		if (res > INT_MAX / 10
			|| (res == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
			free_and_exit(stacks, "Error\n");
		if (!(str[i] >= '0' && str[i] <= '9'))
			free_and_exit(stacks, "Error\n");
		res = res * 10 + (str[i++] - '0');
	}
	return (res * sig);
}
