/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:12:17 by nolahmar          #+#    #+#             */
/*   Updated: 2023/08/23 10:12:19 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data						g_data;

void	ft_plus(int *i, int plus)
{
	if (!plus)
		(*i)++;
	else
		(*i) += plus;
}

void	check_cmd_state(t_elem**ptr, char **env, int *value)
{
	if ((*ptr)->state == GENERAL)
	{
		(*value)++;
		if ((*ptr)->type == ENV)
		{
			if (ft_strcmp(expand_env((*ptr)->content, env), "") == EQUAL)
				(*value)--;
		}
	}
	else
	{
		while ((*ptr) && (*ptr)->state != GENERAL)
			(*ptr) = (*ptr)->next;
		(*value)++;
	}
}
