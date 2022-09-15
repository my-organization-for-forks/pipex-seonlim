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

#ifndef FT_TYPES_PRIMITIVE_INT_H
# define FT_TYPES_PRIMITIVE_INT_H

# include <stddef.h>
# include <stdbool.h>

void	ft_types_primitive_int_swap(int *a, int *b);
int		ft_types_primitive_int_min(int a, int b);
int		ft_types_primitive_int_max(int a, int b);
int		ft_types_primitive_int_if(
			bool condition,
			int value_if_true,
			int value_if_false);

#endif
