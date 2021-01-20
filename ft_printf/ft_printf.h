/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:57 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 18:06:57 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	char		type;
	char		minus;
	char		zero;
	char		dot;
	char		flag;
	int			first;
	int			second;
}				t_flags;
int				ft_printf(const char *s, ...);
int				check_combi(t_flags *cur);
int				print_form(t_flags cur, va_list ap, int *count);
int				print_percent(t_flags cur, int *count, char *tmp);
int				print_c(t_flags cur, char c, int *count, char *tmp);
int				print_sp(t_flags cur, char *s, int *count, char *tmp);
int				print_num(t_flags cur, int n, int *count, char *tmp);

#endif
