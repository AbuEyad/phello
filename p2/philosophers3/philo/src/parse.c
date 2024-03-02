/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habu-zua <habu-zua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:24:13 by habu-zua          #+#    #+#             */
/*   Updated: 2024/03/02 11:14:06 by habu-zua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_instruction(void)
{
	printf("WRONG INPUT!\n");
	printf("Usage: ./philo <nb_philos> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep> ");
	printf("<number_of_meals> ");
	printf("(optional argument)\n");
}

int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (is_space (str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + (str[i++] - '0');
	while (is_space(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (result);
}

int	check_input(int argc, char **argv)
{
	if (argc < 5)
		return (WRONG_INPUT);
	if (argc > 6)
		return (WRONG_INPUT);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (WRONG_INPUT);
	while (argc > 1)
	{
		if (ft_atoi(argv[argc - 1]) <= 0)
			return (WRONG_INPUT);
		argc--;
	}
	return (0);
}
