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

int		ft_put_x_o(t_ulong num, t_s *sp)
{
	int n;
	int dig;
	int l;
	int k;

	num = ft_cast_num_t_ulong(num, sp);
	dig = (num == 0) ? 1 : ft_dig_from_spec(num, sp);
// printf("dig = %d\n", dig);

	ft_modify_from_hash(num, sp);
	if (sp->point == 0)
		sp->decim = 0;
	// print_sp(sp);
	if (sp->point && sp->decim == 0 && num == 0)
		dig = 0;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
// printf("sp->hash = %d\n", sp->hash);
// printf("l = %d, k = %d, dig = %d\n", l, k, dig);

	if (num == 0 && l == 0 && sp->hash && sp->point && sp->s == 'o')
		l = 1;
	else if (l == 0 && sp->hash && sp->s == 'o')
		l = 1;

	k = sp->numb - dig - l;
	if (k < 0)
		k = 0;
// printf("l = %d, k = %d, dig = %d\n", l, k, dig);

	ft_put_x_o_mi_nmi(num, sp, k, l);
	n = dig + k + l;
	// print_sp(sp);
// printf("n = %d\n", n);

	if (sp->s != 'o' && (sp->s == 'x' && num != 0))
		n += sp->hash;
// printf("n = %d\n", n);

// printf("n = %d\n", n);
// 	print_sp(sp);
// 	if (sp->point)
// 	{
// 		if (num == 0)
// 			dig = 0;
// 		l = ft_put_x_o_fet_l(sp, dig);
// // printf("l = %d\n", l);
		
// 		if (l == 0 && sp->hash == 1)
// 		{
// 			sp->hash = 0;
// 			l = 1;
// 		}
// 		k = ft_x_o_point_get_k(sp, dig, l);
// printf("k = %d\n", k);
// 		n = ft_put_x_o_mi_nmi(num, sp, k, l);
// 		return (n + k + l);
// 	}
// 	else
// 		n = ft_put_x_o_npo(num, sp, dig);
	return (n + (sp->hash && num != 0));
}

void	ft_modify_from_hash(t_ulong num, t_s *sp)
{
	if (sp->hash)
	{
		if (sp->s == 'x' || sp->s == 'X' ||
		(sp->s == 'h' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'l' && (sp->s1 == 'x' || sp->s1 == 'X')) ||
		(sp->s == 'l' && sp->s1 == 'l' && (sp->s2 == 'x' || sp->s2 == 'X')) ||
		(sp->s == 'h' && sp->s1 == 'h' && (sp->s2 == 'x' || sp->s2 == 'X')))
			sp->hash = 2;
		// if (num == 0 && (!sp->point || sp->hash == 2))
		// 	sp->hash = 0;
	}
}
