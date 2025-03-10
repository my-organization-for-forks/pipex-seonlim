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

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "ft_io.h"
#include "ms_execute.h"
#include "wrap.h"

void	ms_builtin_pwd(int fd)
{
	char	*path;

	ms_execute_globals()->exit_status = EXIT_SUCCESS;
	path = getcwd(NULL, 0);
	if (path == NULL)
	{
		perror("minishell pwd");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return ;
	}
	if (ft_puts(fd, path))
	{
		perror("minishell pwd");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return ;
	}
	wrap_free(path);
	if (ft_puts(fd, "\n"))
	{
		perror("minishell pwd");
		ms_execute_globals()->exit_status = EXIT_FAILURE;
		return ;
	}
}
