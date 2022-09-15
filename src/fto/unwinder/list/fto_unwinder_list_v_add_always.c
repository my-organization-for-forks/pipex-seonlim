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

t_err	fto_unwinder_list_v_add_always(
	t_fto_unwinder_list *self,
	void **destination,
	void *value,
	void (*how_to_remove_value)(void *value)
)
{
	t_fto_unwinder_list_node *const	node
		= malloc(sizeof(t_fto_unwinder_list_node));

	*destination = value;
	if (!value || !node)
	{
		how_to_remove_value(value);
		free(node);
		return (true);
	}
	node->next = self->head;
	node->value = value;
	node->how_to_remove_value = how_to_remove_value;
	node->destination = destination;
	node->remove_always = true;
	self->head = node;
	return (false);
}
