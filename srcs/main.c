/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:48:56 by dcyprien          #+#    #+#             */
/*   Updated: 2022/05/06 00:15:12 by dcyprien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_exit_code;

int	main(int ac, char **av, char **envp)
{
	char				*prompt;
	int					std_copy[2];
	t_list				*list;

	(void)av;
	std_copy[0] = dup(0);
	std_copy[1] = dup(STDOUT_FILENO);
	if (ac != 1)
	{
		ft_putstr_fd("Error: too many arguments\n", 1);
		exit(0);
	}
	list = init(envp);
	while (42)
	{
		printf("eof = %d\n", EOF);
		set_sigaction(0);
		prompt = readline("Mimi_shell>> ");
		if (ft_strlen(prompt) > 0)
			add_history(prompt);
		list->prems = parsing(prompt, list);
		run_shell(list);
		ft_free_data(list);
		secure_free((void **)&prompt);
		dup2(std_copy[0], STDIN_FILENO);
		close(std_copy[0]);
	}
	ft_free_list(list);
	rl_clear_history();
	return (g_exit_code);
}
