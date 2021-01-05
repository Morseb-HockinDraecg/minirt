/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smorel <smorel@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:10:27 by smorel            #+#    #+#             */
/*   Updated: 2020/12/26 13:51:51 by smorel           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct	s_conversion
{
	char	flag[5];
	int		width;
	int		precision;
	int		preci_nul;
	char	length[2];
	char	specifier;
	int		*len_p;
}				t_conversion;

void			ft_bonus_testing(char spec, va_list params_info,\
				t_conversion current_c);

void			ft_rea_print(char c, char *str, t_conversion current_c);
int				ft_printf(const char *f,\
					...) __attribute__((format(printf,1,2)));

int				ft_isflag(int c);
int				ft_iswidth(int c);
int				ft_islenght(int c);
int				ft_isspecifier(int c);
void			ft_filler(int c, long long int len, t_conversion current_c);

void			ft_conversion(char **tmp, va_list param_info,\
				t_conversion current_c);
int				ft_fill_value(t_conversion current_c);
void			ft_printf_specifier(char spec, va_list params_info,\
				t_conversion current_c);

void			ft_printf_string(char *string, t_conversion current_c);
void			ft_str_flag_tiret(t_conversion current_c, char *string);
void			ft_str_flag_zero(t_conversion current_c, char *string);
void			ft_str_no_flag(char *string, t_conversion current_c);
void			ft_str_malloc_arg(va_list params_info, t_conversion current_c);

void			ft_printf_char(unsigned long int param_int,\
				t_conversion current_c);
void			ft_char_no_flag(unsigned long int p, t_conversion current_c);
void			ft_char_flag_tiret(t_conversion current_c, unsigned long int p);
void			ft_char_flag_zero(t_conversion current_c, unsigned long int p);

void			ft_printf_int(unsigned long int param_int,\
				t_conversion current_c, char spec);
void			ft_int_no_flag(t_conversion current_c, char **tmp);
void			ft_int_flag_tiret(t_conversion current_c, char **tmp);
void			ft_int_flag_zero(t_conversion current_c, char **tmp);

void			ft_printf_address(unsigned long int param_int,\
				t_conversion current_c);
void			ft_adrs_flag_tiret(t_conversion current_c, char **tmp);
void			ft_adrs_flag_zero(t_conversion current_c, char **tmp);
void			ft_adrs_no_flag(t_conversion current_c, char **tmp);

long long int	ft_choosen_length(va_list params_info, char spec,\
				t_conversion current_c);
long long int	ft_modif_h(va_list params_info, char spec);
long long int	ft_modif_hh(va_list params_info, char spec);
long long int	ft_modif_l(va_list params_info, char spec);
long long int	ft_modif_ll(va_list params_info, char spec);
long long int	ft_modif_none(va_list params_info, char spec);

void			ft_printf_diez(t_conversion current_c, int spec);
char			*ft_dec_to_hex(unsigned long int dec, char cap_lower_zero,\
				t_conversion current_c);

#endif
