/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 23:49:10 by dcyprien          #+#    #+#             */
/*   Updated: 2022/05/06 23:53:19 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_expansion(char *var, t_list *list, int i)
{
	var = cat_expansion(list->prems->cmd[i], list);
	if (char_in_quote(list->prems->cmd[i], '$', 0) != DOUBLE_QUOTE)
		var = skip_spaces(var);
	secure_free((void **)&list->prems->cmd[i]);
	list->prems->cmd[i] = ft_strdup(var);
	i = check_null_cmd(list->prems, i);
	secure_free((void **)&var);
	return (i);
}