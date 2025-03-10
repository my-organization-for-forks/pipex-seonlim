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

#include "ms_builtin.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/_types/_size_t.h>
#include <unistd.h>

#include "ft_types.h"
#include "ft_cstring.h"
#include "ft_io.h"
#include "ms_execute.h"
#include "wrap.h"

static	t_err	print(char *message, int fd)
{
	if (ft_puts(fd, message))
	{
		perror("minishell echo");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return (true);
	}
	return (false);
}

void	ms_builtin_echo(char **args, int fd)
{
	size_t	index;
	bool	no_enter;

	ms_execute_globals()->exit_status = EXIT_SUCCESS;
	no_enter = false;
	index = 1;
	while (args[index])
	{
		if (index == 1 && ft_cstring_equals(args[index], "-n"))
			no_enter = true;
		else
		{
			if (print(args[index], fd))
				return ;
			if (args[index + 1] != NULL)
			{
				if (print(" ", fd))
					return ;
			}
		}
		++index;
	}
	if (!no_enter)
		if (print("\n", fd))
			return ;
}
