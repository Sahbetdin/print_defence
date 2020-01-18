/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:28:01 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 18:28:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

uint	*add_arithmetics(uint *a, uint *b)
{
	int		i;

	i = 1;
	while (i < a[0])
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		i++;
	}
	return (a);
}

uint	*set_arithmetic_zeros(int n)
{
	uint	*s;
	int		i;

	s = (uint *)malloc(sizeof(uint) * (n + 1));
	s[0] = n;
	i = 0;
	while (++i <= n)
		s[i] = 0;
	return (s);
}

uint	*add_arithmetics_minus(uint *a, uint *b)
{
	int		i;

	i = b[0];
	while (i && b[i] == 0)
		i--;
	while (i > 0)
	{
		a[i] += b[i];
		if (a[i] > 9)
		{
			a[i - 1] += a[i] / 10;
			a[i] %= 10;
		}
		i--;
	}
	return (a);
}
