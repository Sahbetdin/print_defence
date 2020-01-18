/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_oct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:13:01 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:13:02 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int		ft_put_x_o_npo_nmi(ulong num, t_s *sp, int k)
{
	int n;

	n = 0;
	if (sp->zero)
	{
		ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_prelimenaries(num, sp);
	}
	n = ft_put_integer_u(num, sp);
	return (n);
}

int		ft_put_x_o_npo(ulong num, t_s *sp, int dig)
{
	int k;
	int n;

	k = (sp->numb > dig) ? sp->numb - dig : 0;
	k -= sp->hash;
	if (k < 0)
		k = 0;
	if (sp->minus)
	{
		ft_put_prelimenaries(num, sp);
		n = ft_put_integer_u(num, sp);
		ft_put_n_chars(32, k);
	}
	else
		n = ft_put_x_o_npo_nmi(num, sp, k);
	return (n);
}

int		ft_put_x_o_mi_nmi(ulong num, t_s *sp, int k, int l)
{
	int n;

	if (sp->minus)
	{
		ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
		if (num != 0)
			n = ft_put_integer_u(num, sp);
		ft_put_n_chars(32, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_prelimenaries(num, sp);
		ft_put_n_chars(48, l);
		if (num != 0)
			n = ft_put_integer_u(num, sp);
	}
	return (n);
}

int		ft_x_o_point_get_k(t_s *sp, int dig, int l)
{
	int k;

	k = (sp->numb > sp->decim) ? sp->numb : sp->decim;
	k -= dig + l + sp->hash;
	if (k < 0)
		k = 0;
	return (k);
}

int		ft_put_x_o_fet_l(t_s *sp, int dig)
{
	int l;

	l = (sp->decim > dig) ? sp->decim - dig : 0;
	if (l > 2 && sp->hash == 1)
		l--;
	return (l);
}
