/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex_oct3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 20:13:05 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 20:13:07 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

int		ft_put_x_o(ulong num, t_s *sp)
{
	int n;
	int dig;
	int l;
	int k;

	num = ft_cast_num_ulong(num, sp);
	dig = ft_dig_from_spec(num, sp);
	ft_modify_from_hash(num, sp);
	n = 0;
	if (sp->point)
	{
		if (num == 0)
			dig = 0;
		l = ft_put_x_o_fet_l(sp, dig);
		if (l == 0 && sp->hash == 1)
		{
			sp->hash = 0;
			l = 1;
		}
		k = ft_x_o_point_get_k(sp, dig, l);
		n = ft_put_x_o_mi_nmi(num, sp, k, l);
	}
	else
		n = ft_put_x_o_npo(num, sp, dig);
	return (n + k + l + sp->hash);
}

void	ft_modify_from_hash(ulong num, t_s *sp)
{
	if (sp->hash)
	{
		if (sp->s == 'x' || sp->s == 'X' ||
		(sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X')))
			sp->hash = 2;
		if (num == 0 && (!sp->point || sp->hash == 2))
			sp->hash = 0;
	}
}
