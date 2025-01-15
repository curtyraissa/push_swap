/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcurty-g <rcurty-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:51:26 by rcurty-g          #+#    #+#             */
/*   Updated: 2025/01/10 16:36:32 by rcurty-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_and_exit(t_stacks *stacks, char *error_message)
{
	if (error_message)
		write(2, error_message, ft_strlen(error_message));
	if (stacks)
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks->join_args);
		free(stacks);
	}
	exit(1);
}

static void	validate_arguments(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (!argv[i][0] || argv[i][0] == ' ')
				free_and_exit(NULL, "Error\n");
			j = 0;
			while (argv[i][j])
			{
				if ((!(ft_isdigit(argv[i][j])) && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				|| ((argv[i][j] == '-' || argv[i][j] == '+')
				&& (argv[i][j + 1] == '\0' || argv[i][j + 1] == ' ')))
					free_and_exit(NULL, "Error\n");
				j++;
			}
			i++;
		}
	}
	else
		free_and_exit(NULL, "Error\n");
}

static void	join_args(int argc, char **argv, t_stacks *stacks)
{
	char	*current;
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		current = ft_strjoin(result, argv[i]);
		if (result)
			free(result);
		if (i != argc - 1)
		{
			result = ft_strjoin(current, " ");
			if (current)
				free(current);
			current = result;
		}
	}
	stacks->join_args = ft_strdup(current);
	if (stacks->join_args == NULL)
		free_and_exit(stacks, "Error\n");
	if (current)
		free(current);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	validate_arguments(argc, argv);
	stacks = malloc(sizeof * stacks);
	if (stacks == NULL)
		exit(1);
	initialize_stacks(argc, argv, stacks);
	join_args(argc, argv, stacks);
	parse_numbers(stacks);
	check_sorted_or_duplicate(stacks, 0);
	create_index(stacks);
	if (stacks->a_size == 2 && stacks->a[0] > stacks->a[1])
		swap("sa", stacks->a, stacks->a_size);
	else if (stacks->a_size == 3)
		sort_three(stacks);
	else if (stacks->a_size >= 4 && stacks->a_size <= 5)
		sort_small(stacks);
	else
		radix_sort(stacks);
	check_sorted_or_duplicate(stacks, 1);
	free_and_exit(stacks, "Error\n");
	return (0);
}
