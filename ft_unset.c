/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:13:34 by nolahmar          #+#    #+#             */
/*   Updated: 2023/08/24 11:20:24 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_isdigit(char c)
{
	return (c >= 0 && c <= 9);
}

void	unset_env(char *args, t_env *env)
{
	t_env_elem	*elem;

	elem = NULL;
	if (args && !ft_isalpha(args[0]))
	{
		printf("minishell: unset: `%s`: not a valid identifier\n",
			args);
		g_data.exit_status = EXIT_FAILURE;
	}
	else
	{
		elem = search_env_elem(env, args);
		if (elem)
			del_env_elem(env, elem);
	}
}

int	ft_unset(t_cmd *cmd, char ***ev)
{
	t_env	*env;
	int		i;

	i = 1;
	env = NULL;
	env = create_env(*ev);
	g_data.exit_status = EXIT_SUCCESS;
	while (cmd->args[i])
	{
		unset_env(cmd->args[i], env);
		i++;
	}
	*ev = convert_array(env);
	del_env(env);
	return (g_data.exit_status);
}
