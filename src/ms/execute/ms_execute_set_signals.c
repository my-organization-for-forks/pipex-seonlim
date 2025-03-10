/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fake_file_name (file name is useless too)          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: 42header-remover <whatever@example.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 00:00:00 by VCS handles       #+#    #+#             */
/*   Updated: 1970/01/01 00:00:00 by file history     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ms_execute.h"

#include <stdlib.h>
#include <signal.h>
#include <sys/_types/_pid_t.h>
#include <sys/signal.h>

#include "ft_io.h"
#include "wrap.h"

static void	parent_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	if (ft_puts(STDOUT_FILENO, "\n"))
		ms_execute_exit(EXIT_FAILURE, "minishell sigint");
}

static void	parent_sigquit_handler(int signo)
{
	if (signo != SIGQUIT)
		return ;
	if (ft_puts(STDOUT_FILENO, "Quit: 3\n"))
		ms_execute_exit(EXIT_FAILURE, "minishell sigquit");
}

void	ms_execute_set_signals(pid_t pid)
{
	if (pid == CHILD_PID)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
		return ;
	}
	signal(SIGINT, parent_sigint_handler);
	signal(SIGQUIT, parent_sigquit_handler);
}
