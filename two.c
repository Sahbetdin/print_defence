/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 21:43:21 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/18 21:43:23 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_header.h"

uint	*raise_to_power_2(uint *s)
{
	int		i;
	int		carry;

	carry = 0;
	i = 1;
	while (i <= s[0])
	{
		carry += s[i] * 2;
		s[i] = carry % 10;
		carry /= 10;
		i++;
	}
	return (s);
}

uint	*power_of_2(uint pow, int n)
{
	uint	*s;
	uint	carry;
	int		p;
	int		i;

	if (!(s = (uint *)malloc(sizeof(uint) * (n + 1))))
		return (NULL);
	s[0] = n;
	s[1] = 1;
	i = 1;
	while (++i <= n)
		s[i] = 0;
	p = -1;
	while (++p < pow)
		raise_to_power_2(s);
	return (s);
}

int		ft_divide_by_2_i(uint *s)
{
	int		i;

	i = s[0];
	while (i && s[i] == 0)
		i--;
	return (i);
}

uint	*divide_by_2(uint *s)
{
	int		i;
	int		carry;

	i = ft_divide_by_2_i(s);
	while (i > 0)
	{
		if (s[i] >= 2)
		{
			carry = s[i] % 2;
			s[i] /= 2;
			if (carry != 0)
			{
				s[i - 1] += carry * 10;
				carry = 0;
			}
		}
		else
		{
			s[i - 1] += 10 * s[i];
			s[i] = 0;
		}
		i--;
	}
	return (s);
}

uint	*divide_by_minus_2(uint *s, int n)
{
	int		i;
	char	u;

	i = 1;
	if (!s)
	{
		s = (uint *)malloc(sizeof(int) * (n + 1));
		s[0] = n;
		s[1] = 5;
		while (++i <= n)
			s[i] = 0;
	}
	else
	{
		while (i <= s[0])
		{
			if (s[i] % 2 == 1)
				s[i + 1] += 10;
			s[i] /= 2;
			i++;
		}
	}
	return (s);
}
