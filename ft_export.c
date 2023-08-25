/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:13:19 by nolahmar          #+#    #+#             */
/*   Updated: 2023/08/24 15:18:46 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_elem *get_key(t_env_elem *head, char *key)
{
	t_env_elem *tmp;

	tmp = head;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			return (tmp);
		tmp = tmp->next;
	}
	return NULL;
}

void handle_env(t_env *env, t_cmd *cmd, t_elem *head) {
	char *key;
	char *value;
	t_env_elem *env_elem;
    int i = 1;
	int index;

    while (cmd->args[i]) {
		index = ft_strchr(cmd->args[i], '=');
		if (index == -1)
		{
			++i;
			continue;
		}
		key = ft_substr(cmd->args[i], 0, index);
		value = ft_substr(cmd->args[i], index + 1, ft_strlen(cmd->args[i]) - index);
		/* step 2*/
		env_elem = get_key(head, key);
		if (env_elem)
		{
			free(key);
			env_elem->value = value;
		}
		else
			add_env_elem(head, new_env_elem(cmd->args[i]));
    }
}

int	ft_export(char ***ev, t_cmd *cmd, t_elem *head)
{
	// t_env	*env;

	// env = NULL;
	// we should not create the env list again in each call
	// env = create_env(*ev);
	// check for cmd->args to avoid segfault
	if (!cmd->args)
		print_sorted_env(env);
	else
	{
		// '_' is a special case
		if (!ft_isalpha(cmd->args[1][0]))
			return (ft_puterr(cmd->args[0],
					cmd->args[1], "not a valid identifier", EXIT_FAILURE));
		handle_env(env, cmd, head);
	}
	g_data.exit_status = EXIT_SUCCESS;
	return (EXIT_SUCCESS);

}
