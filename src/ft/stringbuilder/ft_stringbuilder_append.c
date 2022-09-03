/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringbuilder_append.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:59:01 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2022/09/04 07:50:58 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringbuilder.h"

#include <stdlib.h>

#include "ft_memory.h"

static t_stringbuilder_node	*internal(
	t_stringbuilder *self,
	size_t length,
	const char *buffer
)
{
	t_stringbuilder_node	*node;
	size_t					size;

	size = length;
	if (length < self->buffer_size)
		size = self->buffer_size;
	node = (t_stringbuilder_node *)malloc(sizeof(t_stringbuilder_node) + size);
	if (!node)
		return (NULL);
	node->next = NULL;
	node->capacity = size;
	ft_memory_copy(node->str, buffer, length);
	node->length = length;
	if (self->tail)
		self->tail->next = node;
	else
		self->head = node;
	self->tail = node;
	return (node);
}

t_err	stringbuilder_append(
	t_stringbuilder *self,
	size_t len,
	const char *buffer
)
{
	t_stringbuilder_node *const	tail = self->tail;
	size_t						offset;
	t_stringbuilder_node		*new_tail;

	offset = 0;
	if (self->tail)
		offset = self->tail->capacity - self->tail->length;
	if (offset >= len)
	{
		ft_memory_copy(&self->tail->str[self->tail->length], buffer, len);
		self->tail->length += len;
		self->length += len;
		return (false);
	}
	new_tail = internal(self, len - offset, &buffer[offset]);
	if (!new_tail)
		return (true);
	if (offset)
	{
		ft_memory_copy(&tail->str[tail->length], buffer, offset);
		tail->length += offset;
	}
	self->length += len;
	return (false);
}
