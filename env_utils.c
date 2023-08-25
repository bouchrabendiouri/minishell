/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:12:09 by nolahmar          #+#    #+#             */
/*   Updated: 2023/08/24 10:51:58 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(t_env *env)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
}

void	del_env_elem(t_env *env, t_env_elem *elem)
{
	if (elem && elem->next)
		elem->next->prev = elem->prev;
	if (elem && elem->prev)
		elem->prev->next = elem->next;
	env->size--;
	free(elem->key);
	free(elem->value);
	free(elem);
	elem = NULL;
}

void	del_env(t_env *env)
{
	t_env_elem	*tmp;

	tmp = env->head;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->value);
		free(tmp);
		tmp = tmp->next;
	}
	free(env);
}

void	print_env_arr(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		printf("%s\n", env[i++]);
}

char	**convert_array(t_env *env)
{
	t_env_elem	*tmp;
	char		**arr;
	int			i;

	i = 0;
	tmp = env->head;
	arr = ft_calloc(env->size + 1, sizeof(char *));
	if (arr)
	{
		while (i < env->size)
		{
			char *key = ft_strdup(tmp->key);
			char *value = tmp->value ? ft_strdup(tmp->value) : NULL;

			if (value)
				key = ft_strjoin(key, "=");

			if (value)
				key = ft_strjoin(key, value);

			arr[i] = key;
			i++;

			tmp = tmp->next;

			// N'oubliez pas de libérer la mémoire allouée pour value
			free(value);
		}
		arr[i] = NULL;
	}
	return (arr);
}
