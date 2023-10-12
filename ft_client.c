/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:11:51 by mschaub           #+#    #+#             */
/*   Updated: 2023/01/27 17:43:10 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_check_args(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (0);
	return (1);
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("1234567890", argv[1][i]))
			return (0);
		return (1);
	}
}

void	ft_send_sig(int pid, char a)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if ((a & (00000001 << j)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (ft_check_args(argc, argv) == 1)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_sig(pid, argv[2][i]);
			i++;
		}
		ft_send_sig(pid, '\n');
	}
	else
	{
		write(STDOUT_FILENO, "Wrong format!", 13);
	}
}
