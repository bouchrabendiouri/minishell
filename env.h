/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nolahmar <nolahmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:41:12 by bbendiou          #+#    #+#             */
/*   Updated: 2023/08/24 14:58:49 by nolahmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

typedef struct s_env_elem
{
	char				*key;
	char				*value;
	struct s_env_elem	*next;
	struct s_env_elem	*prev;
}	t_env_elem;

typedef struct s_env
{
	t_env_elem			*head;
	char				**env;
	int					size;
}	t_env;

t_env		*init_env(t_env *env);
t_env_elem	*new_env_elem(char *line);
void		add_env_elem(t_env *env, t_env_elem *elem);
t_env		*create_env(char **tab);

void		print_env(t_env *env);
char		**convert_array(t_env *env);
void		del_env_elem(t_env *env, t_env_elem *elem);
void		del_env(t_env *env);
void		print_env_arr(char **env);

char		*get_env_value(char *key, t_env *env);
t_env_elem	*search_env_elem(t_env *env, char *key);
char		*search_env_var(char *key, char **env);
char		*expand_env(char *line, char **env);
char		*get_expanded_value(char **line, char **env);

void		print_env_arr(char **env);

#endif
