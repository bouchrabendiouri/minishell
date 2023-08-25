/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:16:18 by nolahmar          #+#    #+#             */
/*   Updated: 2023/08/24 14:58:31 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_data(t_data *data)
{
	data->exit_status = 0;
	data->which = 0;
	data->pid = 0;
	data->tree = NULL;
	data->ev = NULL;
	data->alloc = 0;
}

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1 || !*env)
		return (1);
	create_env(env);
	init_data(&g_data);
	lunch_program(env);
	return (0);
}
