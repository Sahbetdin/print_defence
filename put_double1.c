/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:15:33 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 19:15:37 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

void	normalize(t_uint *a, t_uint *s, int i)
{
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 0)
		{
			s[i] -= 10;
			s[i - 1] += 1;
			i--;
		}
		if (i == 0)
		{
			a[1]++;
			i = 1;
			while (a[i] > 9)
			{
				a[i] -= 10;
				a[i + 1]++;
				i++;
			}
		}
	}
}

t_long	*create_long_whole_pre(t_double *num_union_f)
{
	t_long		*lng;
	t_uint		exp;
	int			n;

	lng = (t_long *)malloc(sizeof(t_long));
	lng->whole = NULL;
	lng->flag = 1UL << 51;
	if (num_union_f->parts.exponent >= 1023)
	{
		exp = num_union_f->parts.exponent - 1023;
		n = 0.30103 * exp + 3;
		lng->whole = power_of_2(exp, n);
	}
	else
	{
		exp = 1023 - num_union_f->parts.exponent;
		if (!(lng->whole = (t_uint *)malloc(sizeof(t_uint) * 2)))
			return (0);
		lng->whole[0] = 1;
		lng->whole[1] = 0;
	}
	return (lng);
}

t_long	*create_long_whole(t_double *num_union_f)
{
	t_long	*lng;
	t_uint	*b;
	t_uint	exp;
	int		n;

	lng = create_long_whole_pre(num_union_f);
	b = NULL;
	if (num_union_f->parts.exponent >= 1023)
	{
		exp = num_union_f->parts.exponent - 1023;
		n = 0.30103 * exp + 3;
		b = power_of_2(exp, n);
		while (exp > 0)
		{
			divide_by_2(b);
			if (lng->flag & num_union_f->parts.mantissa)
				add_arithmetics(lng->whole, b);
			lng->flag = lng->flag >> 1;
			exp--;
		}
		free(b);
		b = NULL;
	}
	return (lng);
}

t_uint	*ft_temp_b_floats(t_double *num_union_f, t_uint n)
{
	t_uint		exp;
	t_uint		*b;

	b = NULL;
	if (num_union_f->parts.exponent < 1023)
	{
		exp = 1023 - num_union_f->parts.exponent;
		b = divide_by_minus_2(NULL, n);
		while (exp > 1)
		{
			divide_by_minus_2(b, n);
			exp--;
		}
	}
	else
		b = divide_by_minus_2(NULL, n);
	return (b);
}

t_long	*create_long(double x, int d)
{
	t_long		*lng;
	t_double	num;
	t_uint		*b;
	t_uint		n;

	num.dbl = x;
	if (!(lng = create_long_whole(&num)))
		return (NULL);
	n = ft_create_n_temp(num.parts.exponent, d, 1023);
	lng->decimal = set_arithmetic_zeros(n);
	b = ft_temp_b_floats(&num, n);
	if (num.parts.exponent < 1023)
	{
		add_arithmetics_minus(lng->decimal, b);
		divide_by_minus_2(b, n);
	}
	while (lng->flag)
	{
		if (lng->flag & num.parts.mantissa)
			add_arithmetics_minus(lng->decimal, b);
		divide_by_minus_2(b, n);
		lng->flag = lng->flag >> 1;
	}
	free(b);
	return (lng);
}
