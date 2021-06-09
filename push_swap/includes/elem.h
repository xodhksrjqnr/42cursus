/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:54 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 13:38:55 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEM_H
# define ELEM_H

# include <stdlib.h>

typedef struct	s_elem
{
	int				value;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

t_elem			*new_elem(int num);
t_elem			*sub_elem(t_elem **stack);
void			add_elem(t_elem **stack, t_elem **new_elem);

#endif
