/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:09:28 by jyriarte          #+#    #+#             */
/*   Updated: 2025/01/15 14:22:07 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# define BASE_DECIMAL "0123456789"
# define BASE_HEX_LOWER "0123456789abcdef"
# define BASE_HEX_UPPER "0123456789ABCDEF"
# define FORMAT_FLAGS " -+#0"
# define FORMAT_SPECIFIERS "cspdiuxX%"
# define FLAGS_SIZE 7

typedef struct s_format
{
	char	flags[FLAGS_SIZE];
	int		width;
	int		precision;
}			t_format;

int			ft_printf(const char *str, ...);
void		print_format(const char *str, int *index, va_list args, int *count);
void		print_specifier(int c, va_list args, int *count, t_format *format);
int			parse_format(const char *str, int *index, t_format *curr_format);
void		reset_format(t_format *format);
void		print_front_padding(int len, int *count, t_format *format);
void		print_middle_padding(int len, int *count, t_format *format);
void		print_back_padding(int len, int *count, t_format *format);
void		ft_putlchar(int c, int *count, t_format *format);
void		ft_putlstr(char *str, int *count, t_format *format);
void		ft_putlmem(void *mem, int *count, t_format *format);
void		ft_putlint(int num, int *count, t_format *format);
void		ft_putluint(unsigned int num, int *count, t_format *format);
void		ft_putlhex(unsigned int num, int is_upper, int *count,
				t_format *format);
void		ft_putlnbr_base(unsigned long long num, char *base, int *count);
void		ft_putlnchar(int c, int num, int *count);
int			ft_nbrlen_base(unsigned long long nbr, char *base);
#endif
