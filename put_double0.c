/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 13:30:56 by btrifle           #+#    #+#             */
/*   Updated: 2020/01/24 13:30:58 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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