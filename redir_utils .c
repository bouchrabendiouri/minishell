/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbendiou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:36:56 by bbendiou          #+#    #+#             */
/*   Updated: 2023/08/23 17:37:33 by bbendiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_redir_list	*init_redir_list(t_redir_list *list)
{
	list = ft_calloc(sizeof(t_redir_list), 1);
	if (!list)
		return (NULL);
	return (list);
}

t_redir_elem	*new_redir_elem(char *arg, enum e_token type)
{
	t_redir_elem	*elem;

	elem = ft_calloc(sizeof(t_redir_elem), 1);
	if (!elem)
		return (NULL);
	elem->arg = arg;
	elem->type = type;
	return (elem);
}

void	add_redir_tail(t_redir_list *list, t_redir_elem *new)
{
	if (!list->head)
		list->head = new;
	else
		list->tail->next = new;
	list->tail = new;
	list->size++;
}

void	free_redir_list(t_redir_list *list)
{
	t_redir_elem	*tmp;

	tmp = list->head;
	while (tmp)
	{
		free(tmp->arg);
		free(tmp);
		tmp = tmp->next;
	}
	free(list);
}

void	print_redir_list(t_redir_list *redir)
{
	t_redir_elem	*tmp;

	tmp = redir->head;
	if (tmp)
		printf("REDIR LIST\n");
	while (tmp)
	{
		printf("redir type: %i\n", tmp->type);
		printf("redir arg: %s\n", tmp->arg);
		tmp = tmp->next;
	}
}
