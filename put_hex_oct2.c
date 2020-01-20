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

int		ft_put_x_o_npo_nmi(t_ulong num, t_s *sp, int k)
{
	int n;

	n = 0;
	if (sp->zero)
	{
		ft_put_prelimenaries(sp);
		ft_put_n_chars(48, k);
	}
	else
	{
		ft_put_n_chars(32, k);
		ft_put_prelimenaries(sp);
	}
	n = ft_put_integer_u(num, sp);
	return (n);
}

int		ft_put_x_o_npo(t_ulong num, t_s *sp, int dig)
{
	int k;
	int n;

	k = (sp->numb > dig) ? sp->numb - dig : 0;
	k -= sp->hash;
	if (k < 0)
		k = 0;
	if (sp->minus)
	{
		ft_put_prelimenaries(sp);
		n = ft_put_integer_u(num, sp);
		ft_put_n_chars(32, k);
	}
	else
		n = ft_put_x_o_npo_nmi(num, sp, k);
	return (n + k);
}

int		ft_put_x_o_mi_nmi(t_ulong num, t_s *sp, int k, int l)
{
	int	n;
// printf("l = %d\n", l);
	n = 0;
	if (sp->minus)
	{
		if (sp->s != 'o')
			ft_put_prelimenaries(sp);
		ft_put_n_chars(48, l);
		// if (num != 0)
			n = ft_put_integer_u(num, sp);
		if (sp->hash)
			ft_put_n_chars(48, k);
		else
			ft_put_n_chars(32, k);
	}
	else
	{

		// if (sp->hash)
		// 	ft_put_n_chars(48, k);
		// else
			ft_put_n_chars(32, k);
		// ft_put_n_chars(32, k);

		if (sp->s != 'o' && (sp->s == 'x' && num != 0))
			ft_put_prelimenaries(sp);
		ft_put_n_chars(48, l);
	//printf("l = %d\n", l);

	if (!(num == 0 && sp->decim == 0 && sp->point))
		// if (num != 0)
			n = ft_put_integer_u(num, sp);
	}
	// printf("n = %d\n", n);
	return (n);
}

int		ft_x_o_point_get_k(t_s *sp, int dig, int l)
{
	int k;

	k = (sp->numb > sp->decim) ? sp->numb : sp->decim;
	k -= dig + l; // + sp->hash;
	if (k < 0)
		k = 0;
	return (k);
}

int		ft_put_x_o_fet_l(t_s *sp, int dig)
{
	int l;

	l = (sp->decim > dig) ? sp->decim - dig : 0;
	if (l >= 2 && sp->hash == 1 && sp->s != 'o')
		l--;
	return (l);
}
