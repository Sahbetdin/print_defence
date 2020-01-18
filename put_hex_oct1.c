/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_oct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:12:56 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:12:57 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	ft_put_prelimenaries(long num, t_s *sp)
{
	if (sp->hash)
	{
		if (sp->hash == 1)
			write(1, "0", 1);
		else if ((sp->s == 'x' ||
			(sp->s == 'h' && sp->s1 == 'x') ||
			(sp->s == 'l' && sp->s1 == 'x') ||
			(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x') ||
			(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'x')) &&
			sp->hash == 2)
			write(1, "0x", 2);
		else if ((sp->s == 'X' ||
			(sp->s == 'h' && sp->s1 == 'X') ||
			(sp->s == 'l' && sp->s1 == 'X') ||
			(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X') ||
			(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'X')) &&
			sp->hash == 2)
			write(1, "0X", 2);
	}
}

int		ft_put_integer_u(ulong u_value, t_s *sp)
{
	int n;

	n = 0;
	if (sp->s == 'u' || (sp->s == 'l' && sp->s1 == 'u') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
	(sp->s == 'h' && sp->s1 == 'u') ||
	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'u'))
		n += ft_itoa_base_unsigned(u_value, 10, 0);
	else if (sp->s == 'o' ||
	(sp->s == 'h' && sp->s1 == 'o') || (sp->s == 'l' && sp->s1 == 'o') ||
	(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
	(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o'))
		n += ft_itoa_base_unsigned(u_value, 8, 0);
	else if (sp->s == 'x' ||
		(sp->s == 'l' && sp->s1 == 'x') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'x') ||
		(sp->s == 'h' && sp->s1 == 'x') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'x'))
		n += ft_itoa_base_unsigned(u_value, 16, 0);
	else if (sp->s == 'X' ||
		(sp->s == 'l' && sp->s1 == 'X') || (sp->s == 'h' && sp->s1 == 'X') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'X') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'X'))
		n += ft_itoa_base_unsigned(u_value, 16, 1);
	return (n);
}

int		ft_dig_from_spec(ulong num, t_s *sp)
{
	int	dig;

	if (sp->s == 'u' || (sp->s == 'l' && sp->s1 == 'u') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'u') ||
		(sp->s == 'h' && sp->s1 == 'u') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'u'))
		dig = digits_in_base_unsigned(num, 10);
	else if (sp->s == 'o' ||
		(sp->s == 'l' && sp->s1 == 'o') ||
		(sp->s == 'l' && sp->s1 == 'l' && sp->s2 == 'o') ||
		(sp->s == 'h' && sp->s1 == 'o') ||
		(sp->s == 'h' && sp->s1 == 'h' && sp->s2 == 'o'))
		dig = digits_in_base_unsigned(num, 8);
	else if (sp->s == 'x' || sp->s == 'X' ||
		((sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X'))) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X'))
		|| (sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X')))
		dig = digits_in_base_unsigned(num, 16);
	return (dig);
}

ulong	ft_cast_num_ulong(ulong num, t_s *sp)
{
	if (sp->s == 'u' || sp->s == 'o' ||
		sp->s == 'x' || sp->s == 'X')
		num = (uint)num;
	else if (sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X'))
		num = (unsigned short)num;
	else if (sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' ||
	sp->s2 == 'X' || sp->s2 == 'o' || sp->s2 == 'u'))
		num = (unsigned char)num;
	else if (sp->s == 'h' && (sp->s1 == 'o' || sp->s1 == 'u'))
		num = (unsigned short)num;
	return (num);
}
