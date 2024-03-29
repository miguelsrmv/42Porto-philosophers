/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-sa-- <mde-sa--@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:33:22 by mde-sa--          #+#    #+#             */
/*   Updated: 2024/03/26 18:41:23 by mde-sa--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_args(int argc, char **argv)
{
	if (is_argc_inadequate(argc) == true)
		return (ARG_ERROR);
	if (arg_has_non_digit_chars(argv) == true)
		return (ARG_ERROR);
	if (is_arg_larger_than_int(argv) == true)
		return (ARG_ERROR);
	return (SUCCESS);
}

bool	is_argc_inadequate(int argc)
{
	if (argc < 5 || argc > 6)
	{
		ft_printf(ARG_MESSAGE);
		return (true);
	}
	return (false);
}

bool	arg_has_non_digit_chars(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j++]))
			{
				ft_printf(ARG_MESSAGE);
				return (true);
			}
		}
		i++;
	}
	return (false);
}

bool	is_arg_larger_than_int(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 10)
			return (true);
		if (ft_atol(argv[i]) > INT_MAX)
			return (true);
		i++;
	}
	return (false);
}
