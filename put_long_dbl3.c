#include "test_header.h"

int		ft_put_LONG_double(long double x, t_s *sp)
{
	int			dig;
	int			k;
	int			count;
	u_long_dbl	num;

	if (x < 0)
	{
		sp->sign = 1;
		x = -x;
	}
	num.l_dbl = x;
	if ((k = check_DLNG_inf(&num, sp)))
		return (k);
	if (sp->s1 == 'e' || sp->s1 == 'E')
		return (ft_put_whole_sci_LDBL(x, sp));
	dig = ft_dig_LDBL(x);
	count = dig + ft_get_k_for_LDBL(sp, dig) + (sp->plus || sp->sign);
	if (sp->decim > 0)
		count += sp->decim + 1;
	ft_put_from_specif_LDBL(&num, sp, k);	
	return (count);
}
