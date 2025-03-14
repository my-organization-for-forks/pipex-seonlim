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

#ifndef MS_H
# define MS_H
# define FILE_EXIST 0

# include <stdbool.h>
# include <stddef.h>

# include "ft_types.h"

typedef enum e_ms_word_part_string_type
{
	ms_word_part_string_no_expansion,
	ms_word_part_string_expansion,
}	t_ms_word_part_string_type;

typedef struct s_ms_word_part_string_list_node
{
	struct s_ms_word_part_string_list_node	*next;
	t_ms_word_part_string_type				type;
	char									*value;
}	t_ms_word_part_string_list_node;

typedef struct s_ms_word_part_string_list
{
	t_ms_word_part_string_list_node	*head;
	t_ms_word_part_string_list_node	*tail;
}	t_ms_word_part_string_list;

typedef enum e_ms_word_part_type
{
	ms_word_part_unquoted,
	ms_word_part_single_quoted,
	ms_word_part_double_quoted,
}	t_ms_word_part_type;

typedef union u_ms_word_part_value
{
	void						*any;
	t_ms_word_part_string_list	*unquoted;
	char						*single_quoted;
	t_ms_word_part_string_list	*double_quoted;
}	t_ms_word_part_value;

typedef struct s_ms_word_part_list_node
{
	struct s_ms_word_part_list_node	*next;
	t_ms_word_part_type				type;
	t_ms_word_part_value			value;
}	t_ms_word_part_list_node;

typedef struct s_ms_word_part_list
{
	t_ms_word_part_list_node	*head;
	t_ms_word_part_list_node	*tail;
}	t_ms_word_part_list;

typedef struct s_ms_word
{
	t_ms_word_part_list	part_list;
}	t_ms_word;

typedef struct s_ms_word_list_node
{
	struct s_ms_word_list_node	*next;
	t_ms_word					*word;
}	t_ms_word_list_node;

typedef struct s_ms_word_list
{
	t_ms_word_list_node	*head;
	t_ms_word_list_node	*tail;
}	t_ms_word_list;

typedef struct s_ms_redirection_list_node
{
	struct s_ms_redirection_list_node	*next;
	bool								is_special;
	t_ms_word							*target;
}	t_ms_redirection_list_node;

typedef struct s_ms_redirection_list
{
	t_ms_redirection_list_node	*head;
	t_ms_redirection_list_node	*tail;
}	t_ms_redirection_list;

typedef struct s_ms_redirections
{
	t_ms_redirection_list	in;
	t_ms_redirection_list	out;
}	t_ms_redirections;

typedef struct s_ms_command_simple
{
	t_ms_word_list		word_list;
	t_ms_redirections	redirections;
}	t_ms_command_simple;

typedef struct s_ms_pipe_list
{
	struct s_ms_pipe_list_node	*head;
	struct s_ms_pipe_list_node	*tail;
}	t_ms_pipe_list;

typedef struct s_ms_and_or_list_node
{
	struct s_ms_and_or_list_node	*next;
	bool							is_and;
	t_ms_pipe_list					pipe_list;
}	t_ms_and_or_list_node;

typedef struct s_ms_and_or_list
{
	t_ms_and_or_list_node	*head;
	t_ms_and_or_list_node	*tail;
}	t_ms_and_or_list;

typedef struct s_ms_command_compound
{
	t_ms_and_or_list	and_or_list;
	t_ms_redirections	redirections;
}	t_ms_command_compound;

typedef enum e_ms_command_type
{
	ms_command_type_invalid,
	ms_command_type_simple,
	ms_command_type_compound,
}	t_ms_command_type;

typedef union u_ms_command_value
{
	void					*any;
	t_ms_command_simple		*simple;
	t_ms_command_compound	*compound;
}	t_ms_command_value;

typedef struct s_ms_command
{
	t_ms_command_type	type;
	t_ms_command_value	value;
}	t_ms_command;

typedef struct s_ms_pipe_list_node
{
	struct s_ms_pipe_list_node	*next;
	t_ms_command				command;
}	t_ms_pipe_list_node;

typedef struct s_ms_program
{
	t_ms_and_or_list	and_or_list;
}	t_ms_program;

t_err	ms_tmpname_find(char **out);
t_err	ms_tmpname_init(void);
t_err	ms_parse(const char *source, t_ms_program **out);
void	ms_free(t_ms_program *program);
t_err	ms_execute(t_ms_program *program);

#endif
