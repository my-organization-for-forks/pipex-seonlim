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
#include <sys/_types/_pid_t.h>
#include <sys/_types/_ssize_t.h>
#include <sys/fcntl.h>
#include <unistd.h>

#include "ms.h"
#include "ft_os_file.h"
#include "ms_parse.h"
#include "wrap.h"
#include "ft_types.h"
#include "ft_stringbuilder.h"
#include "ft_os_fork.h"

static t_err	read_file(int fd)
{
	char	buf[READ_BUF_SIZE];
	int test_fd = open("log.test", O_WRONLY | O_APPEND | O_CREAT, 644);
	ssize_t	read_size;
	ssize_t	left_size;
	ssize_t	write_size;

	read_size = wrap_read(fd, buf, READ_BUF_SIZE);
	while (read_size)
	{
		if (read_size < 0)
			return (true);
		write_size = wrap_write(STDOUT_FILENO, buf, read_size);
		if (write_size < 0)
			return (true);
		left_size = read_size - write_size;
		while (left_size)
		{
			write_size = wrap_write(STDOUT_FILENO, buf, read_size);
			write(test_fd, buf, read_size); //test only
			if (write_size < 0)
				return (true);
			left_size -= write_size;
		}
		read_size = wrap_read(fd, buf, READ_BUF_SIZE);
	}
	close(test_fd); //test only
	return (false);
}

void	ms_execute_redirecions_in(t_ms_redirection_list *rd_list)
{
	int							fd;
	char						*path;
	t_ms_redirection_list_node	*node;

	node = rd_list->head;
	while (node)
	{
		if (ms_execute_redirections_word_to_str(node->target, &path))
			wrap_exit(EXIT_FAILURE);
		fd = wrap_open(path, O_RDONLY);
		if (fd < 0 || read_file(fd))
			wrap_exit(EXIT_FAILURE);
		wrap_free(path);
		node = node->next;
	}
	wrap_exit(EXIT_SUCCESS);
}
