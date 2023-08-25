/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:12:56 by nolahmar          #+#    #+#             */
/*   Updated: 2023/08/24 15:09:49 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_cmd *cmd, t_env *env)
{
	int	i;

	i = 0;
	if (!cmd->args[1])
	{
		while (env[i])
		{
			if (ft_strchr(env[i], '=') != -1)
				printf("%s\n", env[i]);
			i++;
		}
	}
	else
	{
		g_data.exit_status = EXIT_FAILURE;
		return (ft_perror("minishell: env: Too many arguments.", NULL));
	}
	return (EXIT_SUCCESS);
}
