/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:57 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 16:16:01 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "command.h"
# include <fcntl.h>

typedef struct	s_data
{
	int		pivot;
	int		pivot2;
	int		count;
	int		count2;
	int		i;
	char	check;
	char	check2;
}				t_data;

int				setting_program(t_elem **stack_a, int argc, char **argv);
void			sort_target(t_elem **s1, t_elem **s2, int leng, char flag);
void			move_target(t_elem **s1, t_elem **s2, int leng, char flag);
void			reverse_sort(t_elem **s1, t_elem **s2, int *leng);
char			check_start(t_elem **s1, t_elem **s2, int *leng);
char			check_end(t_elem **s, int *leng, char *flag);
char			move_end(t_elem **s1, t_elem **s2, int *leng, char *flag);

void			find_low_start(t_elem **s1, t_elem **s2, t_data *data
, char flag);
int				find_pivot(t_elem *s, int leng, char dir);
void			set_dir(t_elem **s, char dir);
void			init_data(t_data *data, int pivot);

void			error_message(void);

#endif
