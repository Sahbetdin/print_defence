#include "test_header.h"

int		ft_put_LONG_only(u_long_dbl *num_DBL, t_s *sp)
{
	double		log2;
	int			count;
	int			dig;
	t_long		*lng2;

	count = 0;
	lng2 = ft_create_LONG_whole(num_DBL);
	ft_create_LONG_decimal(lng2, num_DBL, sp->decim);
	dig = (sp->point > 0) ? sp->decim : 6;
	normalize(lng2->whole, lng2->decimal, sp->decim);
	count += print_double_whole_part(lng2->whole);
	if (!sp->hash && sp->decim == 0)
	{
		free_long_arithm(lng2);
		return (count); 
	}	
	write(1, ".", 1);
	count++;
	print_double_decimal_part(lng2->decimal, sp->decim);
	count += sp->decim;
	free_long_arithm(lng2);
	return (count);
}

int ft_dig_LDBL(long double a)
{
	int			i;

	if (a < 1)
		return (1);
	i = 0;
	while (a >= 1)
	{
		a /= 10;
		i++;
	}
	return (i);
}

void	ft_put_from_specif_LDBL_minus(u_long_dbl *num_DBL, t_s *sp, int k)
{
	ft_put_sign(sp);
	ft_put_LONG_only(num_DBL, sp);
	ft_put_n_chars(32, k);	
}

void	ft_put_from_specif_LDBL(u_long_dbl *num_DBL, t_s *sp, int k)
{
	if (sp->minus)
		ft_put_from_specif_LDBL_minus(num_DBL, sp, k);		
	else
	{
		if (sp->zero && sp->backsp && !sp->plus && !sp->sign)
		{
			write(1, " ", 1);
			ft_put_n_chars(48, k - 1);
			ft_put_LONG_only(num_DBL, sp);
		}
		else if (sp->zero)
		{		
			ft_put_sign(sp);
			ft_put_n_chars(48, k);
			ft_put_LONG_only(num_DBL, sp);
		}
		else
		{
			ft_put_sign(sp);
			ft_put_LONG_only(num_DBL, sp);
		}
	}
}

int		ft_get_k_for_LDBL(t_s *sp, int dig)
{
	int			k;

	k = (sp->numb > dig) ? sp->numb - dig : 0;
	if (sp->decim > 0)
		k -= sp->decim + 1;
	k -= (sp->plus || sp->sign);
	if (k < 0)
		k = 0;
	if (k == 0 && sp->backsp && !sp->sign)
		k = 1;
	return (k);
}
