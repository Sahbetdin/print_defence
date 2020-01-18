#include "test_header.h"

int ft_put_si_ba(long num, int k, int l)
{
	ft_put_n_chars(32, k);
	write(1, "-", 1);
	ft_put_n_chars(48, l);
	ft_put_long(num);
	return (1);
}

void ft_put_else(long num, int k, int l, t_s *sp)
{
	ft_put_n_chars(32, k);
	if (sp->sign)
		write(1, "-", 1);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
}

int		ft_put_npl_nsi_ba(long num, int k, int l, t_s *sp)
{
	if (k < 1)
		write(1, " ", 1);
	else
		ft_put_n_chars(32, k);
	ft_put_n_chars(48, l);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	return (1);	
}

int		ft_put_npl_nsi_ze_ba(long num, int k, int l, t_s *sp)
{
	write(1, " ", 1);
	if (k > 0)
		k--;
	if (sp->point)
	{
		ft_put_n_chars(32, k);
		ft_put_n_chars(48, l);
	}
	else
		ft_put_n_chars(48, k);
	if (!(sp->point && num == 0))
		ft_put_long(num);
	return (1);
}

int ft_put_d_with_numb_point(long num, t_s *sp, int dig)
{
	int l;
	int k;

	if (sp->point && num == 0)
		dig = 0;
	l = (sp->decim > dig) ? sp->decim - dig : 0;
	k = (sp->decim > dig) ? sp->numb - sp->decim : sp->numb - dig;
	k -= sp->sign || sp->plus;
	if (k < 0)
		k = 0;

	if (sp->plus && !sp->sign && sp->minus)
		ft_put_d_pl_si_mi(num, k, l, sp);
	else if (sp->plus && !sp->sign && sp->zero)
		ft_put_d_pl_nsi_ze(num, k, l, sp);
	else if (sp->plus && !sp->sign)
		ft_put_d_pl_nsi(num, k, l, sp);
	else if (!sp->plus && !sp->sign && sp->minus && sp->backsp)
		ft_put_d_npl_nsi_mi_ba(num, &k, l, sp); //изменил k
	else if (!sp->plus && !sp->sign && sp->zero && sp->backsp)
		k = k - ft_put_npl_nsi_ze_ba(num, k, l, sp);
	else if (!sp->plus && !sp->sign && sp->minus)
		ft_put_d_npl_nsi_mi(num, k, l, sp);
	else if (!sp->plus && !sp->sign && sp->backsp)
		k = k - ft_put_npl_nsi_ba(num, k, l, sp);
	else if (!sp->plus && !sp->sign && sp->zero)
		ft_put_d_npl_nsi_ze(num, k, l, sp);
	else if (sp->sign && sp->minus)
		ft_put_d_si_mi(num, k, l);
	else if (sp->sign && sp->zero)
		ft_put_si_ze(num, k, l, sp);
	else if (sp->sign && sp->backsp)
		k = k - ft_put_si_ba(num, k, l);
	else
		ft_put_else(num, k, l, sp);
	return (dig + (sp->sign || sp->plus || sp->backsp) + l + k);
}


long ft_cast_num(long num, t_s *sp)
{
	if (sp->s == 'h')
	{
		if (sp->s1 == 'd' || sp->s1 == 'i')
			num = (short)num;
		else if (sp->s1 == 'h' && (sp->s2 == 'd' || sp->s2 == 'i'))
			num = (char)num;
	}
	else if (sp->s == 'l')
	{
		if (sp->s1 == 'd')
			num = (long)num;
	}
	else if (sp->s == 'd' || sp->s == 'i')
		num = (int)num;
	return (num);
}

int ft_put_d(long num, t_s *sp)
{
	int dig;
	int l;
	int k;
	int n;

	num = ft_cast_num(num, sp);
	dig = digits_in_base(num, 10);
	if (num == -2147483648)
		return (ft_put_int_min_with_spec(num, sp));	
	if (num < 0)
	{
		num = -num;
		sp->sign = 1;
	}
	if (sp->numb || sp->point)
		return (ft_put_d_with_numb_point(num, sp, dig));
	else
		return (ft_put_d_withOUT_numb_point(num, sp) + dig);
	return (0);
}
