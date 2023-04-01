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

#include "ft_stringbuilder.h"
#include "ms.h"
#include "ms_expand.h"

t_err	ms_expand_string_list_list_builder_feed_string(
	t_ms_expand_string_list_list_builder *self,
	const char *str,
	t_ms_word_part_type type
)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ms_expand_string_list_list_builder_feed_char(
				self, str[i], type))
			return (true);
		if (str[i] == '*' && str[i + 1] == '\0')
		{
			if (self->builder == NULL)
				self->builder = new_stringbuilder(STRING_BUILDER_SIZE);
			if (self->builder == NULL)
				return (true);
			if (ms_expand_string_list_list_builder_add_list_node(
					&self->list.tail->list)
				|| ms_expand_string_list_list_builder_fill_node(
					&self->builder, &self->list.tail->list))
				return (true);
		}
		i++;
	}
	return (false);
}
