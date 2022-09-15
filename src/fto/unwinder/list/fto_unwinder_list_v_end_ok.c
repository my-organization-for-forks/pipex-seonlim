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

#include "fto_unwinder_list_v.h"

#include <stdlib.h>

t_err	fto_unwinder_list_v_end_ok(
	t_fto_unwinder_list *self
)
{
	t_fto_unwinder_list_node	*tmp;

	while (self->head)
	{
		tmp = self->head;
		self->head = tmp->next;
		if (tmp->remove_always)
		{
			if (tmp->value == *tmp->destination)
				*tmp->destination = NULL;
			tmp->how_to_remove_value(tmp->value);
		}
		free(tmp);
	}
	return (false);
}
