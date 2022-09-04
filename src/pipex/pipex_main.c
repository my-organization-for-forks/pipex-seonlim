/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 08:48:49 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/05 00:56:34 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "pipex.h"

#include <stdlib.h>
#include <unistd.h>

#include "ft_cstring_split.h"
#include "ft_os_util_envp.h"

int	main(int argc, char **argv)
{
	t_pipex *const		pipex = pipex_new(argc - 1, argv + 1);
	const char *const	env_path = ft_os_util_envp_get(environ, "PATH");

	if (!pipex || !env_path)
		return (EXIT_FAILURE);
	pipex_free(pipex);
	return (0);
}
